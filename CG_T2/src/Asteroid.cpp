#include "Matriz.hpp"
#include "Asteroid.hpp"
#include "Matriz_Functions.hpp"
#include <cstdlib>
#include "GObject.hpp"

Asteroid::~Asteroid() {}

void Asteroid::updatePosition(int WL, int WA)
{
   Matriz<3,1> movAsteroid = mat.rotation2D(_angle)*_direction;
   _p = mat.Translate2D(0,0,movAsteroid(0,0)*getSpeed(),movAsteroid(1,0)*getSpeed())*_p;
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