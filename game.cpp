#include "window.cpp"
#include "snake.cpp"
#include "item.cpp"
#include "gate.cpp"

void game(){
  while(true){
    time_t start, end;
    Head_Direction = 1;
    set_zero();
    color();
    make_snake();
    nodelay(stdscr, true); //delay 없이 움직이게 하기
    while(true){
      // item, gate 초기화
      for(int i=0;i<30;i++){
        for(int j=0; j<30; j++){
          if(map[stage_num][i][j] == 5 || map[stage_num][i][j] == 6)  map[stage_num][i][j] = 0;
          if(map[stage_num][i][j] == 7)  map[stage_num][i][j] = 1;
        }
      }
      gate.clear();
      refresh();

      generate_item(); // item 생성
      generate_gate(); // gate 생성
      color();

      start = time(NULL);
      while(true){
        Head_Direction = set_Head_Direction(); // 방향설정
        Head_Direction = move_Snake();         // 방향에 따라 스네이크 움직이기
        color();
        score();

        usleep(200000);     // 1000000 = 1초
        end = time(NULL);
        if(stage_flag == 1) break;
        if(gate_posX == 0 && gate_posY == 0 && end-start > 10) break;
      }
      if(stage_flag == 1){
        break;
      }
    }
    if(stage_num == 4){
      NEXTGAME(2);
      break;
    }
    NEXTGAME(1);
  }
}
