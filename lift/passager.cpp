#include "stdafx.h"
#include "passager.h"


passager::passager()
{
  static int i = 0;
  id = i;
  isok = 0;
  goal = 0;
  i++;
}


passager::~passager()
{
}
int passager::in_out(int liftfloor,int nowtime) {
  int costtime=0;
  if (goal == liftfloor) {
    if (isok == 0) {
      isok = 1;
      goal = direction;
      costtime = -1;
    }
  }
  if (goal == liftfloor) {
    if (isok == 1) {
      isok = 2;
      goal = 0;
      costtime = nowtime - time;
    }
  }
  return costtime;
}

void passager::call(int nowtime) {
  if (nowtime >= time&&isok==0) {
    
    goal=floor;
  }
  else if(nowtime >= time && isok == 1){
    goal = direction;
  }
  else {
    goal = 0;
  }
}

istream & operator >>(istream & is, passager & c) {
  is >> c.time >> c.floor >> c.direction;
  c.goal = 0;
  return is;
}