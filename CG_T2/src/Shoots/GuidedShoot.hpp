#ifndef ____GUIDED_SHOOT____HPP____
#define ____GUIDED_SHOOT____HPP____

#include "Nave.hpp"
#include "Shoot.hpp"
#include "Asteroid.hpp"

//Classe de tiro que se move com a movimentação da nave
class GuidedShoot : public Shoot
{
public:
   GuidedShoot(Nave* _nave,Matriz<3,1> d,Matriz<3,1> _p, float graus) : Shoot(_nave,d, _p, graus) 
   {
      Matriz<3,1> v;
      v(2,0) = 1;
      v(0,0) = 6;
      v(1,0) = 0;
      addVertex(v);
      v(0,0) = -6;
      v(1,0) = 0;
      addVertex(v);
      _damage = 0.2f;
      _typeShoot = Guided;
      _timeLife = 100;
      setSpeed(9);

   }
   ~GuidedShoot() {}

private:
};

#endif