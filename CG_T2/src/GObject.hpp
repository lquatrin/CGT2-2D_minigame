#ifndef ____GOBJECT____HPP____
#define ____GOBJECT____HPP____

#include <vector>
#include "Matriz.hpp"

//Classe base dos Objetos criados no jogo
class GObject
{

public:
   GObject(Matriz<3,1> p, float speed, Matriz<3,1> direction, float angle);
   ~GObject();

   float getSpeed();
   void setSpeed(float sp);

   Matriz<3,1> _p;
   Matriz<3,1> _direction;
   std::vector<Matriz<3,1>> _vertices;
   float _angle;

private:
   float _speed;
};

#endif
