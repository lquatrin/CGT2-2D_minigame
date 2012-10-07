#include "Menu.hpp"
#include <SCV/Button.h>
#include <SCV/Canvas.h>
#include "CanvasDraw.h"
#include <SCV/Kernel.h>

QuitButton::QuitButton() : scv::Button(scv::Point(600, 400),scv::Point(680, 420), "Quit") 
{
}

QuitButton::~QuitButton() {}

void QuitButton::onMouseUp(const scv::MouseEvent& evt)
{
   if(isVisible()){
      static scv::Kernel *kernel = scv::Kernel::getInstance();
      kernel->destroyInstance();
      exit(0);
   }
}

TopButton::TopButton(RetButton *rt) : scv::Button(scv::Point(600, 350),scv::Point(680, 370), "TOP 10") 
{
   _rt = rt;
}

TopButton::~TopButton() {}

void TopButton::onMouseUp(const scv::MouseEvent& evt)
{
   if(isVisible()){
      _rt->show();
   }
}

StartButton::StartButton(CanvasDraw *mcanvas, QuitButton *qb,  TopButton *qt) : scv::Button(scv::Point(600, 300),scv::Point(680, 320), "Start") 
{
   _canvas = mcanvas;
   _qb = qb;
   _qt = qt;
}

StartButton::~StartButton() {}

void StartButton::onMouseUp(const scv::MouseEvent& evt)
{
   if(isVisible()){
      _canvas->initGame();
      setVisible(false);
      _qb->setVisible(false);
      _qt->setVisible(false);

   }
}