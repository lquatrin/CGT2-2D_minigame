#ifndef ____TOP10SCREEN__HPP__
#define ____TOP10SCREEN__HPP__

#include <SCV/Button.h>
#include <iostream>
#include <cstring>
#include <fstream> 
#include <cstdio>
#include <sstream>


//contém toda a parte de comunicação entre os menus e o menu top10
class Top10Menu
{
public:
   Top10Menu();
   ~Top10Menu();

   void setInitScreen(scv::Button *bs, scv::Button *bt,scv::Button *bq, std::vector<scv::Label*> &vScore);

   void setMenuVisible();

   void hideMenus();

   void copyToVector(std::vector<long int> vf);

   void passToLabels();

   void showTop10Labels();

   std::vector<long int> showTop10LabelsRetVet();

   void hideTop10Labels();

private:
   scv::Button *_bs;
   scv::Button *_bt;
   scv::Button *_bq;
   scv::Label *_score01;
   scv::Label *_score02;
   scv::Label *_score03;
   scv::Label *_score04;
   scv::Label *_score05;
   scv::Label *_score06;
   scv::Label *_score07;
   scv::Label *_score08;
   scv::Label *_score09;
   scv::Label *_score10;
   std::vector<long int> vValors;
};

//classe do botão para retornar ao menu principal
class RetButton : public scv::Button
{
public:
   RetButton(Top10Menu *T_M);

   ~RetButton();

   void onMouseUp(const scv::MouseEvent& evt);

   void show();

   void showAG(long int points);

private:
   Top10Menu *_T_M;

};


#endif