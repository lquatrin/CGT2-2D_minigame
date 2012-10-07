#include "Input.hpp"
#include <map>

Input::Input() 
{
   keyboard.insert ( std::pair<char,bool>('i',false) );
   keyboard.insert ( std::pair<char,bool>('k',false) );
   keyboard.insert ( std::pair<char,bool>('l',false) );
   keyboard.insert ( std::pair<char,bool>('j',false) );
   keyboard.insert ( std::pair<char,bool>('u',false) );
   keyboard.insert ( std::pair<char,bool>('o',false) );
   keyboard.insert ( std::pair<char,bool>('z',false) );
   keyboard.insert ( std::pair<char,bool>('x',false) );
   keyboard.insert ( std::pair<char,bool>('c',false) );
   keyboard.insert ( std::pair<char,bool>('v',false) );
   keyboard.insert ( std::pair<char,bool>('q',false) );
}
Input::~Input() {}

void Input::reset()
{
   keyboard['i'] = false;
   keyboard['k'] = false;
   keyboard['l'] = false;
   keyboard['j'] = false;
   keyboard['u'] = false;
   keyboard['o'] = false;
   keyboard['z'] = false;
   keyboard['x'] = false;
   keyboard['c'] = false;
   keyboard['v'] = false;
   keyboard['q'] = false;
}
