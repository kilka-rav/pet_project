#include "draw.h"

#include <iostream>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

sf::RenderWindow window;
sf::Event event;

void draw_init_window(unsigned int width, unsigned int height) {
    window.create(sf::VideoMode(width, height), "Lloyd's Relaxation");
}

int draw_window_is_open() {
    window.clear();
    return window.isOpen();
}

int draw_rand() {
    return rand();
}

void put_pixel(int x, int y, int r, int g, int b) {
    sf::Color color(r, g, b);
    sf::Vertex point({static_cast<float>(x), static_cast<float>(y)}, color);
    window.draw(&point, 1, sf::Points);
}

void flush() {
    while ( window.pollEvent(event) ) {
        if ( event.type == sf::Event::Closed ) {
            window.close();
        }
    }
    window.display();
}

int count_min_len(int x, int y, Point* points) {
    int min_id = 0;
    int size = points[0].num_main_points;
    float min_len = distance(x, y, points[0]);
    for(int i = 1; i < size; ++i) {
        if ( min_len > distance(x, y, points[i])) {
            min_len = distance(x, y, points[i]);
            min_id = points[i].id;
        }
    }
    points[min_id].sum_x += x;
    points[min_id].sum_y += y;
    points[min_id].number_points++;
    return min_id;
}

float distance(int x, int y, Point point) {
    return ( x - point.x_begin ) * ( x - point.x_begin ) + ( y - point.y_begin ) * ( y - point.y_begin) ;
}

int check_arguments(int argc, char** argv) {
    if ( argc > 2 ) {
        fprintf(stderr, "Error in input: Wrong number of arguments\n");
        exit(1);
    }
    if ( argc == 1 ) {
        std::cout << "Init number of points 8" << std::endl;
        return 8;
    }
    int ret = atoi(argv[1]);
    if ( ret == 0 || ret >= WIDTH * HEIGHT ) {
        fprintf(stderr, "Error in input: Wrong number, try again!\n");
        exit(2);
    }
    fprintf(stderr, "Init number of points, %d\n", ret);
    return ret;
}