#ifndef ____SHOOT__HPP____
#define ____SHOOT__HPP____

#include "Nave.hpp"
#include "GObject.hpp"
#include "Asteroid.hpp"
#include "Intersections.hpp"
#include "Matriz_Functions.hpp"
#include "Vehicle.hpp"
#include "CanvasDraw.h"
#include <SCV/Canvas.h>

//enum contendo os tipos de tiro usados
enum typeShoot {
   NONE, Basic,
   Guided, EnemyBasic,
   Circle, GrandCircle
};

//Classe base para todos os tiros que foram criados
class Shoot : public GObject
{
public:
   Shoot(Nave* _nave,Matriz<3,1> d,Matriz<3,1> _p, float graus) : GObject(_p, 10, d, graus)
   {
      _timeLife = 0;
      _typeShoot = NONE;
   }
   ~Shoot() {}


   void addVertex(Matriz<3,1> v)
   {
      _vertices.push_back(v);
   }

   void updatePosition(int WL, int WA, Nave *_nave)
   {
      if(_typeShoot == Basic || _typeShoot == EnemyBasic){
         Matriz<3,1> movShip = mat.rotation2D(_angle)*_direction;
         _p = mat.Translate2D(0,0,movShip(0,0)*getSpeed(),movShip(1,0)*getSpeed())*_p;
      } else if(_typeShoot == Guided){
         Matriz<3,1> movShip = mat.rotation2D(_nave->_angle)*_direction;
         _p = mat.Translate2D(0,0,movShip(0,0)*getSpeed(),movShip(1,0)*getSpeed())*_p;
      }else if(_typeShoot == Circle){
         Matriz<3,1> movShip = mat.rotation2D(_angle)*_direction;
         _p = mat.Translate2D(0,0,movShip(0,0)*getSpeed(),movShip(1,0)*getSpeed())*_p;
      }


      if(_p(1,0) < 0)
      {
         _p(1,0) += WA;
      }
      if(_p(1,0) > WA)
      {
         _p(1,0) -= WA;
      }
      if(_p(0,0) < 0)
      {
         _p(0,0) += WL;
      }
      if(_p(0,0) > WL)
      {
         _p(0,0) -= WL;
      }
   }

   bool detectAsteroid(Asteroid *o){    
      if(_typeShoot == Basic ||_typeShoot == Guided){
         std::vector<Matriz<3,1>> vLines;
         Matriz<3,1> des;      
         Matriz<3,3> multi = mat.Translate2D(0,0,_p(0,0),_p(1,0))*mat.Scale2D1(4)*mat.rotation2D(_angle);    
         for(int j = 0 ; j < (int)_vertices.size() ; j++){
            des = multi*_vertices[j]; 
            vLines.push_back(des);
         }
         return inte.intersectionCircLine(o->_p,o->_r,vLines);
      }else if(_typeShoot == Circle || _typeShoot == GrandCircle)
      {
         return inte.intersectionCircCirc(o->_p,o->_r,_p, _r);
      }
      return false;
   }

   void draw()
   {
      if(_typeShoot == Basic ||_typeShoot == Guided){
         Matriz<3,3> multi = mat.Translate2D(0,0,_p(0,0),_p(1,0))*mat.rotation2D(_angle);
         Matriz<3,1> des;
         glBegin(GL_LINES);
         glColor3f(1.f, 0.f, 0.f);
         for(int j = 0 ; j < (int)_vertices.size() ; j++){
            des = multi*_vertices[j];
            glVertex2i((GLint)des(0,0), (GLint)des(1,0));
         }
         glEnd();
      }else if(_typeShoot == Circle || _typeShoot == GrandCircle){
         glBegin(GL_TRIANGLE_FAN);
         glColor3f(1.f, 0.f, 0.f);
         glVertex2i((GLint)_p(0,0), (GLint)_p(1,0));
         for(float j = 0; j < 6.3f; j += 0.1f){
            glVertex2i((GLint)(_p(0,0)+(_r*cos(j))),
               (GLint)(_p(1,0)+ (_r*sin(j))));
         }
         glEnd();
      }
   }

   bool detectEnemy(Vehicle *o)
   {
      if(_typeShoot == Basic ||_typeShoot == Guided){
         std::vector<Matriz<3,1>> vLines;   
         Matriz<3,3> multi = mat.Translate2D(0,0,_p(0,0),_p(1,0))*mat.Scale2D1(4)*mat.rotation2D(_angle);    
         for(int j = 0 ; j < (int)_vertices.size() ; j++){
            vLines.push_back(multi*_vertices[j]);
         }
         multi = mat.Translate2D(0,0,o->_p(0,0),o->_p(1,0));
         return inte.intersectionCircLine(o->_p, 10,vLines);
      }else if(_typeShoot == Circle || _typeShoot == GrandCircle)
      {
         return inte.intersectionCircCirc(o->_p, 10,_p, _r);
      }
      return false;
   }

   bool detectNaveP(Nave *o)
   {
      if(_typeShoot == EnemyBasic){
         std::vector<Matriz<3,1>> vLines;   
         Matriz<3,1> pontoShoot;
         pontoShoot(2,0) = 1;
         pontoShoot(0,0) = (_p(0,0) - o->_p(0,0));
         pontoShoot(1,0) = (_p(1,0) - o->_p(1,0));
         pontoShoot = mat.rotation2D(-1.f*o->_angle)*pontoShoot;
         Matriz<3,3> multi = mat.Translate2D(0,0,pontoShoot(0,0),pontoShoot(1,0))*mat.rotation2D(-1.f*(o->_angle-_angle));    
         for(int j = 0 ; j < (int)_vertices.size() ; j++){
            Matriz<3,1> des = multi*_vertices[j];
            vLines.push_back(des);
         }  
         std::vector<Matriz<3,1>> vTrig;
         vTrig.push_back(o->_vertices[0]);
         vTrig.push_back(o->_vertices[7]);
         vTrig.push_back(o->_vertices[11]);
         return inte.intersectionTrigLine(vTrig,vLines);

      }
      return false;
   }


   int _timeLife;
   float _r;
   float _damage;
protected:
   typeShoot _typeShoot;
private:
   mFunctions mat;
   Intersections inte;
};


#endif