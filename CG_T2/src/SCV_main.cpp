#include <SCV/Kernel.h>
#include <SCV/ColorScheme.h>
#include <SCV/ButtonGroup.h>
#include "../src/Canvas/CanvasDraw.h"
#include "Menu.hpp"
#include "CanvasAssistance.h"
#include "Top10Screen.hpp"

int const WL = 1280;
int const WA = 800;

void SCV_main(){

   using namespace scv;

   // Kernel Instance
   static Kernel *kernel = Kernel::getInstance();

   // Load ColorScheme
   static ColorScheme *scheme = ColorScheme::getInstance();
   scheme->loadScheme(ColorScheme::warcraft);

   // Set Windows Size
   kernel->setWindowSize(WL, WA);
   kernel->setWindowTitle("CG_T2");

   // Set Frame Rate
   kernel->setFramesPerSecond(55.f);

   std::cout << "Implementacoes" << std::endl;
   std::cout << "-Movimentacao da nave" << std::endl;
   std::cout << "-Adicao de tiros(4 tipos)" << std::endl;
   std::cout << "-Adicao de asteroides com divisoes" << std::endl;
   std::cout << "-Adicao de naves inimigas que atiram no oponente" << std::endl;
   std::cout << "movimentacao: " << std::endl;
   std::cout << "i->para frente" << std::endl;
   std::cout << "k->para tras" << std::endl;
   std::cout << "j->gira para esquerda" << std::endl;
   std::cout << "l->gira para direita" << std::endl;
   std::cout << "o->move para o lado direito" << std::endl;
   std::cout << "u->move para o lado esquerdo" << std::endl;
   std::cout << "q->passa para o proximo estagio" << std::endl;
   std::cout << "z,x,c,v->tiros (sendo desbloqueados de acordo com a pontuacao)" << std::endl;


   kernel->addComponent(new scv::Image(scv::Point(0,0), "Resources/Bbackground.jpg"));

   std::vector<scv::Label*> vLabels;
   scv::Label *sc = new scv::Label(scv::Point(500,100), scv::Point(600,110),"01 - 00000");
   vLabels.push_back(sc);
   sc = new scv::Label(scv::Point(500,120), scv::Point(600,130),"02 - 00000");
   vLabels.push_back(sc);
   sc = new scv::Label(scv::Point(500,140), scv::Point(600,150),"03 - 00000");
   vLabels.push_back(sc);
   sc = new scv::Label(scv::Point(500,160), scv::Point(600,170),"04 - 00000");
   vLabels.push_back(sc);
   sc = new scv::Label(scv::Point(500,180), scv::Point(600,190),"05 - 00000");
   vLabels.push_back(sc);
   sc = new scv::Label(scv::Point(500,200), scv::Point(600,210),"06 - 00000");
   vLabels.push_back(sc);
   sc = new scv::Label(scv::Point(500,220), scv::Point(600,230),"07 - 00000");
   vLabels.push_back(sc);
   sc = new scv::Label(scv::Point(500,240), scv::Point(600,250),"08 - 00000");
   vLabels.push_back(sc);
   sc = new scv::Label(scv::Point(500,260), scv::Point(600,270),"09 - 00000");
   vLabels.push_back(sc);
   sc = new scv::Label(scv::Point(500,280), scv::Point(600,290),"10 - 00000");
   vLabels.push_back(sc);

   for(int i = 0 ; i < (int)vLabels.size() ; i++)
      kernel->addComponent(vLabels[i]);

   Top10Menu *T_M = new Top10Menu();
   RetButton *rt = new RetButton(T_M);
   CanvasAssistance *C_A = new CanvasAssistance(rt);
   scv::Label *points = new Label(scv::Point(70,0), scv::Point(200,10),"Score: ");
   scv::Label *life = new Label(scv::Point(0,0), scv::Point(70,10),"Life: ");
   scv::Label *gameNotes = new Label(scv::Point(400,0), scv::Point(1000,10),"");
   CanvasDraw *mcanvas = new CanvasDraw(life, points,C_A, gameNotes);
   QuitButton *qb = new QuitButton();
   TopButton *qt = new TopButton(rt);
   StartButton *st = new StartButton(mcanvas,qb,qt );
   kernel->addComponent(mcanvas);
   kernel->addComponent(life);
   kernel->addComponent(points);
   kernel->addComponent(st);
   kernel->addComponent(qb);
   kernel->addComponent(qt);
   kernel->addComponent(rt);
   kernel->addComponent(gameNotes);
   T_M->setInitScreen(st,qt,qb,vLabels);
   kernel->run();

}