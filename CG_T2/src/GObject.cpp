#include "GObject.hpp"
#include <vector>
#include "Matriz.hpp"

GObject::GObject(Matriz<3,1> p, float speed, Matriz<3,1> direction, float angle)
{
   _p = p;
   _speed = speed;
   _direction = direction;
   _angle = angle;
}

GObject::~GObject() {}

float GObject::getSpeed()
{
   return _speed;
}

void GObject::setSpeed(float sp)
{
   _speed = sp;
}

