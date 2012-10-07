#ifndef ___INTERSECTIONS___HPP____
#define ___INTERSECTIONS___HPP____

#include <cmath>

#include <vector>
#include "Matriz.hpp"

//classe com funções de intersecção usadas para tirosxnaves tirosxasteroides navexasteroides
class Intersections{
public:

   /*Quadrado e linha*/
   //vertices do quadrado
   /*
   0------------------1
   |                  |
   |                  |
   |                  |
   |                  |
   |                  |
   |                  |
   3------------------2
   */
   bool intersectionQuadLine(std::vector<Matriz<3,1>> _vq, std::vector<Matriz<3,1>> _vl)
   {
      for(int i = 0 ; i < 2 ; i ++)
      {
         if(_vl[i](0,0) >= _vq[0](0,0) && _vl[i](0,0) <= _vq[1](0,0))
         {
            if(_vl[i](1,0) >= _vq[0](1,0) && _vl[i](1,0) <= _vq[2](1,0)){
               return true;      
            }
         }
      }
      return false;
   }

   bool intersectionCircLine(Matriz<3,1> _p, float r, std::vector<Matriz<3,1>> _vl)
   {
      for(int i = 0 ; i < (int)_vl.size() ; i ++)
      {
         float t = pow((_p(0,0)-_vl[i](0,0)),2)+pow((_p(1,0)-_vl[i](1,0)),2);
         if(t <= pow(r,2)){
            return true;
         }
      }
      return false;
   }

   /*
   1
   |\
   | \ 
   |  \
   |   0
   |  /
   | /
   |/
   2
   */
   bool intersectionTrigLine(std::vector<Matriz<3,1>> _vt, std::vector<Matriz<3,1>> _vl) 
   {
      for(int i = 0 ; i < (int)_vl.size() ; i ++)
      {
         float x1 = ((10.f/42.f)*(_vl[i](0,0)+17.f))-10.f;//-10
         float x2 = ((-10.f/42.f)*(_vl[i](0,0)+17.f))+10.f;//10
         if(_vl[i](0,0) >= _vt[1](0,0) && _vl[i](0,0) <= _vt[0](0,0))
         {  
            if(_vl[i](1,0) <= x2+0.5f && _vl[i](1,0) >= x1-0.5f){
               return true;      
            }
         }
      }
      return false;
   }

   bool intersectionTriCirc(Matriz<3,1> _p, float r) {return false;}

   bool intersectionCircCirc(Matriz<3,1> _p, float _r, Matriz<3,1> p, float r)
   {
      float ret = pow(_p(0,0)-p(0,0),2) + pow(_p(1,0)-p(1,0),2);
      if(ret <= pow((_r+r),2))
         return true;

      return false;
   }
};

#endif