#ifndef ____ENEMY_SHOOT____HPP____
#define ____ENEMY_SHOOT____HPP____

#include "Nave.hpp"
#include "Shoot.hpp"
#include "Asteroid.hpp"

//Tiro que o inimigo solta na nave do jogador
class EnemyShoot : public Shoot
{
public:
   EnemyShoot(Nave* _nave,Matriz<3,1> d,Matriz<3,1> _p, float graus) : Shoot(_nave,d, _p, graus) 
   {
      Matriz<3,1> v;
      v(2,0) = 1;
      v(0,0) = 8;
      v(1,0) = 0;
      addVertex(v);
      v(0,0) = -8;
      v(1,0) = 0;
      addVertex(v);
      _damage = 30;
      _typeShoot = EnemyBasic;
      _timeLife = 100;
   }
   ~EnemyShoot() {}

private:
};

#endif