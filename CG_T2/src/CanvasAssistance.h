#ifndef __CANVAS_ASSISTANCE__HPP__
#define __CANVAS_ASSISTANCE__HPP__

#include <SCV/Button.h>
#include "Top10Screen.hpp"

//classe que faz a comunicação entre o canvas e o menu dos top10
class CanvasAssistance
{
public:
   CanvasAssistance(RetButton *rt);
   ~CanvasAssistance();

   void showTop10(long int points);

private:
   RetButton *_rt;
};


#endif