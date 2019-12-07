#pragma once
#ifndef lab4task1
#define lab4task1

using namespace std;

class Engine{
	public:
		int cylinders, litres;
		void printEngine(int cylinders, int litres);

};

class Person {
public:
	string name, address;
	bool allowedToDrive;
	void printPerson(string name, string address, bool allowedToDrive);
};

class Body {
public: 
	  string colour;
	  float width, hight;
	  void printBody(string colour, float width, float hight);
};

class MotorVehicle {
public: Engine engine;
	  Body   body;
	  Person person, end;
	  int tires;
	  float* arr;

	  MotorVehicle(int numtires, int cylinders, float litres, float width, float hight, string name2, string model, string colour, string address, bool allowedToDrive, float* tireDiametre);
	 void printMotorVehicle(int tires, float* arr);
	 void printAll();
	 ~MotorVehicle();
};

#endif // !lab4task1