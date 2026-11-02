#include <cmath>
#include <algorithm>
#include "func.h"

using namespace std;

const double EPS = 1e-5;

double distancePoints(const Point& a, const Point& b) {
    return sqrt(
        (a.x - b.x) * (a.x - b.x) +
        (a.y - b.y) * (a.y - b.y)
    );
}

bool pointInsideCircle(const Point& p, const Circle& c) {
    return distancePoints(p, c.center) < c.radius - EPS;
}

bool pointInsideSquare(const Point& p, const Square& s) {
    double left = s.leftTop.x;
    double right = left + s.side;
    double top = s.leftTop.y;
    double bottom = top - s.side;

    return p.x > left + EPS &&
           p.x < right - EPS &&
           p.y < top - EPS &&
           p.y > bottom + EPS;
}

bool pointOnCircle(const Point& p, const Circle& c) {
    return fabs(distancePoints(p, c.center) - c.radius) < EPS;
}

bool pointOnSquare(const Point& p, const Square& s) {
    double left = s.leftTop.x;
    double right = left + s.side;
    double top = s.leftTop.y;
    double bottom = top - s.side;

    bool vertical =
        (fabs(p.x - left) < EPS || fabs(p.x - right) < EPS) &&
        p.y >= bottom - EPS && p.y <= top + EPS;

    bool horizontal =
        (fabs(p.y - top) < EPS || fabs(p.y - bottom) < EPS) &&
        p.x >= left - EPS && p.x <= right + EPS;

    return vertical || horizontal;
}

bool circlesIntersect(const Circle& c1, const Circle& c2) {
    double d = distancePoints(c1.center, c2.center);

    return d <= c1.radius + c2.radius + EPS &&
           d + EPS >= fabs(c1.radius - c2.radius);
}

bool squareInsideSquare(const Square& s1, const Square& s2) {
    return s1.leftTop.x > s2.leftTop.x + EPS &&
           s1.leftTop.x + s1.side < s2.leftTop.x + s2.side - EPS &&
           s1.leftTop.y < s2.leftTop.y - EPS &&
           s1.leftTop.y - s1.side > s2.leftTop.y - s2.side + EPS;
}

bool squaresIntersect(const Square& s1, const Square& s2) {
    double left1 = s1.leftTop.x;
    double right1 = left1 + s1.side;
    double top1 = s1.leftTop.y;
    double bottom1 = top1 - s1.side;

    double left2 = s2.leftTop.x;
    double right2 = left2 + s2.side;
    double top2 = s2.leftTop.y;
    double bottom2 = top2 - s2.side;

    bool separated =
        right1 < left2 - EPS ||
        right2 < left1 - EPS ||
        bottom1 > top2 + EPS ||
        bottom2 > top1 + EPS;

    if (separated)
        return false;

    if (squareInsideSquare(s1, s2) ||
        squareInsideSquare(s2, s1))
        return false;

    return true;
}

bool circleInsideCircle(const Circle& c1, const Circle& c2) {
    return distancePoints(c1.center, c2.center) + c1.radius
           < c2.radius - EPS;
}

bool squareInsideCircle(const Square& s, const Circle& c) {
    Point p1 = s.leftTop;
    Point p2 = {s.leftTop.x + s.side, s.leftTop.y};
    Point p3 = {s.leftTop.x, s.leftTop.y - s.side};
    Point p4 = {s.leftTop.x + s.side, s.leftTop.y - s.side};

    return pointInsideCircle(p1, c) &&
           pointInsideCircle(p2, c) &&
           pointInsideCircle(p3, c) &&
           pointInsideCircle(p4, c);
}

bool circleInsideSquare(const Circle& c, const Square& s) {
    double left = s.leftTop.x;
    double right = left + s.side;
    double top = s.leftTop.y;
    double bottom = top - s.side;

    return c.center.x - c.radius > left + EPS &&
           c.center.x + c.radius < right - EPS &&
           c.center.y + c.radius < top - EPS &&
           c.center.y - c.radius > bottom + EPS;
}

bool circleSquareIntersect(const Circle& c, const Square& s) {
    double left = s.leftTop.x;
    double right = left + s.side;
    double top = s.leftTop.y;
    double bottom = top - s.side;

    double nearestX = max(left, min(c.center.x, right));
    double nearestY = max(bottom, min(c.center.y, top));

    Point nearest = {nearestX, nearestY};

    if (distancePoints(c.center, nearest) > c.radius + EPS)
        return false;

    if (circleInsideSquare(c, s))
        return false;

    if (squareInsideCircle(s, c))
        return false;

    return true;
}