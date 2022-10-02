#include "draw.h"
#include <stdlib.h>

sf::RenderWindow window;
sf::Event event;

void draw::init_window(unsigned int width, unsigned int height) {
    window.create(sf::VideoMode(width, height), "Lloyd's Relaxation");
}

bool draw::window_is_open() {
    return window.isOpen();
}

void draw::window_clear() {
    window.clear();
}

void draw::check_event() {
    while ( window.pollEvent(event) ) {
        if ( event.type == sf::Event::Closed ) {
            window.close();
        }
    }
}


void draw::draw_surf(std::vector<draw::Point>& points) {
    for(int y = 0; y < HEIGHT; ++y) {
        for(int x = 0; x < WIDTH; ++x) {
            int min_id = count_min_len(x, y, points);
            draw::draw_pixel(x, y, points[min_id].get_color());
        }
    }
}

void draw::draw_pixel(int x, int y, sf::Color color) {
    sf::Vertex point({static_cast<float>(x), static_cast<float>(y)}, color);
    window.draw(&point, 1, sf::Points);
}

void draw::flush() {
    window.display();
}

draw::Point::Point(int _id, int num) {
    id = _id;
    x_begin = std::rand() % WIDTH;
    y_begin = std::rand() % HEIGHT;
    int colour = static_cast<int>(255 * (_id + 1) / num );
    std::cout << "id = " << id << "Point: " << x_begin << " " << y_begin << " col: " << colour << std::endl;
    color = sf::Color(colour, x_begin + colour / 2, y_begin - colour / 2);
}

int draw::Point::get_x() const {
    return x_begin;
}

int draw::Point::get_y() const {
    return y_begin;
}

int draw::Point::get_id() const {
    return id;
}

sf::Color draw::Point::get_color() const {
    return color;
}

void draw::Point::set_new_coordinates(int x, int y) {
    x_begin = x;
    y_begin = y;
    number = 0;
    sum_x = 0;
    sum_y = 0;
}

void init(std::vector<draw::Point>& points, int num_points) {
    std::srand(std::time(nullptr));
    for(int i = 0; i < num_points; ++i) {
        draw::Point local(i, num_points);
        points.push_back(local);
    }
}

void recalc(std::vector<draw::Point>& points) {
    for( int i = 0; i < points.size(); ++i ) {
        int x_new = points[i].sum_x / points[i].number;
        int y_new = points[i].sum_y / points[i].number;
        points[i].set_new_coordinates(x_new, y_new);
    }
}

int count_min_len(int x, int y, std::vector<draw::Point>& points) {
    int min_id = 0;
    float min_len = distance(x, y, points[0]);
    for(int i = 1; i < points.size(); ++i) {
        if ( min_len > distance(x, y, points[i])) {
            min_len = distance(x, y, points[i]);
            min_id = points[i].get_id();
        }
    }
    points[min_id].sum_x += x;
    points[min_id].sum_y += y;
    points[min_id].number++;
    return min_id;
}

float distance(int x, int y, draw::Point& point) {
    return ( x - point.get_x() ) * ( x - point.get_x() ) + ( y - point.get_y() ) * ( y - point.get_y());
}

int check_arguments(int argc, char** argv) {
    if ( argc > 2 ) {
        std::cerr << "Error in input: Wrong number of arguments" << std::endl;
        exit(1);
    }
    if ( argc == 1 ) {
        std::cout << "Init number of points 8" << std::endl;
        return 8;
    }
    int ret = std::atoi(argv[1]);
    if ( ret == 0 || ret >= WIDTH * HEIGHT ) {
        std::cerr << "Error in input: Wrong number, try again!" << std::endl;
        exit(2);
    }
    std::cout << "Init number of points " << ret << std::endl;
    return ret;
}