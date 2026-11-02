#include <iostream>
#include "figures.h"

using namespace std;

const double PI = 3.141592653589793;

void readPoint(Point& p) {
    cin >> p.x >> p.y;
}

void printPoint(const Point& p) {
    cout << p.x << " " << p.y << endl;
}

void readCircle(Circle& c) {
    cin >> c.center.x >> c.center.y >> c.radius;
}

void printCircle(const Circle& c) {
    cout << c.center.x << " "
         << c.center.y << " "
         << c.radius << endl;
}

double circleLength(const Circle& c) {
    return 2 * PI * c.radius;
}

double circleArea(const Circle& c) {
    return PI * c.radius * c.radius;
}

void readSquare(Square& s) {
    cin >> s.leftTop.x >> s.leftTop.y >> s.side;
}

void printSquare(const Square& s) {
    cout << s.leftTop.x << " "
         << s.leftTop.y << " "
         << s.side << endl;
}

double squarePerimeter(const Square& s) {
    return 4 * s.side;
}

double squareArea(const Square& s) {
    return s.side * s.side;
}