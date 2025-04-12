#include <curses.h>
#include <stdio.h>

WINDOW *create_newwin(int height, int width, int starty, int startx);

int
main()
{
  char main_character = '@';

  WINDOW *my_win;
  int startx, starty, width, height;

  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(2);

  int main_ch_pos_x = COLS / 2;
  int main_ch_pos_y = LINES / 2;
  
  height = LINES - 4;
  width = COLS - 15;
  starty = (LINES - height) / 2;
  startx = (COLS - width) / 2;

 
  
  for(;;){
    my_win = create_newwin(height, width, starty, startx);  
    mvaddch(main_ch_pos_y, main_ch_pos_x, main_character);
    move(main_ch_pos_y, main_ch_pos_x);
    int input = getch();

    /*movement*/
    if(input == KEY_LEFT){
      mvaddch(main_ch_pos_y, main_ch_pos_x, ' ');
      refresh();
     
      main_ch_pos_x -= 1;
      mvaddch(main_ch_pos_y, main_ch_pos_x, main_character);
      move(main_ch_pos_y, main_ch_pos_x);
    }

    if(input == KEY_RIGHT){
      mvaddch(main_ch_pos_y, main_ch_pos_x, ' ');
      refresh();

      main_ch_pos_x += 1;
      mvaddch(main_ch_pos_y, main_ch_pos_x, main_character);
      move(main_ch_pos_y, main_ch_pos_x);
    }

    if(input == KEY_UP){
      mvaddch(main_ch_pos_y, main_ch_pos_x, ' ');
      refresh();

      main_ch_pos_y -= 1;
      mvaddch(main_ch_pos_y, main_ch_pos_x, main_character);
       move(main_ch_pos_y, main_ch_pos_x);
    }
	
    if(input == KEY_DOWN){
      mvaddch(main_ch_pos_y, main_ch_pos_x, ' ');
      refresh();

      main_ch_pos_y += 1;
      
      mvaddch(main_ch_pos_y, main_ch_pos_x, main_character);
      move(main_ch_pos_y, main_ch_pos_x);
    }

    if(input == 27)
      break;
    
  }
  endwin();
  return 0;
}

WINDOW *create_newwin(int height, int width, int starty, int startx) {
  WINDOW *local_win;

  local_win = newwin(height, width, starty, startx);
  box(local_win, 0, 0);

  wrefresh(local_win);
  
  return local_win;
}
