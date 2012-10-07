#ifndef ___NAVE___HPP___
#define ___NAVE___HPP___

#include "Vehicle.hpp"
#include "Intersections.hpp"
#include "Asteroid.hpp"

//Classe da nave principal do jogo
class Nave : public Vehicle
{
public:
   Nave(Matriz<3,1> p, float _speed, Matriz<3,1> _direction, std::vector<Matriz<3,1>> _vertices);

   ~Nave();
     
   void reset();

   bool detectAsteroid(Asteroid *o);

   bool detectEnemy(Vehicle *o);

   void updatePosition(int WL, int WA);

private:
   mFunctions mat;
   Intersections inte;

};


#endif