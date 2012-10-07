#ifndef ____MENU__HPP__
#define ____MENU__HPP__

#include <SCV/Button.h>
#include <SCV/Canvas.h>
#include "CanvasDraw.h"
#include <SCV/Kernel.h>

//Classe com botões do Menu inicial do programa
class QuitButton : public scv::Button
{
public:
   QuitButton();

   ~QuitButton();

   void onMouseUp(const scv::MouseEvent& evt);

private:
};

class TopButton : public scv::Button
{
public:
   TopButton(RetButton *rt);

   ~TopButton();

   void onMouseUp(const scv::MouseEvent& evt);

private:
   RetButton *_rt;
};

class StartButton : public scv::Button
{
public:
   StartButton(CanvasDraw *mcanvas, QuitButton *qb,  TopButton *qt);

   ~StartButton();

   void onMouseUp(const scv::MouseEvent& evt);

private:
   CanvasDraw *_canvas;
   QuitButton *_qb;
   TopButton *_qt;
};

#endif