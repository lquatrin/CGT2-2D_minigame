#include "Top10Screen.hpp"

Top10Menu::Top10Menu() {}
Top10Menu::~Top10Menu() {}

void Top10Menu::setInitScreen(scv::Button *bs, scv::Button *bt,scv::Button *bq, std::vector<scv::Label*> &vScore)
{
   _bs = bs;
   _bt = bt;
   _bq = bq;
   _score01 = vScore[0];
   _score02 = vScore[1];
   _score03 = vScore[2];
   _score04 = vScore[3];
   _score05 = vScore[4];
   _score06 = vScore[5];
   _score07 = vScore[6];
   _score08 = vScore[7];
   _score09 = vScore[8];
   _score10 = vScore[9];
   _score01->setVisible(false);
   _score02->setVisible(false);
   _score03->setVisible(false);
   _score04->setVisible(false);
   _score05->setVisible(false);
   _score06->setVisible(false);
   _score07->setVisible(false);
   _score08->setVisible(false);
   _score09->setVisible(false);
   _score10->setVisible(false);
}

void Top10Menu::setMenuVisible(){
   _bs->setVisible(true);
   _bt->setVisible(true);
   _bq->setVisible(true);
}

void Top10Menu::hideMenus(){
   _bs->setVisible(false);
   _bt->setVisible(false);
   _bq->setVisible(false);
}

void Top10Menu::copyToVector(std::vector<long int> vf)
{
   vValors.clear();
   for(int i = 0 ; i < (int)vf.size() ; i++)
      vValors.push_back(vf[i]);
}

void Top10Menu::passToLabels()
{
   std::stringstream ss1;
   ss1 << (vValors[0]);
   _score01->setString("01 - "+ ss1.str());  
   std::stringstream ss2;
   ss2 << (vValors[1]);
   _score02->setString("02 - "+ ss2.str());
   std::stringstream ss3;
   ss3 << (vValors[2]);
   _score03->setString("03 - "+ ss3.str());
   std::stringstream ss4;
   ss4 << (vValors[3]);
   _score04->setString("04 - "+ ss4.str());
   std::stringstream ss5;
   ss5 << (vValors[4]);
   _score05->setString("05 - "+ ss5.str());
   std::stringstream ss6;
   ss6 << (vValors[5]);
   _score06->setString("06 - "+ ss6.str());
   std::stringstream ss7;
   ss7 << (vValors[6]);
   _score07->setString("07 - "+ ss7.str());
   std::stringstream ss8;
   ss8 << (vValors[7]);
   _score08->setString("08 - "+ ss8.str());
   std::stringstream ss9;
   ss9 << (vValors[8]);
   _score09->setString("09 - "+ ss9.str());
   std::stringstream ss10;
   ss10 << (vValors[9]);
   _score10->setString("10 - "+ ss10.str());
}

void Top10Menu::showTop10Labels()
{
   _score01->setVisible(true);
   _score02->setVisible(true);
   _score03->setVisible(true);
   _score04->setVisible(true);
   _score05->setVisible(true);
   _score06->setVisible(true);
   _score07->setVisible(true);
   _score08->setVisible(true);
   _score09->setVisible(true);
   _score10->setVisible(true); 

   std::fstream p("Resources/top.bin", std::fstream::in | std::fstream::binary);
   vValors.clear();
   long int ax;

   for(int i = 0 ; i < 10 ; i++)
   {
      p >> ax;
      vValors.push_back(ax);
   }
   p.close();


   /*FILE*ap;
   ap = fopen("Resources/top.txt", "r");
   vValors.clear();
   long int ax;
   for(int i = 0 ; i < 10 ; i ++)
   {
   fscanf(ap,"%ld\n",&ax);
   vValors.push_back(ax);
   }
   fclose(ap);*/
   passToLabels();
}

std::vector<long int> Top10Menu::showTop10LabelsRetVet(){
   _score01->setVisible(true);
   _score02->setVisible(true);
   _score03->setVisible(true);
   _score04->setVisible(true);
   _score05->setVisible(true);
   _score06->setVisible(true);
   _score07->setVisible(true);
   _score08->setVisible(true);
   _score09->setVisible(true);
   _score10->setVisible(true);

   std::fstream p("Resources/top.bin", std::fstream::in | std::fstream::binary);
   vValors.clear();
   long int ax;

   for(int i = 0 ; i < 10 ; i++)
   {
      p >> ax;
      vValors.push_back(ax);
   }
   p.close();
   /*
   FILE*ap;
   ap = fopen("Resources/top.txt", "r");
   vValors.clear();
   long int ax;
   for(int i = 0 ; i < 10 ; i ++)
   {
   fscanf(ap,"%ld\n",&ax);
   vValors.push_back(ax);
   }
   fclose(ap);*/
   return vValors;
}



void Top10Menu::hideTop10Labels()
{
   _score01->setVisible(false);
   _score02->setVisible(false);
   _score03->setVisible(false);
   _score04->setVisible(false);
   _score05->setVisible(false);
   _score06->setVisible(false);
   _score07->setVisible(false);
   _score08->setVisible(false);
   _score09->setVisible(false);
   _score10->setVisible(false);

   std::fstream p("Resources/top.bin", std::fstream::out | std::fstream::binary);
   for(int i = 0 ; i < 10 ; i++)
   {
      p << vValors[i];
      p << "\n";
   }
   p.close();

   /*
   FILE*ap;
   ap = fopen("Resources/top.txt", "w");
   for(int i = 0 ; i < (int)vValors.size() ; i ++)
   {
   fprintf(ap,"%ld\n",vValors[i]);
   }
   fclose(ap);*/
}

RetButton::RetButton(Top10Menu *T_M) : scv::Button(scv::Point(600, 400),scv::Point(680, 420), "Return")
{setVisible(false);
_T_M = T_M;}

RetButton::~RetButton() {}

void RetButton::onMouseUp(const scv::MouseEvent& evt)
{
   if(isVisible())
   {
      _T_M->setMenuVisible();
      _T_M->hideTop10Labels();
      setVisible(false);
   }
}

void RetButton::show()
{
   _T_M->hideMenus();
   _T_M->showTop10Labels();
   setVisible(true);
}

void RetButton::showAG(long int points)
{
   std::vector<long int> v = _T_M->showTop10LabelsRetVet();
   std::vector<long int> vf;
   bool scored = false;
   for(int i = 0 ; i < (int)v.size() ; i++)
   {
      if(v[i] < points && !scored)
      {
         vf.push_back(points);
         vf.push_back(v[i]);
         scored = true;
      }else{
         vf.push_back(v[i]);
      }
   }
   if((int)vf.size() > 10){
      vf.pop_back();
   }

   _T_M->copyToVector(vf);
   _T_M->passToLabels();

   setVisible(true);
}
