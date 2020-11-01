#pragma once

#include <ncurses.h>
#include <vector>
#include <locale.h>
#include <cstdlib>
#include <unistd.h>
#include <time.h>
#include <string>
#include "map.h"

using namespace std;

// 필요한 색 정의
#define COLOR_GRAY 8
#define COLOR_BLACK_A 9

WINDOW *win1, *win2, *win3;
void color_init();
void color();
void score();
void set_zero();
void del_win();
void make_snake();
int set_Head_Direction();
int move_Snake();
void generate_item();
int collision_gate();
void generate_gate();
int pass_the_gate();
void NEXTGAME(int num);
void game();
int head_way[4][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
int Head_Direction, Body_length, Growth_item, Poison_item, Gate_cnt, gate_posX, gate_posY;
int stage_num=0, stage_flag=0;


struct snakepart{
  int x, y;
  snakepart(int col, int row);
  snakepart();
};
snakepart::snakepart(int col, int row){
  x=col;
  y=row;
}
snakepart::snakepart(){
  x=0;
  y=0;
}

vector<snakepart> snake;
vector<snakepart> gate;
