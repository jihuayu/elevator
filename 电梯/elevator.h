#pragma once
#include "stdafx.h"
#include "passager.h"
class elevator
{
public:
  int nowfloor;
  int nowtime;
  int to10;
  int to1;
  int i = 0;
  int isp[5];
  int alltime;
  elevator();
  ~elevator();
  void in(const passager );
  void out(const passager);

};

