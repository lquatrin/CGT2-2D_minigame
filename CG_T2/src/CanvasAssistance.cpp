#include "CanvasAssistance.h"
#include <SCV/Button.h>
#include "Top10Screen.hpp"

CanvasAssistance::CanvasAssistance(RetButton *rt) 
{
   _rt = rt;
}

CanvasAssistance::~CanvasAssistance() {}

void CanvasAssistance::showTop10(long int points)
{
   _rt->showAG(points);
}
