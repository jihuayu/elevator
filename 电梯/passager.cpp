#include "stdafx.h"
istream & operator >>(istream & is, passager & c) {
  is >> c.time >> c.floor ;
  int num;
  is >> num;
  if (num == 0  ) {
    c.direction = 10;
  }
  else {
    c.direction = 1;
  }
  return is;
}

passager::passager()
{
  static int i = 0;
  id = i;
  isok = 0;
}
