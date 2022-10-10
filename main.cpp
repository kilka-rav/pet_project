#include "draw.h"


void init_table(Point* points, int num_points) {
    srand(time(NULL));
    for(int i = 0; i < num_points; ++i) {
        points[i].id = i;
        points[i].num_main_points = num_points;
        points[i].sum_x = 0;
        points[i].sum_y = 0;
        points[i].number_points = 0;
        points[i].x_begin = draw_rand() % WIDTH;
        points[i].y_begin = draw_rand() % HEIGHT;
        points[i].color_r = 255 * (i + 1) / num_points;
        points[i].color_g = points[i].x_begin + points[i].color_r / 2;
        points[i].color_b = points[i].x_begin - points[i].color_g / 2;
    }
}

void surf(Point* points) {
    for(int y = 0; y < HEIGHT; ++y) {
        for(int x = 0; x < WIDTH; ++x) {
            int min_id = count_min_len(x, y, points);   //change
            put_pixel(x, y, points[min_id].color_r, points[min_id].color_g, points[min_id].color_b);                    //add
        }
    }
}

void recalc(Point* points, int num_points) {
    for(int i = 0; i < num_points; ++i) {
        points[i].x_begin = points[i].sum_x / points[i].number_points;
        points[i].y_begin = points[i].sum_y / points[i].number_points;
        points[i].sum_x = 0;
        points[i].sum_y = 0;
        points[i].number_points = 0;
    }
}


int main(int argc, char** argv) {
    int num_points = check_arguments(argc, argv);
    Point* points = (Point*) malloc(sizeof(Point) * num_points);
    draw_init_window(WIDTH, HEIGHT);
    init_table(points, num_points);
    while( draw_window_is_open() ) {
        surf(points);
        recalc(points, num_points);
        flush();   
    }
    free(points);
}