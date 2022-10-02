#include "draw.h"


int main(int argc, char** argv) {
    int num_points = check_arguments(argc, argv);
    init_window(WIDTH, HEIGHT);
    init_table(num_points);
    while( window_is_open() ) {
        window_clear();
        draw_surf();
        recalc();
        check_event();
        flush();   
    }
}