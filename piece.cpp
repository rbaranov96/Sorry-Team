//
// Created by Robert Baranov on 4/2/18.
//

#include "piece.h"
#include "graphics.h"

Shape::Shape() {
    // default color: black
    fill = {0, 0, 0};
    position = {0, 0};
}

Shape::Shape(hue f) : Shape() {
    fill = f;
}

Shape::Shape(xy_position p) : Shape() {
    set_position(p);
}

Shape::Shape(hue f, xy_position p) : Shape(f) {
        set_position(p);
}

Shape::Shape(hue f, int x_in, int y_in) : Shape(f) {
        set_position(x_in, y_in);
}

Shape::Shape(double x_in, double y_in) : Shape() {
    set_position(x_in, y_in);
}

Shape::Shape(const Shape &s) : fill(s.fill) {
}

Shape::~Shape() {
    // does nothing
}
string Shape::get_color() const {
    return color;
}

double Shape::get_area() const {
    return calculate_area();
}

double Shape::get_perimeter() const {
    return calculate_perimeter();
}

hue Shape::get_fill() const {
    return fill;
}

xy_position Shape::get_position() const {
    return position;
}

double Shape::get_x() const {
    return position.x;
}

double Shape::get_y() const {
    return position.y;
}
void Shape::set_color(string piece_color) {
    color = piece_color;
}

void Shape::set_fill(hue f) {
fill = f;
}

void Shape::set_fill(double r, double g, double b) {
    fill = {r, g, b};
}

void Shape::set_position(xy_position p) {
    position = p;
}

void Shape::set_position(double x_in, double y_in) {
    position = {x_in, y_in};
}

void Shape::move(int delta_x, int delta_y) {
    // Note: if delta_x is negative, this will
    // in effect subtract from the x position.
    position.x += delta_x;
    // Note: if delta_y is negative, this will
    // in effect subtract from the y position.
    position.y += delta_y;
}

Piece::Piece() : Shape(), radius(0) {
}

Piece::Piece(double r) : Shape() {
    set_radius(r);
}

Piece::Piece(double r, hue f) : Shape(f) {
    set_radius(r);
}

Piece::Piece(hue f) : Shape(f), radius(0) {
}

Piece:: ~Piece() {
    // does nothing
}

double Piece::get_radius() const {
    return radius;
}

void Piece::set_radius(double r) {
    if (r < 0) {
        radius = 0;
    } else {
        radius = r;
    }
}

void Piece::draw() const {

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(fill.red, fill.green, fill.blue);
    glVertex2i(position.x, position.y);
    for (double i = 0; i <= 2.0*M_PI+0.05; i += 2.0*M_PI/360.0) {
        glVertex2i(position.x+radius*cos(i),position.y+radius*sin(i));
    }
    glEnd();

}

double Piece::calculate_area() const {
    return M_PI * radius * radius;
}

double Piece::calculate_perimeter() const {
    return 2.0 * M_PI * radius;
}




