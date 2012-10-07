#include "CanvasDraw.h"
#include "CanvasAssistance.h"
#include <cstdlib>
#include <cmath>
#include <sstream>
#include "Nave.hpp"
#include "naveInstances.hpp"
#include "Input.hpp"
#include "Shoot.hpp"
#include "BasicShoot.hpp"
#include "GuidedShoot.hpp"
#include "Asteroid.hpp"
#include "Matriz.hpp"
#include "Matriz_Functions.hpp"
#include <SCV/Label.h>
#include "EnemyShoot.hpp"
#include <ctime>
#include "CircleShoot.hpp"
#include "ExplosionShoot.hpp"

int const WL = 1280;
int const WA = 800;
time_t labelStart,labelEnd;

static const float M_PI = 3.1415926535897932384626433832795f;

CanvasDraw::CanvasDraw(scv::Label *lifeLabel, scv::Label *pointsLabel, CanvasAssistance *C_A, scv::Label *gameNotes) 
   : scv::Canvas(scv::Point(0, 0),scv::Point(1280, 800)), bg_color(0.f,0.f,0.f) 
{
   _nave = createNave();
   _lifeLabel = lifeLabel;
   _pointsLabel = pointsLabel;
   _gameNotes = gameNotes;
   _lifeLabel->setVisible(false);
   _pointsLabel->setVisible(false);
   _gameNotes->setVisible(false);
   setVisible(false);
   _C_A = C_A;
   _input = new Input();
   //bImage = new scv::Image(scv::Point(0,0), "Resources/Bbackground.jpg");
}

void CanvasDraw::initGame()
{
   points1 = false;
   points2 = false; 
   points3 = false;
   vAsteroids.clear();
   vEnemies.clear();
   vETiros.clear();
   vTiros.clear();
   vAExplosion.clear();
   nAsteroids = 0;
   nEnemies = 0;
   gamePoints = 0;
   _nave->reset();
   _input->reset();
   std::stringstream ssp;
   ssp << (gamePoints);
   _pointsLabel->setString("Score: " + ssp.str());

   std::stringstream sse1;
   sse1 << (_nave->_life);
   _lifeLabel->setString("Life: " + sse1.str());

   shipTime = false;
   asteroidTime = true;
   _lifeLabel->setVisible(true);
   _pointsLabel->setVisible(true);
   _gameNotes->setVisible(true);
   _gameNotes->setString("");
   finish = false;
   setVisible(true);
   GetFocus();
}


void CanvasDraw::setBackground(const scv::Color4f& color) 
{
   bg_color = color;
}

void CanvasDraw::onMouseClick(const scv::MouseEvent& evt)
{

}

void CanvasDraw::onMouseHold (const scv::MouseEvent& evt)
{     

}

void CanvasDraw::onKeyPressed (const scv::KeyEvent &evt){
   if(isVisible()) {
      auto p = _input->keyboard.find(evt.getKeyCode());
      if (p != _input->keyboard.end())
         p->second = true;
   }
}

void CanvasDraw::onKeyUp(const scv::KeyEvent &evt){
   if(isVisible()){
      auto p = _input->keyboard.find(evt.getKeyCode());
      if (p != _input->keyboard.end())
         p->second = false;
   }
}

void CanvasDraw::onMouseOver(const scv::MouseEvent& evt)
{

}

void CanvasDraw::onMouseUp(const scv::MouseEvent& evt)
{

}

