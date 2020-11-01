#include "game.h"

void color_init(){
  // 글씨 배경 순서
  init_color(COLOR_GRAY, 150, 150, 150);      // 회색으로 설정
  init_pair(1, COLOR_GRAY, COLOR_GRAY);       // Wall
  init_color(COLOR_BLACK_A, 0, 0, 0);         // 검은색으로 설정
  init_pair(2, COLOR_BLACK_A, COLOR_BLACK_A); // Immune Wall
  init_pair(3, COLOR_CYAN, COLOR_CYAN);       // Snake Head
  init_pair(4, COLOR_BLUE, COLOR_BLUE);       // Snake Body
  init_pair(5, COLOR_GREEN, COLOR_GREEN);     // Growth Item
  init_pair(6, COLOR_RED, COLOR_RED);         // Poison Item
  init_pair(7, COLOR_YELLOW, COLOR_YELLOW);   // Gate
  init_pair(8, COLOR_WHITE, COLOR_WHITE);     // Blank
}

void color(){
  for(int i=0; i<30; i++){
    for(int j=0; j<30; j++){
      // 직사각형 모양인데 색 O
      if(map[stage_num][i][j] == 0){
        wattron(win1, COLOR_PAIR(8));
        mvwprintw(win1, i, j, "%d", map[stage_num][i][j]);
        wattroff(win1, COLOR_PAIR(8));
      }

      else if(map[stage_num][i][j] == 1){
        wattron(win1, COLOR_PAIR(1));
        mvwprintw(win1, i, j, "%d", map[stage_num][i][j]);
        wattroff(win1, COLOR_PAIR(1));
      }

      else if(map[stage_num][i][j] == 2){
        wattron(win1, COLOR_PAIR(2));
        mvwprintw(win1, i, j, "%d", map[stage_num][i][j]);
        wattroff(win1, COLOR_PAIR(2));
      }

      else if(map[stage_num][i][j] == 3){
        wattron(win1, COLOR_PAIR(3));
        mvwprintw(win1, i, j, "%d", map[stage_num][i][j]);
        wattroff(win1, COLOR_PAIR(3));
      }

      else if(map[stage_num][i][j] == 4){
        wattron(win1, COLOR_PAIR(4));
        mvwprintw(win1, i, j, "%d", map[stage_num][i][j]);
        wattroff(win1, COLOR_PAIR(4));
      }

      else if(map[stage_num][i][j] == 5){
        wattron(win1, COLOR_PAIR(5));
        mvwprintw(win1, i, j, "%d", map[stage_num][i][j]);
        wattroff(win1, COLOR_PAIR(5));
      }

      else if(map[stage_num][i][j] == 6){
        wattron(win1, COLOR_PAIR(6));
        mvwprintw(win1, i, j, "%d", map[stage_num][i][j]);
        wattroff(win1, COLOR_PAIR(6));
      }

      else if(map[stage_num][i][j] == 7){
        wattron(win1, COLOR_PAIR(7));
        mvwprintw(win1, i, j, "%d", map[stage_num][i][j]);
        wattroff(win1, COLOR_PAIR(7));
      }
    }
  }
  wrefresh(win1);
}

