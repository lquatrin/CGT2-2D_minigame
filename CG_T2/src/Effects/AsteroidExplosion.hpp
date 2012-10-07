#ifndef ___ASTEROID_EXPLOSION___HPP__
#define ___ASTEROID_EXPLOSION___HPP__

#include "Matriz.hpp"
#include "Matriz_Functions.hpp"

//Efeito de asteroide quando ele é destruído
class AsteroidExplosion
{
public:
   AsteroidExplosion(Matriz<3,1> p, float r);
   ~AsteroidExplosion();

   void setRadius(float r);
 
   float getRadius();

   Matriz<3,1> _p;
   Matriz<3,1> _direction;
private:
   mFunctions mat;
   float _r;
};

#endif