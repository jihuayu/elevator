#pragma once
#include<iostream>
using namespace std;
class passager
{
public:
  int id;
  int isok;
  int floor;
  int direction;
  int time;
  int goal;

  passager();
  ~passager();

  void call(int);
  int in_out(int,int);
  friend istream & operator >>(istream &, passager &);
};

