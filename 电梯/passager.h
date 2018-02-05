#pragma once
#include "stdafx.h"
using namespace std;
class passager
{
public:
  int id;
  int time;
  int floor;
  int direction;
  bool isok;

  passager();

  friend istream & operator >>(istream &, passager &);
  
};

