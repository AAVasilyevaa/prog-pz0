#ifndef FIGURES_H
#define FIGURES_H

#include "structs.h"

void readPoint(Point& p);
void printPoint(const Point& p);

void readCircle(Circle& c);
void printCircle(const Circle& c);
double circleLength(const Circle& c);
double circleArea(const Circle& c);

void readSquare(Square& s);
void printSquare(const Square& s);
double squarePerimeter(const Square& s);
double squareArea(const Square& s);

#endif