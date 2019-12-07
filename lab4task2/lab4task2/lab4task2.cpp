#include <iostream>
#include <math.h>
#include "lab4Task2.h"
using namespace std;


Point2D::Point2D(float xValue, float yValue) {
	x = xValue;
	y = yValue;
}

Point2D::Point2D(Point2D& o) {
	x = o.x;
	y = o.y;
}

void Point2D::newPoint(float xValue, float yValue) {
	x = xValue;
	y = yValue;
}
double Point2D::distance(Point2D point2) {
	float distance, deltaX = x - point2.x, deltaY = y - point2.y;
	distance = pow(deltaX, 2) + pow(deltaY, 2);
	return sqrt(distance);
}

int main() {
	Point2D p1(1, 2);
	Point2D p2 = p1;
	Point2D p3(4, 3);
	Point2D p4(p1.x + p3.x, p1.y + p3.y);
	Point2D* p5 = new Point2D(3, 2);
	Point2D* p6 = p5;
	p6->x = 6;
	p6->y = 5;
	cout << p1.distance(p3) << endl;
	cout << p3.distance(p4) << endl;
	cout << "p1 x, " << p1.x << " p1 y " << p1.y << endl;
	cout << "p2 x, " << p2.x << " p2 y " << p2.y << endl;
	cout << "p3 x, " << p3.x << " p3 y " << p3.y << endl;
	cout << "p4 x, " << p4.x << " p4 y " << p4.y << endl;
	cout << "p5 x, " << p5->x << " p5 y " << p5->y << endl;
}