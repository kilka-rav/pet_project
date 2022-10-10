#pragma once

#include <SFML/Graphics.hpp>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define WIDTH 400
#define HEIGHT 400

typedef struct _Point {
    int id;
    int num_main_points;
    int x_begin;
    int y_begin;
    int sum_x;
    int sum_y;
    int number_points;
    int color_r;
    int color_g;
    int color_b;
} Point;


int count_min_len(int x, int y, Point* points);
float distance(int x, int y, Point point);
void put_pixel(int x, int y, int r, int g, int b);
void flush();

extern "C" {
    int check_arguments(int argc, char** argv);
    int draw_rand();
    void draw_init_window(unsigned int width, unsigned int height);
    int draw_window_is_open();
}