void CanvasDraw::update(void) 
{
   if(isVisible()){
      int mSizes;
      ///////////////Keyboard///////////////
      if (_input->keyboard['q']) {
         vAsteroids.clear();
         vEnemies.clear();
         _input->keyboard['q'] = false;
      }
      if(_input->keyboard['z']){
         Matriz<3,1> t = mat.Translate2D(0,0,_nave->_p(0,0),_nave->_p(1,0))*mat.rotation2D(_nave->_angle)*_nave->_vertices[0];
         vTiros.push_back(BasicShoot(_nave,_nave->_direction, t,_nave->_angle));
         _input->keyboard['z'] = false;
      }
      if(_input->keyboard['c'] && points2){
         Matriz<3,1> t = mat.Translate2D(0,0,_nave->_p(0,0),_nave->_p(1,0))*mat.rotation2D(_nave->_angle)*_nave->_vertices[0];
         vTiros.push_back(CircleShoot(_nave,_nave->_direction, t, _nave->_angle));
         _input->keyboard['c'] = false;
      }
      if(_input->keyboard['v'] && points3){
         Matriz<3,1> t = mat.Translate2D(0,0,_nave->_p(0,0),_nave->_p(1,0))*mat.rotation2D(_nave->_angle)*_nave->_vertices[0];
         vTiros.push_back(GrandCircleShoot(_nave,_nave->_direction, t, _nave->_angle));
         _input->keyboard['v'] = false;
      }
      if(_input->keyboard['x'] && points1){
         Matriz<3,1> t = mat.Translate2D(0,0,_nave->_p(0,0),_nave->_p(1,0))*mat.rotation2D(_nave->_angle)*_nave->_vertices[0];
         vTiros.push_back(GuidedShoot(_nave,_nave->_direction, t,_nave->_angle));
         _input->keyboard['x'] = false;
      }
      if(_input->keyboard['l']){
         if(_nave->getSpeed() < 0){
            _nave->_angle -= 0.07f/(-1*((_nave->getSpeed()*0.1f)-1));
         }else{
            _nave->_angle += 0.07f/((_nave->getSpeed()*0.1f)+1);
         }
      }
      if(_input->keyboard['k']){
         if(_nave->getSpeed() > -5.0) 
            _nave->setSpeed(_nave->getSpeed() - 0.05f);
         else if(_nave->getSpeed() < -5.0)
            _nave->setSpeed(-5.00);
      }else
      {
         if(_nave->getSpeed() < -0.3f ){
            _nave->setSpeed(_nave->getSpeed() + 0.1f);               
         } else if(_nave->getSpeed() < 0 && _nave->getSpeed() >= -0.3f) {
            _nave->setSpeed(0);
         }
      }
      if(_input->keyboard['j']){
         if(_nave->getSpeed() < 0){
            _nave->_angle += 0.07f/(-1*((_nave->getSpeed()*0.1f)-1));
         }else{
            _nave->_angle -= 0.07f/((_nave->getSpeed()*0.1f)+1);
         }
      }
      if(_input->keyboard['i']){
         if(_nave->getSpeed() < 7.0f) 
            _nave->setSpeed(_nave->getSpeed() + 0.05f);
         else if(_nave->getSpeed() > 7.0f)
            _nave->setSpeed(7.0f);
      }else 
      {
         if(_nave->getSpeed() > 0.3f){
            _nave->setSpeed(_nave->getSpeed() - 0.1f);
         }else if(_nave->getSpeed() > 0 && _nave->getSpeed() <= 0.3f) {
            _nave->setSpeed(0);
         }
      }
      if(_input->keyboard['u']){
         Matriz<3,1> perp = mat.rotation2D((-M_PI/2)+_nave->_angle)*_nave->_direction;
         _nave->_p = mat.Translate2D(0,0,perp(0,0)*((_nave->getSpeed()/2)+1),perp(1,0)*((_nave->getSpeed()/2)+1))*_nave->_p;
      }
      if(_input->keyboard['o']){
         Matriz<3,1> perp = mat.rotation2D((M_PI/2)+_nave->_angle)*_nave->_direction;
         _nave->_p = mat.Translate2D(0,0,perp(0,0)*((_nave->getSpeed()/2)+1),perp(1,0)*((_nave->getSpeed()/2)+1))*_nave->_p;
      }
      ///////////////Keyboard///////////////

      //////////////New Shoots//////////////
      if(!points1 && gamePoints >= 1000){
         points1 = true;
         _gameNotes->setString("New Shoot Avaliable! [GuidedShoot (press x to shoot)]");
         time(&labelStart);
      }

      if(!points2 && gamePoints >= 5000){
         points2 = true;
         _gameNotes->setString("New Shoot Avaliable! [CircleShoot (press c to shoot)]");
         time(&labelStart);
      }

      if(!points3 && gamePoints >= 20000){
         points3 = true;
         _gameNotes->setString("New Shoot Avaliable! [GrandCircleShoot (press v to shoot)]");
         time(&labelStart);
         finish = true;
      }
      if(!finish)
      {
         time(&labelEnd);
         if(difftime (labelEnd,labelStart) > 5.0){
            _gameNotes->setString("");
         }
      }
      //////////////New Shoots//////////////

      ////////////Nave Updates/////////////
      _nave->updatePosition(WL, WA);
      ////////////Nave Updates/////////////

      ///////////Shoots update/////////////
      mSizes = (int)vTiros.size();
      for(int i = 0; i < mSizes; i ++)
      {
         vTiros[i].updatePosition(WL, WA, _nave);

         vTiros[i]._timeLife--;
         if(vTiros[i]._timeLife < 0)
         {
            vTiros.erase(vTiros.begin()+i,vTiros.begin()+i+1);
            mSizes--;
            if(i >= mSizes)
            {
               break;
            }
         }

         for(int j = 0; j < (int)vAsteroids.size() ; j++){
            if(vTiros[i].detectAsteroid(&vAsteroids[j])){
               vAsteroids[j]._life -= vTiros[i]._damage;
               vTiros.erase(vTiros.begin()+i,vTiros.begin()+i+1);
               mSizes--;
               if(vAsteroids[j]._life < 0){
                  gamePoints += (int)vAsteroids[j]._r;

                  if(vAsteroids[j]._repartition == 1){
                     vAExplosion.push_back(AsteroidExplosion(vAsteroids[j]._p, vAsteroids[j]._r));
                     vAsteroids.erase(vAsteroids.begin()+j, vAsteroids.begin()+j+1);
                  } else{
                     vAsteroids.push_back(Asteroid(vAsteroids[j]._p,  vAsteroids[j]._angle+(0.1f*(float)(rand()%64)),vAsteroids[j]._repartition-1,vAsteroids[j]._r/2.f));
                     vAsteroids.push_back(Asteroid(vAsteroids[j]._p,  vAsteroids[j]._angle-(0.1f*(float)(rand()%64)),vAsteroids[j]._repartition-1,vAsteroids[j]._r/2.f));
                     vAsteroids.push_back(Asteroid(vAsteroids[j]._p,  vAsteroids[j]._angle+(0.1f*(float)(rand()%64)),vAsteroids[j]._repartition-1,vAsteroids[j]._r/2.f));
                     vAsteroids.push_back(Asteroid(vAsteroids[j]._p,  vAsteroids[j]._angle-(0.1f*(float)(rand()%64)),vAsteroids[j]._repartition-1, vAsteroids[j]._r/2.f));
                     vAsteroids.erase(vAsteroids.begin()+j, vAsteroids.begin()+j+1);
                  }
               }
               break;
            }
         }

         for(int j = 0; j < (int)vEnemies.size() ; j++){
            if(vTiros[i].detectEnemy(&vEnemies[j])){
               vEnemies[j]._life -= vTiros[i]._damage;
               vTiros.erase(vTiros.begin()+i,vTiros.begin()+i+1);
               mSizes--;
               if(vEnemies[j]._life < 0){
                  gamePoints += (int)vEnemies[j]._points;
                  vEnemies.erase(vEnemies.begin()+j, vEnemies.begin()+j+1);
               }
               break;
            }
         }
      }
      ///////////Shoots update/////////////

      ////////Enemy Shoots Update///////////
      mSizes = (int)vETiros.size();
      for(int i = 0; i < mSizes; i ++){
         vETiros[i].updatePosition( WL, WA, _nave);
         if(vETiros[i].detectNaveP(_nave)){
            _nave->_life -= vETiros[i]._damage;
            vETiros.erase(vETiros.begin()+i,vETiros.begin()+i+1);
            mSizes--;
            std::stringstream sse1;
            sse1 << (_nave->_life);
            _lifeLabel->setString("Life: " + sse1.str());
            if(_nave->_life <= 0)
            {
               _lifeLabel->setVisible(false);
               _pointsLabel->setVisible(false);
               _gameNotes->setVisible(false);
               setVisible(false);
               _C_A->showTop10(gamePoints);
            }
         }
         if(i >= mSizes)
            break;
         vETiros[i]._timeLife--;
         if(vETiros[i]._timeLife < 0)
         {
            vETiros.erase(vETiros.begin()+i,vETiros.begin()+i+1);
            mSizes--;
         }
      }
      ////////Enemy Shoots Update///////////

      /////////Asteroids Update/////////////
      mSizes = (int)vAsteroids.size();
      for(int j = 0 ; j < mSizes ; j ++){
         if(_nave->detectAsteroid(&vAsteroids[j])){
            _nave->_life -= vAsteroids[j]._r;
            vAExplosion.push_back(AsteroidExplosion(vAsteroids[j]._p, vAsteroids[j]._r));
            vAsteroids.erase(vAsteroids.begin()+j, vAsteroids.begin()+j+1);
            mSizes--;
            std::stringstream sse1;
            sse1 << (_nave->_life);
            _lifeLabel->setString("Life: " + sse1.str());
            if(_nave->_life <= 0)
            {
               _lifeLabel->setVisible(false);
               _pointsLabel->setVisible(false);
               _gameNotes->setVisible(false);
               setVisible(false);
               _C_A->showTop10(gamePoints);
            }
         }else{
            vAsteroids[j].updatePosition(WL, WA);
         }
      }
      /////////Asteroids Update/////////////

      //////////Enemies update///////////// 
      mSizes = (int)vEnemies.size();
      for(int j = 0; j < mSizes ; j++){
         if(_nave->detectEnemy(&vEnemies[j])){
            _nave->_life -= 50;
            vEnemies.erase(vEnemies.begin()+j, vEnemies.begin()+j+1);
            mSizes--;
            std::stringstream sse1;
            sse1 << (_nave->_life);
            _lifeLabel->setString("Life: " + sse1.str());
            if(_nave->_life <= 0)
            {
               _lifeLabel->setVisible(false);
               _pointsLabel->setVisible(false);
               _gameNotes->setVisible(false);
               setVisible(false);
               _C_A->showTop10(gamePoints);
            }
         }else{
            vEnemies[j].updatePosition(WL, WA);
            if(vEnemies[j].shoot)
            {
               time(&vEnemies[j].start);
               vEnemies[j].shoot = false;
            }
            time(&vEnemies[j].end);
            if(difftime (vEnemies[j].end,vEnemies[j].start) > vEnemies[j]._shootTime){
               Matriz<3,1> dirT;
               dirT(2,0) = 1;
               dirT(1,0) = 0;
               dirT(0,0) = 1;
               Matriz<3,1> vAngle;
               vAngle(2,0) = 1;
               vAngle(0,0) = _nave->_p(0,0) - vEnemies[j]._p(0,0);
               vAngle(1,0) = _nave->_p(1,0) - vEnemies[j]._p(1,0);
               vAngle = mat.nomalizeVector2D(vAngle);
               float _angleShoot = mat.angleDotProduct2D(vAngle,dirT);
               if(vAngle(1,0) < dirT(1,0)){
                  _angleShoot *=-1;
               }
               vETiros.push_back(EnemyShoot(_nave,dirT, vEnemies[j]._p,_angleShoot));
               vEnemies[j].shoot = true;
            }

         }

      }
      //////////Enemies update/////////////

      //////////Asteroids explosion update/////////////
      mSizes = (int)vAExplosion.size();
      for(int i = 0; i < mSizes; i ++)
      {  
         vAExplosion[i].setRadius(vAExplosion[i].getRadius()-0.3f);
         if(vAExplosion[i].getRadius() < 0)
         {
            vAExplosion.erase(vAExplosion.begin()+i, vAExplosion.begin()+i+1);
            mSizes--;
         }
      }
      //////////Asteroids explosion update/////////////

      /////////////New stage///////////////
      if(vAsteroids.size() == 0 && shipTime)
      {
         vTiros.clear();
         vETiros.clear();
         for(int i = 0 ; i < nEnemies ; i++)
         {
            vEnemies.push_back(createEnemy(_nave));
         }
         nEnemies++;
         _nave->_p(0,0) = WL/2;
         _nave->_p(1,0) = WA/2;
         _nave->setSpeed(0);
         shipTime = false;
         asteroidTime = true;
      }else if (vEnemies.size() == 0 && asteroidTime)
      {
         vTiros.clear();
         vETiros.clear();
         Matriz<3,1> aw;
         aw(2,0) = 1;
         for(int i = 0 ; i < nAsteroids ; i++){
            aw(0,0) = (float)(800+rand()%1000);
            aw(1,0) = (float)(rand()%720);
            vAsteroids.push_back(Asteroid(aw, 0.f,rand()%3+1));
         }
         nAsteroids++;
         _nave->_p(0,0) = WL/2;
         _nave->_p(1,0) = WA/2;
         _nave->setSpeed(0);
         shipTime = true;
         asteroidTime = false;
      }
      /////////////New stage///////////////

      if(gamePoints != lastgamePoints)
      {
         std::stringstream ssp;
         ssp << (gamePoints);
         _pointsLabel->setString("Points: " + ssp.str());
         lastgamePoints = gamePoints;
      }
   }
}

