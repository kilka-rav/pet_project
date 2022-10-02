#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#define WIDTH 400
#define HEIGHT 400

namespace draw {
    class Point {
        private:
            sf::Color color;
            int id;
            int x_begin;
            int y_begin;
        public:
            Point(int _id, int num);
            int get_x() const;
            int get_y() const;
            int get_id() const;
            void set_new_coordinates(int x, int y);
            sf::Color get_color() const;
            int sum_x = 0;
            int sum_y = 0;
            int number = 0;
    };

    void init_window(unsigned int width, unsigned int height);
    bool window_is_open();
    void window_clear();
    void check_event();
    void draw_surf(std::vector<draw::Point>& points);
    void draw_pixel(int x, int y, sf::Color color);
    void flush();


} //namespace draw

void init(std::vector<draw::Point>& points, int num_points);
void recalc(std::vector<draw::Point>& vec);
int check_arguments(int argc, char** argv);
int count_min_len(int x, int y, std::vector<draw::Point>& points);
float distance(int x, int y, draw::Point& point);

extern "C" {
    void init_window(unsigned int width, unsigned int height);
    void init_table(int num_points);
    int window_is_open();
    void draw_surf();
    void recalc();
    void flush();
    void check_event();
    void window_clear();
}