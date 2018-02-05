// 电梯.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
int min(passager* people,int &time){
  int min = 10000;
  int num = 0;
  for (int i = 0;i < 5;i++) {
    if (people[i].isok == 0) {
      if (people->time < min) {
        min = people->time;
        num = i;
      }
    }
  }
  time = min;
  return num;
}

int main()
{
  elevator* lift=new elevator();
  passager* people = new passager[5];
  int time,id;
  for (int i = 0;i < 5;i++) {
    cin >> people[i];
  }
   while (++lift->nowtime){
    id = min(people, time);
    if (lift->nowtime-1 >= time) {
      while ((people[id].floor == lift->nowfloor)||(lift->nowfloor += (people[id].floor - lift->nowfloor) / abs((people[id].floor - lift->nowfloor)))&& ++lift->nowtime ){
       
        if (people[id].floor == lift->nowfloor) {
          lift->in(people[id]);
          break;
        }
      }
    }
    while (lift->isp[id]!=0&&lift->nowtime++) {
        lift->nowfloor += (people[id].direction - lift->nowfloor) / abs((people[id].direction - lift->nowfloor));
      if (lift->nowfloor == people[id].direction) {
        lift->out(people[id]);
        lift->nowtime++;
        break;
      }
    }
    cout << lift->alltime<<endl;getchar();
  } 
  getchar();
    return 0;
}

