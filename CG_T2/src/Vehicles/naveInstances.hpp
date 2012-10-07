#ifndef ____NAVE__INSTANCES___HPP_____
#define ____NAVE__INSTANCES___HPP_____

#include "Nave.hpp"
#include "Enemy.hpp"

//funções que retornam instancias da nave e inimigo

Nave* createNave()
{
   Matriz<3,1> _p;
   _p(0,0) = 100;
   _p(1,0) = 100;
   _p(2,0) = 1;
   float _speed = 0 ;
   Matriz<3,1> _direction;
   _direction(0,0) = 1;
   _direction(1,0) = 0;
   _direction(2,0) = 1;
   std::vector<Matriz<3,1>> _vertices;
   Matriz<3,1> _v;
   _v(0,0) = 25;
   _v(1,0) = 0;
   _v(2,0) = 1;
   _vertices.push_back(_v);
   _v(0,0) = -5;
   _v(1,0) = -7;
   _vertices.push_back(_v);
   _v(0,0) = 1;
   _v(1,0) = -8;
   _vertices.push_back(_v);
   _v(0,0) = -4;
   _v(1,0) = -9;
   _vertices.push_back(_v);
   _v(0,0) = -4;
   _v(1,0) = -13;
   _vertices.push_back(_v);
   _v(0,0) = -16;
   _v(1,0) = -18;
   _vertices.push_back(_v);
   _v(0,0) = -6;
   _v(1,0) = -10;
   _vertices.push_back(_v);
   _v(0,0) = -17;
   _v(1,0) = -10;
   _vertices.push_back(_v);
   _v(0,0) = -6;
   _v(1,0) = -7;
   _vertices.push_back(_v);

   _v(0,0) = -14;
   _v(1,0) = 0;
   _vertices.push_back(_v); 

   _v(0,0) = -6;
   _v(1,0) = +7;
   _vertices.push_back(_v);
   _v(0,0) = -17;
   _v(1,0) = +10;
   _vertices.push_back(_v);
   _v(0,0) = -6;
   _v(1,0) = +10;
   _vertices.push_back(_v);
   _v(0,0) = -16;
   _v(1,0) = +18;
   _vertices.push_back(_v);
   _v(0,0) = -4;
   _v(1,0) = +13;
   _vertices.push_back(_v);
   _v(0,0) = -4;
   _v(1,0) = +9;
   _vertices.push_back(_v);
   _v(0,0) = 1;
   _v(1,0) = +8;
   _vertices.push_back(_v);
   _v(0,0) = -5;
   _v(1,0) = +7;
   _vertices.push_back(_v);
   return new Nave(_p, _speed, _direction, _vertices);
}

Enemy createEnemy(Nave *n)
{
   Matriz<3,1> _p;
   _p(0,0) = (float)((rand()%2)*1280);
   _p(1,0) = (float)(rand()%800);
   _p(2,0) = 1;
   float _speed = (float)((rand()%3)+3);
   Matriz<3,1> _direction;
   _direction(0,0) = 1;
   _direction(1,0) = 0;
   _direction(2,0) = 1;
   std::vector<Matriz<3,1>> _vertices;
   Matriz<3,1> _v;
   _v(0,0) = 15;
   _v(1,0) = 0;
   _v(2,0) = 1;
   _vertices.push_back(_v);
   _v(0,0) = 10;
   _v(1,0) = -10;
   _vertices.push_back(_v);
   _v(0,0) = 2;
   _v(1,0) = -10;
   _vertices.push_back(_v);
   _v(0,0) = 0;
   _v(1,0) = -13;
   _vertices.push_back(_v);
   _v(0,0) = -2;
   _v(1,0) = -10;
   _vertices.push_back(_v);
   _v(0,0) = -10;
   _v(1,0) = -10;
   _vertices.push_back(_v);

   _v(0,0) = -15;
   _v(1,0) = 0;
   _vertices.push_back(_v);

   _v(0,0) = -10;
   _v(1,0) = 10;
   _vertices.push_back(_v);
   _v(0,0) = -2;
   _v(1,0) = 10;
   _vertices.push_back(_v);
   _v(0,0) = 0;
   _v(1,0) = 13;
   _vertices.push_back(_v); 
   _v(0,0) = 2;
   _v(1,0) = 10;
   _vertices.push_back(_v);
   _v(0,0) = 10;
   _v(1,0) = 10;
   _vertices.push_back(_v);
   return Enemy(n, _p, _speed, _direction, _vertices);
}


#endif