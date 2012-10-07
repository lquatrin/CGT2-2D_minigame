#include "Enemy.hpp"
#include "Nave.hpp"
#include "Vehicle.hpp"
#include <ctime>

Enemy::Enemy(Nave *nave, Matriz<3,1> pp, float sp,  Matriz<3,1> dir, std::vector<Matriz<3,1>> vert) 
   : Vehicle( pp, sp, dir, vert)
{
   _nave = nave;
   _life = 3;
   _points = 100;
   _grausteste = (float)((rand()%630)/100);
   shoot = true;
   _shootTime = (float)(rand()%5 + 4);
}

Enemy::~Enemy() {}

void Enemy::updatePosition(int WL, int WA)
{
   _grausteste += (-1*(rand()%2))*((rand()%120)/100);
   Matriz<3,1> movEnemy = mat.rotation2D(_grausteste)*_direction;
   _p = mat.Translate2D(0,0,movEnemy(0,0)*getSpeed(),movEnemy(1,0)*getSpeed())*_p;
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
