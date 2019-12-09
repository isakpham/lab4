#include <iostream>
#include <math.h>
#include <string>
#include "lab4Task3.h"
using namespace std;


Polyline::Polyline(const int length){
	numberOfElements = length;
	arr = new Point2D[length];	 
}

void Polyline::addPoint(float xValue, float yValue) {
	bool applied = false;
	for (int i = 0; i <= numberOfElements; i++)
	{
		
		if (arr[i].x == 0 && arr[i].y == 0 && applied == false)
		{
			arr[i].x = xValue;
			arr[i].y = yValue;
			applied = true;
		}
		
		if (i == numberOfElements && applied == false)
		{
			cout << "Array is full" << endl;
		}
	
	}	
}


void Polyline::removeLastPoint() {
	int count = 0;
	float* ptr = nullptr;
	bool replaced = false;
	for (int i = 0; i < numberOfElements; i++)
	{
		if (arr[i].x == 0 && arr[i].y == 0)
		{
			count++;
		}
		
		if (count == numberOfElements - 1 && arr[i].x == 0 && arr[i].y == 0)
		{
			cout << "No points was found" << endl;
		}
	
		if (count =! numberOfElements - 1 && arr[i].x == 0 && arr[i].y == 0 && replaced == false) {
			
			arr[i-1].x = 0;
			arr[i-1].y = 0;
			replaced = true;
		}
		
	}

}

float Polyline::PolylineIndexX(int index) {
	return  arr[index].x;
}

float Polyline::totalLenght() {
	float lengthOfPolyline = 0;
	for (int i = 0; i < numberOfElements; i++)
	{

		if (arr[i].x != 0 && arr[i].y != 0 && arr[i+1].x != 0 && arr[i+1].y != 0)
		{
		lengthOfPolyline = lengthOfPolyline + arr[i].distance(arr[i + 1]);
		}
	}
	return lengthOfPolyline;
}

void Polyline::printPolyLine(){
	for (int i = 0; i < numberOfElements; i++)
	{
		if (arr[i].x != 0 && arr[i].y != 0 )
		{
			cout << arr[i].toString() << endl;

		}
	}


}

int Polyline::numberOfPoints() {
	int count = 0;
	for (int i = 0; i < numberOfElements; i++)
	{
		if (arr[i].x == 0 && arr[i].y == 0)
		{
			count++;
		}
		return numberOfElements - count;
	}
}



void Polyline::combinePoints(int index1, int index2){
	bool createdNewPoint = false, wantToCalculate = false;
	int comparison,indexNumber;
	string answer;
	for (int i = 0; i < numberOfElements; i++)
	{
		if (arr[i].x == 0 && arr[i].y == 0)
		{
			arr[i].x = PolylineIndexX(index1) + PolylineIndexX(index2);
			arr[i].y = PolylineIndexX(index1) + PolylineIndexY(index2);
			indexNumber = i;
			createdNewPoint = true;
		}
	
		if (i == numberOfElements && createdNewPoint == false)
		{
			cout << "Polyline Array is full" << endl;
			break;
		}
	}
	
	if (createdNewPoint == true)
	{
		cout << "do you want to calculate the distance with the newly created point? (yes/no)" << endl;
		cin >> answer;
		if (answer == "yes" ||answer == "Yes")
		{
			wantToCalculate = true;
		}

		if (wantToCalculate == true)
		{
			cout << "wich point do you want to calculate distance with?" << endl;
			cin >> comparison;
			
			if (comparison > numberOfElements)
			{
				cout << "Error! indexnumber does not exist!" << endl;
			}

			if (  0 <= comparison < numberOfElements)
			{	
				cout << "the distance is " << arr[indexNumber].distance(arr[comparison]) << " units" << endl;
			}
		}
	}

}

float Polyline::PolylineIndexY(int index) {
	return  arr[index].y;
}

Polyline::~Polyline(){
	delete[] arr;
}

Point2D::Point2D(float xValue, float yValue) {
	x = xValue;
	y = yValue;
}
Point2D::Point2D() {
	x = NULL;
	y = NULL;
}

string Point2D::toString() {
	string xValue, yValue;
	xValue = to_string(x);
	yValue = to_string(y);
	
	return "x: " + xValue + " y:" + yValue;
}

Point2D::Point2D(Point2D& o) {
	x = o.x;
	y = o.y;
}

void Point2D::newPoint(float xValue, float yValue) {
	x = xValue;
	y = yValue;
}
float Point2D::distance(Point2D point2) {
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
	Polyline a(5);
	a.addPoint(1,1);
	a.addPoint(2,2);
	a.addPoint(3,3);
	a.addPoint(4,4);
	a.printPolyLine();
	cout << a.totalLenght() << endl;

}