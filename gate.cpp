#include "game.h"

//gate 충돌
int collision_gate(){
  //스네이크가 gate[0]으로 진입
  int in, out;
  if(snake[0].x == gate[0].x && snake[0].y == gate[0].y){
    in = 0; out = 1;
    gate.push_back(snakepart(in, out));
    return 7;
  }
  //스네이크가 gate[1]로 진입
  else if(snake[0].x == gate[1].x && snake[0].y == gate[1].y){
    in = 1; out = 0;
    gate.push_back(snakepart(in, out));
    return 7;
  }

  return 0;
}

void generate_gate(){
  srand((unsigned) time(0)); // 항상 다른 난수

  int x1=0, y1=0, x2=0, y2=0;
  while(map[stage_num][y1][x1] != 1){
    x1 = rand()%30;
    y1 = rand()%30;
    if(map[stage_num][y1-1][x1] == 2 || map[stage_num][y1+1][x1] == 2 || map[stage_num][y1][x1-1] == 2 || map[stage_num][y1][x1+1] == 2){
      x1 = 0, y1 = 0;
    }
  }
  while(map[stage_num][y2][x2] != 1){
    x2 = rand()%30;
    y2 = rand()%30;
    if(map[stage_num][y2-1][x2] == 2 || map[stage_num][y2+1][x2] == 2 || map[stage_num][y2][x2-1] == 2 || map[stage_num][y2][x2+1] == 2){
      x2 = 0, y2 = 0;
    }
  }
  map[stage_num][y1][x1] = 7;
  map[stage_num][y2][x2] = 7;

  gate.push_back(snakepart(x1,y1));
  gate.push_back(snakepart(x2,y2));
  refresh();
}

int pass_the_gate(){
  int out = gate[2].y;

  //진출 gate가 가장자리에 있을 때
  if(gate[out].x == 0 || gate[out].x == 29 || gate[out].y == 0 || gate[out].y == 29){
    if(gate[out].x == 0) // 왼쪽 벽
      Head_Direction = 2; // 오른쪽 방향
    else if(gate[out].x == 29) // 오른쪽 벽
      Head_Direction = 1; // 왼쪽 방향
    else if(gate[out].y == 0) // 위쪽 벽
      Head_Direction = 3; // 아래 방향
    else // 아래 벽
      Head_Direction = 0; //위쪽 방향
  }

  else{
    // 진출방향이 위-아래
    if(map[stage_num][gate[out].y-1][gate[out].x] != 1 || map[stage_num][gate[out].y+1][gate[out].x] != 1){
      if(Head_Direction == 0 || Head_Direction == 1) // 진입방향이 위 또는 왼쪽
        Head_Direction = 0;
      else // 진입방향이 아래 또는 오른쪽
        Head_Direction = 3;
    }
    // 진출방향이 좌-우
    else{
      if(Head_Direction == 0 || Head_Direction == 1) // 진입방향이 위 또는 왼쪽
        Head_Direction = 1;
      else // 진입방향이 아래 또는 오른쪽
        Head_Direction = 2;
    }
  }

  return Head_Direction;
}
