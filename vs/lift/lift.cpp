#include "stdafx.h"
#include <fstream> 

using namespace std;
//给所有乘客按时间请求时间从小到大排序

static ifstream in("./input.txt");
static ofstream out("./output.txt");

void min(passager* people) {
  int min = 10000;
  int num = 0;
  passager a;
  for (int i = 0;i < 5;i++) {
    for (int j = i;j<5;j++) {
      if (people[i].time>people[j].time) {
        a = people[i];people[i] = people[j];people[j] = a;
        num = people[i].id;people[i].id = people[j].id;people[j].id = num;
      }
    }
  }
}
//更新乘客请求状态
void iscall(passager* people, int nowtime) {
  for (int i = 0;i < 5;i++) {
    people[i].call(nowtime);
  }
}
//更新乘客搭乘状态
bool isopen(passager* people, int liftfloor, int nowtime,int & sumtime) {
  bool isopen = 0;
  for (int i = 0;i < 5;i++) {
    int cost = people[i].in_out(liftfloor, nowtime);
    if (cost == -1) {
      isopen = 1;
    }
    else if(cost > 0){
      sumtime += cost;
      //cout << sumtime << endl;
      isopen = 1;
    }
  }
  return isopen;
}
//选择最优的电梯目的地
int choice(passager* people, int liftfloor) {
  int mincost=10000000;
  int id=-1;
  for (int i = 0;i < 5;i++) {
   
    int liftgoal = people[i].goal;
    if (!liftgoal) {
      continue;
    }
    int cost = 0;
    for (int j = 0;j < 5;j++) {
      if (liftgoal <= people[i].goal&&liftfloor >= people[i].goal || liftgoal >= people[i].goal&&liftfloor <= people[i].goal) {
        cost+=abs(liftgoal-liftfloor);
      }
      else if (people[i].goal) {
        cost+=2* abs(liftgoal - liftfloor);
      }
    }
    if (cost < mincost) {
      id = i;
    }
  }
  return id;
}
//判断是否所有的乘客请求全部完成
bool isall(passager * people) {
  for (int i = 0;i < 5;i++) {
    if (people[i].isok != 2) {
      return 0;
    }
  }
  return 1;
}

int main()
{
  int liftgoal = 0;
  int nowtime = 0;
  int liftfloor = 1;
  int goalid = 0;
  int sumtime = 0;
  passager* people = new passager[5];
  //输入
  for (int i = 0;i < 5;i++) {
    in >> people[i].time >>people[i].floor>>people[i].direction;
  }
  //排序
  min(people);
  while (1) {
    iscall(people, nowtime);
    goalid = choice(people, liftfloor);
    if (goalid == -1) {
      liftgoal = 0;
    }
    else {
      liftgoal = people[goalid].goal;
    }
    if (!liftgoal) {
      //没有请求，进行等待
      nowtime++;
    }
    else {  
      //判断是否开门
      if (isopen(people, liftfloor, nowtime, sumtime)) {
         nowtime++;
		 //输出开门时间
         out <<"在"<< nowtime<<"时刻，电梯在" << liftfloor << "打开了门" << endl;
      }
      if (liftfloor != liftgoal) {
        //向目标移动
        liftfloor += (liftgoal - liftfloor) / abs(liftgoal - liftfloor);
        nowtime++;
      }
    }
    if (isall(people)) {
      break;
    }
    
}
  out << "总等待时间"<<sumtime << endl;
  return 0;
}

