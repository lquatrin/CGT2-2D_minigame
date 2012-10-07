#ifndef ___VEHICLE____H____
#define ___VEHICLE____H____

#include <vector>
#include "Matriz.hpp"
#include "GObject.hpp"

//Função base para os veículos do jogo
class Vehicle : public GObject
{
public:
   Vehicle(Matriz<3,1> p, float speed, Matriz<3,1> direction, std::vector<Matriz<3,1>> vertices);

   ~Vehicle();

   float _life;
private:

};

#endif