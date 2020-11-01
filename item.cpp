#include "game.h"

void generate_item(){
  srand((unsigned) time(0)); // 항상 다른 난수
  int num_growth = rand() % 4;
  int num=0,tmpX=0,tmpY=0;

  while(num<3){
    tmpX = rand()%28+1;
    tmpY = rand()%28+1;

    if(map[stage_num][tmpY][tmpX] != 0)
      continue;

    if(num<num_growth){
      map[stage_num][tmpY][tmpX] = 5;
      refresh();
      num++;
      continue;
    }
    map[stage_num][tmpY][tmpX] = 6;
    refresh();
    num++;
  }
  refresh();
}