void score(){
  // Body_length, Growth_item, Poison_item, Gate_cnt
  //int goal[4][4] = {{5, 2, 1, 1}, {10, 4, 2, 2}, {15, 6, 4, 3}, {15, 6, 5, 4}};
  int goal[4][4] = {{5, 1, 1, 1}, {5, 1, 1, 1}, {5, 1, 1, 1}, {5, 1, 1, 1}};

  // 목표 점수 표시
  wborder(win2, '|', '|', '-', '-', '+', '+', '+', '+');
  mvwprintw(win2, 1, 6, "*Mission*");
  mvwprintw(win2, 3, 8, "B : %d", goal[stage_num][0]);
  mvwprintw(win2, 5, 8, "+ : %d", goal[stage_num][1]);
  mvwprintw(win2, 7, 8, "- : %d", goal[stage_num][2]);
  mvwprintw(win2, 9, 8, "G : %d", goal[stage_num][3]);

  int size = snake.size();
  int current_size = snake.size();
  Body_length = max(size, Body_length); // max_size

  // 점수 표시
  wborder(win3, '|', '|', '-', '-', '+', '+', '+', '+');
  mvwprintw(win3, 1, 7, "*Score*");
  mvwprintw(win3, 3, 2, "B : %d / %d", current_size, Body_length);  // current / max
  mvwprintw(win3, 5, 2, "+ :   %d   ", Growth_item);
  mvwprintw(win3, 7, 2, "- :   %d   ", Poison_item);
  mvwprintw(win3, 9, 2, "G :   %d   ", Gate_cnt);

  // Body_length, 즉 stage 내 max_size가 목표 점수보다 크면 V 표시, 아니면 빈 칸
  if(Body_length < goal[stage_num][0])  mvwprintw(win3, 3, 14, "(   )");
  else  mvwprintw(win3, 3, 14, "( V )");

  // 한 stage에서 목표 점수만큼 아이템을 먹었을 경우 V 표시, 아니면 빈 칸
  if(Growth_item < goal[stage_num][1])  mvwprintw(win3, 5, 14, "(   )");
  else  mvwprintw(win3, 5, 14, "( V )");

  // 한 stage에서 목표 점수만큼 아이템을 먹었을 경우 V 표시, 아니면 빈 칸
  if(Poison_item < goal[stage_num][2])  mvwprintw(win3, 7, 14, "(   )");
  else  mvwprintw(win3, 7, 14, "( V )");

  // 한 stage에서 목표 점수만큼 gate를 지났을 경우 V 표시, 아니면 빈 칸
  if(Gate_cnt < goal[stage_num][3]) mvwprintw(win3, 9, 14, "(   )");
  else  mvwprintw(win3, 9, 14, "( V )");

  if((Body_length >= goal[stage_num][0]) && (Growth_item >= goal[stage_num][1]) &&
     (Poison_item >= goal[stage_num][2]) && (Gate_cnt >= goal[stage_num][3])){
       stage_num++;
       stage_flag = 1;
  }

  wrefresh(win2);
  wrefresh(win3);
}

void set_zero(){
  stage_flag = 0;
  Body_length = 0;
  Growth_item = 0;
  Poison_item = 0;
  Gate_cnt = 0;
  gate_posX = 0;
  gate_posY = 0;
}

void NEXTGAME(int num){
  wclear(win1);
  if(num == 1){
    mvwprintw(win1, 10, 24, "★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★");
    mvwprintw(win1, 11, 24, "★      STAGE CLEAR      ★");
    mvwprintw(win1, 12, 24, "★        ٩( ᐛ )و        ★");
    mvwprintw(win1, 13, 24, "★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★");
  }
  else if(num == 2){
    mvwprintw(win1, 10, 24, "★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★");
    mvwprintw(win1, 11, 24, "★     STAGE ALL CLEAR   ★");
    mvwprintw(win1, 12, 24, "★       ( ღ 'ᴗ'ღ )      ★");
    mvwprintw(win1, 13, 24, "★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★ ★");
  }
  else if(num == 3){
    mvwprintw(win1, 10, 28, "+ - - - - - - - - - - - +");
    mvwprintw(win1, 11, 28, "|    G A M E O V E R    |");
    mvwprintw(win1, 12, 28, "|        ( ಥ﹏ಥ)        |");
    mvwprintw(win1, 13, 28, "+ - - - - - - - - - - - +");
  }
  wrefresh(win1);
  nodelay(stdscr, false);
  getch();
  wclear(win1);
}

void del_win(){
  delwin(win3);
  delwin(win2);
  delwin(win1);
  endwin();
}
