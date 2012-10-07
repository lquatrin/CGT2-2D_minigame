#ifndef ___CANVAS___DRAW____H___
#define ___CANVAS___DRAW____H___

#include <SCV/Canvas.h>
#include <SCV/Label.h>
#include <SCV/Color4f.h>
#include "Nave.hpp"
#include "Input.hpp"
#include "Asteroid.hpp"
#include "Enemy.hpp"
#include "AsteroidExplosion.hpp"
#include "CanvasAssistance.h"
#include "Shoot.hpp"
#include <SCV/Image.h>

//Classe principal do Canvas, onde é rodado
//o jogo inteiro
//contém todas as variáveis que são usadas no jogo
class CanvasDraw : public scv::Canvas {
public:
      
   CanvasDraw(scv::Label *lifeLabel, scv::Label *pointsLabel, CanvasAssistance *C_A, scv::Label *gameNotes);
   ~CanvasDraw() {
      delete _nave;
      delete _input;
      delete _C_A;
      //delete bImage;
      delete _pointsLabel;
      delete _lifeLabel;
   }

   void onMouseClick(const scv::MouseEvent& evt);

   void setBackground(const scv::Color4f& color);

   void onMouseHold (const scv::MouseEvent& evt);

   void onMouseOver(const scv::MouseEvent& evt);

   void onMouseUp(const scv::MouseEvent& evt);

   void onKeyPressed(const scv::KeyEvent& evt);
   
   void onKeyUp(const scv::KeyEvent& evt);

   void update(void);

   void render(void);

   void initGame();

   CanvasAssistance *_C_A;

protected:

private:
   scv::Color4f bg_color;   
   scv::Point p;
   Nave *_nave;
   std::vector<char> teclas;
   Input *_input;
   std::vector<Shoot> vTiros;
   std::vector<Enemy> vEnemies;
   std::vector<Asteroid> vAsteroids;
   mFunctions mat;
   int nAsteroids;
   scv::Label *_lifeLabel;
   scv::Label *_pointsLabel;
   long int gamePoints;
   bool asteroidTime;
   bool shipTime;
   int nEnemies;
   std::vector<Shoot> vETiros;
   std::vector<AsteroidExplosion> vAExplosion;
   bool points1, points2, points3;
   scv::Label *_gameNotes;
   bool finish;
   long int lastgamePoints;
   //scv::Image *bImage;
   
};

#endif