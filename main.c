#include <curses.h>
#include <stdio.h>

int
main()
{
  int main_ch_pos_x = 15;
  int main_ch_pos_y = 10;
  char main_character = '@';

  initscr();
  for(;;){
    keypad(stdscr, TRUE);

    mvaddch(main_ch_pos_y, main_ch_pos_x, main_character);
    int input = getch();

    /*movement*/
    if(input == KEY_LEFT){
      mvaddch(main_ch_pos_y, main_ch_pos_x, ' ');
      refresh();
     
      main_ch_pos_x -= 1;
      mvaddch(main_ch_pos_y, main_ch_pos_x, main_character);
    }

    if(input == KEY_RIGHT){
      mvaddch(main_ch_pos_y, main_ch_pos_x, ' ');
      refresh();

      main_ch_pos_x += 1;
      mvaddch(main_ch_pos_y, main_ch_pos_x, main_character);
    }

    if(input == KEY_UP){
      mvaddch(main_ch_pos_y, main_ch_pos_x, ' ');
      refresh();

      main_ch_pos_y -= 1;
      mvaddch(main_ch_pos_y, main_ch_pos_x, main_character);
    }
	
    if(input == KEY_DOWN){
      mvaddch(main_ch_pos_y, main_ch_pos_x, ' ');
      refresh();

      main_ch_pos_y += 1;
      mvaddch(main_ch_pos_y, main_ch_pos_x, main_character);
    }
    
  }
  endwin();
  return 0;
}
