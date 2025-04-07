#include <curses.h>

int
main()
{
  char character = '@';

  initscr(); //Инициализация либы
  addch(character);
  getch();
  

  endwin();
  
  return 0;
}
