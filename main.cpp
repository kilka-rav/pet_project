#include <iostream>
#include "draw.h"
#include <vector>

int main(int argc, char** argv) {
    int num_points = check_arguments(argc, argv);
    draw::init_window(WIDTH, HEIGHT);
    std::vector<draw::Point> main_points;
    init(main_points, num_points);
    while( draw::window_is_open() ) {
        draw::window_clear();
        draw::draw_surf(main_points);
        recalc(main_points);
        draw::check_event();
        draw::flush();   
    }
}