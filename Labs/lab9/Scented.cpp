#include "Scented.h"

Scented :: Scented(string name, double burnRate, string flavor) : Candle(name, burnRate)
{
  m_flavor = flavor;
}

string Scented :: GetFlavor(){
  return m_flavor;
}

void Scented :: SetFlavor(string flavor){
  m_flavor = flavor;
}

//Prints different messages based on which flavor the candle is set to
string Scented :: SetLit(bool isLit){
  m_isLit = true;
  if(m_flavor == "Hotdogs"){
    cout << "The delicious smell of Hotdogs wafts from the scented candle.\n";
    return "Yes";
  }
  if(m_flavor == "Candy Corn"){
    cout << "The delicious smell of Candy Corn wafts from the scented candle.\n";
    return "Yes";
  }
  return "No";
}