void CanvasDraw::render(void) 
{  
   if(isVisible()){
      glClearColor(bg_color[0], bg_color[1], bg_color[2], bg_color[3]);
      glClear(GL_COLOR_BUFFER_BIT);
      Matriz<3,1> des;
      Matriz<3,3> multi;      
      //bImage->display();

      for(int i = 0; i < (int)vAExplosion.size(); i ++){   
         glBegin(GL_LINES);
         glColor3f(.2f, 0.f, .2f);
         for(float j = 0 ; j < 6.30 ; j+= 0.2f){
            glVertex2i((GLint)vAExplosion[i]._p(0,0), (GLint)vAExplosion[i]._p(1,0));
            des = mat.Translate2D(0,0,vAExplosion[i]._p(0,0),vAExplosion[i]._p(1,0))*
               mat.Scale2D1(vAExplosion[i].getRadius())*mat.rotation2D(j)*vAExplosion[i]._direction;  
            glVertex2i((GLint)des(0,0), (GLint)des(1,0));
         }  
         glEnd();
      }

      for(int i = 0; i < (int)vTiros.size(); i ++){
         vTiros[i].draw();
      }

      glBegin(GL_LINES);
      glColor3f(0.f, 1.f, 0.f);
      for(int i = 0; i < (int)vETiros.size(); i ++){
         multi = mat.Translate2D(0,0,vETiros[i]._p(0,0),vETiros[i]._p(1,0))*mat.rotation2D(vETiros[i]._angle);
         for(int j = 0 ; j < (int)vETiros[i]._vertices.size() ; j++){
            des = multi*vETiros[i]._vertices[j];
            glVertex2i((GLint)des(0,0), (GLint)des(1,0));
         }
      }
      glEnd();

      multi = mat.Translate2D(0,0,_nave->_p(0,0),_nave->_p(1,0))*
         mat.rotation2D(_nave->_angle);
      glBegin(GL_LINE_STRIP);
      glColor3f(1.f, .5f, 0.f);
      for(int i = 0; i < (int)_nave->_vertices.size(); i ++){
         des = multi*_nave->_vertices[i];
         glVertex2i((GLint)des(0,0), (GLint)des(1,0));
      }
      des = multi*_nave->_vertices[0];
      glVertex2i((GLint)des(0,0), (GLint)des(1,0));
      glEnd();    

      for(int i = 0 ; i < (int)vAsteroids.size() ; i++){
         glBegin(GL_TRIANGLE_FAN);
         glColor3f(.2f, 0.f, .2f);
         glVertex2i((GLint)vAsteroids[i]._p(0,0), (GLint)vAsteroids[i]._p(1,0));
         for(float j = 0; j < 6.31; j += 0.3f){
            glVertex2i((GLint)(vAsteroids[i]._p(0,0)+(vAsteroids[i]._r*cos(j))),
               (GLint)(vAsteroids[i]._p(1,0)+ (vAsteroids[i]._r*sin(j))));
         }
         glEnd();  
      }

      for(int i = 0 ; i < (int)vEnemies.size() ; i++)
      {
         multi = mat.Translate2D(0,0,vEnemies[i]._p(0,0),vEnemies[i]._p(1,0))*
            mat.rotation2D(vEnemies[i]._angle);
         glBegin(GL_POLYGON);
         glColor3f(0.f, 0.5f, .5f);
         for(int j = 0; j < (int)vEnemies[i]._vertices.size(); j ++){
            des = multi*vEnemies[i]._vertices[j];
            glVertex2i((GLint)des(0,0), (GLint)des(1,0));
         }
         des = multi*vEnemies[i]._vertices[0];
         glVertex2i((GLint)des(0,0), (GLint)des(1,0));
         glEnd();    
      }
   }
}