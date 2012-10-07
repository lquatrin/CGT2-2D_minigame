#ifndef ____EXPLOSION_SHOOT____HPP____
#define ____EXPLOSION_SHOOT____HPP____

#include "Nave.hpp"
#include "Shoot.hpp"
#include "Asteroid.hpp"

//Tiro que forma um circulo na parte da frente da nave e não se move
class GrandCircleShoot : public Shoot
{
public:
   GrandCircleShoot(Nave* _nave,Matriz<3,1> d,Matriz<3,1> _p, float graus) : Shoot(_nave,d, _p, graus) 
   {
      _r = 30;
      _damage = 2;
      _typeShoot = GrandCircle;
      _timeLife = 200;

   }
   ~GrandCircleShoot() {}

private:
   mFunctions mat;
   Intersections inte;
};

#endif