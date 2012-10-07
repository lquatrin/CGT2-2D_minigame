#ifndef ____BASIC_SHOOT____HPP____
#define ____BASIC_SHOOT____HPP____

#include "Nave.hpp"
#include "Shoot.hpp"
#include "Asteroid.hpp"

//tiro básico inicial do jogo
class BasicShoot : public Shoot
{
public:

   BasicShoot(Nave* _nave,Matriz<3,1> d,Matriz<3,1> _p, float graus) : Shoot(_nave,d, _p, graus) 
   {
      Matriz<3,1> v;
      v(2,0) = 1;
      v(0,0) = 8;
      v(1,0) = 0;
      addVertex(v);
      v(0,0) = -8;
      v(1,0) = 0;
      addVertex(v);
      _damage = 0.2f;
      _typeShoot = Basic;
      _timeLife = 70;

   }
   ~BasicShoot() {}


private:
};

#endif