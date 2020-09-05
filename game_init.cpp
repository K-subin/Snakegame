#include "game.h"
#include "map.h"

void color_init(){
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
