#ifndef ____CIRCLE_SHOOT____HPP____
#define ____CIRCLE_SHOOT____HPP____

#include "Nave.hpp"
#include "Shoot.hpp"
#include "Asteroid.hpp"

//Tiros em formato de circulo
class CircleShoot : public Shoot
{
public:
   CircleShoot(Nave* _nave,Matriz<3,1> d,Matriz<3,1> _p,float angle) : Shoot(_nave,d, _p,angle) 
   {
      _damage = 0.5;
      _typeShoot = Circle;
      _timeLife = 150;
      setSpeed(5);
      _r = 5;

   }
   ~CircleShoot() {}
private:
};

#endif