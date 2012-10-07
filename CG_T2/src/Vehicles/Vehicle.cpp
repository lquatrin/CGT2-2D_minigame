#include "Vehicle.hpp"
#include <vector>
#include "Matriz.hpp"
#include "GObject.hpp"

Vehicle::Vehicle(Matriz<3,1> p, float speed, Matriz<3,1> direction, std::vector<Matriz<3,1>> vertices)
   : GObject(p, speed, direction, 0)
{
   for(int i = 0 ; i < (int)vertices.size() ; i++)
   {
      _vertices.push_back(vertices[i]);
   }
}

Vehicle::~Vehicle() {} 
