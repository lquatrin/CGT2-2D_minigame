#include "Nave.hpp"
#include "Vehicle.hpp"
#include "Intersections.hpp"
#include "Asteroid.hpp"

Nave::Nave(Matriz<3,1> p, float _speed, Matriz<3,1> _direction, std::vector<Matriz<3,1>> _vertices)
   : Vehicle( p, _speed, _direction, _vertices)
{
   _angle = 0;
   _life = 200;

}
Nave::~Nave() {}

void Nave::reset()
{
   _angle = 0;
   _life = 200;
   setSpeed( 0 );
}

bool Nave::detectAsteroid(Asteroid *o) 
{
   std::vector<Matriz<3,1>> vLines;
   vLines.push_back(_p);   
   Matriz<3,1> des;
   Matriz<3,3> multi = mat.Translate2D(0,0,_p(0,0),_p(1,0))*mat.rotation2D(_angle);
   /*for(int i = 0 ; i < (int)_vertices.size() ; i++)
   {
      des = multi*_vertices[i];
      vLines.push_back(des);   
   }*/
   des = multi*_vertices[0];
   vLines.push_back(des); 
   des = multi*_vertices[2];
   vLines.push_back(des); 
   des = multi*_vertices[4];
   vLines.push_back(des); 
   des = multi*_vertices[5];
   vLines.push_back(des); 
   des = multi*_vertices[7];
   vLines.push_back(des); 
   des = multi*_vertices[9];
   vLines.push_back(des); 
   des = multi*_vertices[11];
   vLines.push_back(des); 
   des = multi*_vertices[13];
   vLines.push_back(des); 
   des = multi*_vertices[14];
   vLines.push_back(des); 
   des = multi*_vertices[16];
   vLines.push_back(des); 
   des = _p;
   vLines.push_back(des); 
   return inte.intersectionCircLine(o->_p,o->_r,vLines);
}

bool Nave::detectEnemy(Vehicle *o)
{
   return false;
}

void Nave::updatePosition(int WL, int WA)
{
   Matriz<3,1> movShip = mat.rotation2D(_angle)*_direction;
   _p = mat.Translate2D(0,0,movShip(0,0)*getSpeed(),movShip(1,0)*getSpeed())*_p;

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