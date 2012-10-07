#ifndef ____ENEMY__HPP____
#define ____ENEMY__HPP____

#include "Nave.hpp"
#include "Vehicle.hpp"
#include <ctime>

//Classe da Nave inimiga
class Enemy : public Vehicle
{
public:
   Enemy(Nave *nave, Matriz<3,1> pp, float sp,  Matriz<3,1> dir, std::vector<Matriz<3,1>> vert);

   ~Enemy();
  
   void updatePosition(int WL, int WA);

   float _life;
   Nave *_nave;
   int _points;
   float _grausteste;
   time_t start,end;
   bool shoot;
   float _shootTime;

private:
   mFunctions mat;
   Intersections inte;
   
};

#endif