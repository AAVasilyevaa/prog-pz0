#ifndef FUNC_H
#define FUNC_H

#include "structs.h"

bool pointInsideCircle(const Point& p, const Circle& c);
bool pointInsideSquare(const Point& p, const Square& s);

bool pointOnCircle(const Point& p, const Circle& c);
bool pointOnSquare(const Point& p, const Square& s);

bool circlesIntersect(const Circle& c1, const Circle& c2);
bool squaresIntersect(const Square& s1, const Square& s2);
bool circleSquareIntersect(const Circle& c, const Square& s);

bool circleInsideCircle(const Circle& c1, const Circle& c2);
bool squareInsideSquare(const Square& s1, const Square& s2);
bool squareInsideCircle(const Square& s, const Circle& c);
bool circleInsideSquare(const Circle& c, const Square& s);

#endif