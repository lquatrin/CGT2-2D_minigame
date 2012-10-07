#ifndef __ASTEROID___HPP___
#define __ASTEROID___HPP___


#include "Matriz_Functions.hpp"
#include "Matriz.hpp"
#include <cstdlib>
#include "GObject.hpp"

//classe que possui os asteroides
class Asteroid : public GObject
{
public:
   Asteroid::Asteroid(Matriz<3,1> p,  float angle, int repart, float r = (float)((rand()%30)+20)   ) 
      : GObject(p,((rand()%4)+1.f), (mat.rotation2D((float)((rand()%630)/100))*mat.negBasicXDirection()), (float)angle)
   {
      _r = r;
      _repartition = repart;
      _life = r/100;
   }

   ~Asteroid();

   float _r;
   int _repartition;

   void updatePosition(int WL, int WA);

   float _life;

private:
   mFunctions mat;
};



#endif