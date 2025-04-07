#include <curses.h>

int
main()
{
  char main_character = '@';

  initscr(); //Инициализация либы
  addch(main_character);
  getch();
  

  endwin();
  
  return 0;
}
