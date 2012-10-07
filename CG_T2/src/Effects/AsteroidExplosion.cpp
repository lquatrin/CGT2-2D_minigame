#include "AsteroidExplosion.hpp"
#include "Matriz.hpp"
#include "Matriz_Functions.hpp"

AsteroidExplosion::AsteroidExplosion(Matriz<3,1> p, float r) 
{
   _p = p;
   _r = r;
   _direction = mat.BasicXDirection();
}

AsteroidExplosion::~AsteroidExplosion() {}

void AsteroidExplosion::setRadius(float r)
{
   _r = r;
}

float AsteroidExplosion::getRadius()
{
   return _r;
}