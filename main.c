#include <curses.h>
#include <stdlib.h>
#include <time.h>

#define MAP_WIDTH 40
#define MAP_HEIGHT 20

typedef enum {
    EMPTY = ' ',
    TREE = 'T',
    ROCK = '#',
    PLAYER = '@'
} CellType;

CellType map[MAP_HEIGHT][MAP_WIDTH];
WINDOW *map_win;
int player_x, player_y;

void generate_map() {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            map[y][x] = EMPTY;
        }
    }
    
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (rand() % 100 < 25) map[y][x] = TREE;
        }
    }
    
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (map[y][x] == EMPTY && rand() % 100 < 10) {
                map[y][x] = ROCK;
            }
        }
    }
    
    do {
        player_x = rand() % MAP_WIDTH;
        player_y = rand() % MAP_HEIGHT;
    } while (map[player_y][player_x] != EMPTY);
}

void draw_map() {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (x == player_x && y == player_y) {
                mvwaddch(map_win, y + 1, x + 1, PLAYER);
            } else {
                mvwaddch(map_win, y + 1, x + 1, map[y][x]);
            }
        }
    }
    wrefresh(map_win);
}

int can_move_to(int x, int y) {
    if (x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT) return 0;
    return map[y][x] == EMPTY;
}

WINDOW *create_map_win(int height, int width, int starty, int startx) {
    WINDOW *win = newwin(height, width, starty, startx);
    box(win, 0, 0);
    return win;
}

int main() {
    srand(time(NULL));
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    generate_map();
    
    int win_height = MAP_HEIGHT + 2;
    int win_width = MAP_WIDTH + 2;
    int starty = (LINES - win_height) / 2;
    int startx = (COLS - win_width) / 2;
    
    map_win = create_map_win(win_height, win_width, starty, startx);
    
    while(1) {
        draw_map();
        int input = getch();
        
        int new_x = player_x;
        int new_y = player_y;
        
        switch(input) {
            case KEY_LEFT:  new_x--; break;
            case KEY_RIGHT: new_x++; break;
            case KEY_UP:    new_y--; break;
            case KEY_DOWN: new_y++; break;
            case 27:        endwin(); return 0;
        }
        
        if (can_move_to(new_x, new_y)) {
            player_x = new_x;
            player_y = new_y;
        }
    }
    
    endwin();
    return 0;
}
