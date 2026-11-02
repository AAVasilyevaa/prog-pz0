#include <iostream>
#include "figures.h"
#include "func.h"

using namespace std;

int main() {
    Point p;
    Circle c1, c2;
    Square s1, s2;

    readPoint(p);
    readCircle(c1);
    readCircle(c2);
    readSquare(s1);
    readSquare(s2);

    printPoint(p);
    printCircle(c1);
    printCircle(c2);
    printSquare(s1);
    printSquare(s2);

    cout << circleLength(c1) << endl;
    cout << circleArea(c1) << endl;

    cout << squarePerimeter(s1) << endl;
    cout << squareArea(s1) << endl;

    cout << pointInsideCircle(p, c1) << endl;
    cout << pointInsideSquare(p, s1) << endl;

    cout << pointOnCircle(p, c1) << endl;
    cout << pointOnSquare(p, s1) << endl;

    cout << circlesIntersect(c1, c2) << endl;
    cout << squaresIntersect(s1, s2) << endl;
    cout << circleSquareIntersect(c1, s1) << endl;

    cout << circleInsideCircle(c1, c2) << endl;
    cout << squareInsideSquare(s1, s2) << endl;
    cout << squareInsideCircle(s1, c1) << endl;
    cout << circleInsideSquare(c1, s1) << endl;

    return 0;
}