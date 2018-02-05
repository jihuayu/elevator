#include "stdafx.h"
elevator::elevator()
{
  nowfloor = 1;
  nowtime = 0;
  to10 = 0;
  to1 = 0;
  alltime = 0;
  memset(isp, 0, sizeof(isp));
}
void elevator::in(const passager people) {
  isp[people.id] = 1;
}
void elevator::out(const passager people) {
  isp[people.id] = 0;
  alltime += (nowtime - people.time);

}

elevator::~elevator()
{
}
