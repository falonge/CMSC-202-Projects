//scented.h
#ifndef BIRTHDAY_H
#define BIRTHDAY_H
#include "Candle.h"

class Scented : public Candle{
  public:
  //constructor
  Scented(string name, double burnRate, string flavor);
  //Setter for isLit
  string SetLit(bool isLit);
  //Setter for flavor
  void SetFlavor(string flavor);
  //Getter for flavor
  string GetFlavor();
  protected:
    string m_flavor;
};

#endif

    

