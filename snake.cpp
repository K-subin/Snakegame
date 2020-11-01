#include "game.h"

// 스네이크 생성
void make_snake(){
  int snake_location[4][3][2] = {
    {{4, 23}, {6, 8}, {18, 16}},
    {{15, 14}, {21, 9}, {3, 18}},
    {{4, 15}, {27, 18}, {16, 15}},
    {{16, 15}, {6, 12}, {27, 17}}
  };

  if(stage_num > 0){
    for(int i=0; i<(int)snake.size()-1; i++){
      map[stage_num][snake[i].y][snake[i].x] = 0;
    }
    snake.clear();
    refresh();
  }

  srand((unsigned) time(0)); // 항상 다른 난수
  int a = rand()%3;
  for(int i=0; i<4; i++)
    snake.push_back(snakepart(snake_location[stage_num][a][1]+i, snake_location[stage_num][a][0]));

  map[stage_num][snake[0].y][snake[0].x] = 3;
  for(int i=1; i<4; i++)
    map[stage_num][snake[i].y][snake[i].x] = 4;
  refresh();
  color();
  getch();
}

//방향키 설정
int set_Head_Direction(){
  int key = getch();

  switch(key){
    case KEY_UP:
      // 반대 방향이면 gameover
      if(Head_Direction == 3){
        NEXTGAME(3);
        del_win();
        exit(0);
      }
      Head_Direction = 0;
      break;
    case KEY_LEFT:
      if(Head_Direction == 2){
        NEXTGAME(3);
        del_win();
        exit(0);
      }
      Head_Direction = 1;
      break;
    case KEY_RIGHT:
      if(Head_Direction == 1){
        NEXTGAME(3);
        del_win();
        exit(0);
      }
      Head_Direction = 2;
      break;
    case KEY_DOWN:
      if(Head_Direction == 0){
        NEXTGAME(3);
        del_win();
        exit(0);
      }
      Head_Direction = 3;
      break;
  }

  return Head_Direction;
}

int move_Snake(){
  // 스네이크 다음 이동 위치
  int move_posX = snake[0].x + head_way[Head_Direction][0];
  int move_posY = snake[0].y + head_way[Head_Direction][1];

  // growth item 먹을 때
  if(map[stage_num][move_posY][move_posX] == 5){
    // 머리 + 1
    Growth_item += 1;
    snake.insert(snake.begin(), snakepart(move_posX, move_posY));
    map[stage_num][snake[0].y][snake[0].x] = 3;
    map[stage_num][snake[1].y][snake[1].x] = 4;
    refresh();
  }

  // poison item 먹을 때
  else if(map[stage_num][move_posY][move_posX] == 6){
    // 머리 + 1, 꼬리 - 2
    if(snake.size() == 3){
      NEXTGAME(3);
      del_win();
      exit(0);
    }

    Poison_item += 1;
    map[stage_num][snake[snake.size()-1].y][snake[snake.size()-1].x] = 0;
    map[stage_num][snake[snake.size()-2].y][snake[snake.size()-2].x] = 0;
    snake.pop_back();
    snake.pop_back();
    snake.insert(snake.begin(), snakepart(move_posX, move_posY));
    map[stage_num][snake[0].y][snake[0].x] = 3;
    map[stage_num][snake[1].y][snake[1].x] = 4;
    refresh();
  }

  // 게이트를 만났을 때
  else if(collision_gate() == 7){
    Head_Direction = pass_the_gate();

    gate_posX = gate[gate[2].y].x + head_way[Head_Direction][0];
    gate_posY = gate[gate[2].y].y + head_way[Head_Direction][1];

    map[stage_num][snake[snake.size()-1].y][snake[snake.size()-1].x] = 0;
    snake.pop_back();
    snake.insert(snake.begin(), snakepart(gate_posX, gate_posY));
    map[stage_num][snake[0].y][snake[0].x] = 3;
    map[stage_num][snake[1].y][snake[1].x] = 4;
    refresh();
  }

  //벽을 만났을 때
  else if(map[stage_num][move_posY][move_posX] == 1){
    NEXTGAME(3);
    del_win();
    exit(0);
  }

  // 아무것도 만나지 않을 때
  else{
    // 스네이크 전체가 gate를 다 통과했을 때
    if(snake[snake.size()-1].x == gate_posX && snake[snake.size()-1].y == gate_posY){
      map[stage_num][gate[0].y][gate[0].x] = 1;
      map[stage_num][gate[1].y][gate[1].x] = 1;
      gate_posX = 0; gate_posY = 0;
      Gate_cnt += 1;
      gate.clear();
      refresh();
    }

    // 머리 + 1, 꼬리 - 1
    map[stage_num][snake[snake.size()-1].y][snake[snake.size()-1].x] = 0;
    snake.pop_back();
    snake.insert(snake.begin(), snakepart(move_posX, move_posY));
    map[stage_num][snake[0].y][snake[0].x] = 3;
    map[stage_num][snake[1].y][snake[1].x] = 4;
    refresh();
  }

  return Head_Direction;
}
