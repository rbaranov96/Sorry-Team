//
// Created by Robert Baranov on 4/2/18.
//

#ifndef UNTITLED5_PIECE_H
#define UNTITLED5_PIECE_H

#include <iostream>
#include <math.h>
#include <string>
#include <memory>
#include <vector>
#include "piece.h"


using namespace std;
struct hue{
    double red;
    double green;
    double blue;
};
struct xy_position{
    double x;
    double y;
};
class Shape{

private:
public:
    //Constructors for Shape parent class
    Shape();
    Shape(hue f);
    Shape(xy_position p);
    Shape(string piece_color);
    Shape(double x_in, double y_in);
    Shape(hue f, xy_position p);
    Shape(hue f, int x_in, int y_in);
    Shape(const Shape &s); // copy constructor

    ~Shape();

    //getters
    string get_color() const;
    double get_area() const;
    double get_perimeter() const;
    hue get_fill() const;
    xy_position get_position() const;
    double get_x() const;
    double get_y() const;

    //setters
    void set_color(string piece_color);
    void set_fill(hue f);
    void set_fill(double r, double g, double b);
    void set_position(xy_position p);
    void set_position(double x_in, double y_in);

    // methods to move the shape and draw it in the gui
    void move(int delta_x, int delta_y);

    virtual void draw() const = 0;

protected:
    hue fill;
    xy_position position;
    string color;
    virtual double calculate_area() const = 0;
    virtual double calculate_perimeter() const = 0;
};

class Piece : public Shape {
public:
    // Constructors
    Piece();
    Piece(double r);
    Piece(double r, hue f);
    Piece(hue f);

    ~Piece();

    // getter
    double get_radius() const;

    // setter
    void set_radius(double r);

    void draw() const override;
private:
    double calculate_area() const override;
    double calculate_perimeter() const override;
    double radius;
};






#endif //UNTITLED5_PIECE_H
