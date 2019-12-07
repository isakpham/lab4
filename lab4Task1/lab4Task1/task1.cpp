#include <iostream>
#include <string>
#include <lab4task1.h>
using namespace std;




void Engine::printEngine(int cylinders, int litre) {
		  cout << "Number of cylinders " << cylinders << endl;
		  cout << "Number of litres: " << litre << endl;
}

 void Person::printPerson(string name, string address, bool allowedToDrive) {
		  cout << "Name: " << name << endl;
		  cout << "Address: " << address << endl;
		  cout << "Allowed to drive?: " << (allowedToDrive ? "Yes" : "No") << endl;
}


void Body::printBody(string colour, float widht, float hight) {
		  cout << "Colour: " << colour << endl;
		  cout << "Car Width: " << width << endl;
		  cout << "Car hight: " << hight << endl;
}





MotorVehicle::MotorVehicle(int numtires, int cylinders, float litres, float width, float hight, string name, string model, string colour, string address, bool allowedToDrive, float* tireDiametre) {
		  tires = numtires;
		  arr = new float[tires*sizeof(float)];
		  memcpy(arr, tireDiametre, tires * sizeof(float));
		  engine.cylinders = cylinders;
		  engine.litres = litres;
		  person.name = name;
		  person.address = address;
		  person.allowedToDrive = allowedToDrive;
		  body.colour = colour;
		  body.width = width;
		  body.hight = hight;	
	  }
	
	  void MotorVehicle::printMotorVehicle(int tires, float* arr) {
		  cout << "Number of tires: " << tires << endl;		
		  cout << "Tire diameter: " << endl;
		  for (int i = 0; i < tires; i++)
		  {
			  cout << "Tire " << i + 1 <<": " << arr[i] << endl;
		  }
		  
	  }

	  void MotorVehicle::printAll() {
		  person.printPerson(person.address,person.address,person.allowedToDrive);
		  body.printBody(body.colour,body.width,body.hight);
		  engine.printEngine(engine.cylinders,engine.cylinders);
		  printMotorVehicle(tires, arr);
	  }

	  MotorVehicle::~MotorVehicle() {
		  for (int i = 0; i <= tires; i++)
		  {
			  arr[i] = NULL;		  
			
		  }  
		  delete[] arr;
		  cout << "entity destroyed" << endl;
	  }

int main() {
	int numTires, numCylinders;
	float numLitres, carWidth, carHight;
	string owner, Carmodel, carColour, ownerAddress, trueOrFalse;
	bool allowedTodrive;
	cout << "Name?: " << endl;
	cin >> owner;
	cout << "Model?:" << endl;
	cin >> Carmodel;
	cout << "Address?: " << endl;
	cin >> ownerAddress;
	cout << "Colour?: " << endl;
	cin >> carColour;
	cout << "Number of Tires?: " << endl;
	cin >> numTires;

	float* tireWidhtArr = new float[numTires], * tirePtr = tireWidhtArr;
	cout << "tire width?" << endl;
	for (int i = 0; i < numTires; i++)
	{
		float tireWidth;
		cin >> tireWidth;
		tirePtr[i] = tireWidth;
	}

	cout << "Car width?: " << endl;
	cin >> carWidth;
	cout << "Car hight?:" << endl;
	cin >> carHight;
	cout << "Number of litres?: " << endl;
	cin >> numLitres;
	cout << "Number of cylinders?: " << endl;
	cin >> numCylinders;

	cout << "Allowed to drive?: " << endl;
	cin >> trueOrFalse;
	if (trueOrFalse == "yes" || trueOrFalse == "Yes")
	{
		allowedTodrive = true;
	}
	else
	{
		allowedTodrive = false;
	}

	MotorVehicle cat2(numTires, numCylinders, numLitres, carWidth, carHight, owner, Carmodel, carColour, ownerAddress, allowedTodrive, tirePtr);
	for (int i = 0; i < numTires; i++)
	{
		tirePtr[i] = NULL;
	}
	
	cout << "Name?: " << endl;
	cin >> owner;
	cout << "Model?:" << endl;
	cin >> Carmodel;
	cout << "Address?: " << endl;
	cin >> ownerAddress;
	cout << "Colour?: " << endl;
	cin >> carColour;
	cout << "Number of Tires?: " << endl;
	cin >> numTires;

	cout << "tire width?" << endl;
	for (int i = 0; i < numTires; i++)
	{
		float tireWidth;
		cin >> tireWidth;
		tirePtr[i] = tireWidth;
	}

	cout << "Car width?: " << endl;
	cin >> carWidth;
	cout << "Car hight?:" << endl;
	cin >> carHight;
	cout << "Number of litres?: " << endl;
	cin >> numLitres;
	cout << "Number of cylinders?: " << endl;
	cin >> numCylinders;

	cout << "Allowed to drive?: " << endl;
	cin >> trueOrFalse;
	if (trueOrFalse == "yes" || trueOrFalse == "Yes")
	{
		allowedTodrive = true;
	}
	else
	{
		allowedTodrive = false;
	}

	MotorVehicle cat(numTires, numCylinders, numLitres, carWidth, carHight, owner, Carmodel, carColour, ownerAddress, allowedTodrive, tirePtr);
	for (int i = 0; i < numTires; i++)
	{
		tirePtr[i] = NULL;
	}
	cat.printAll();
	cat2.printAll();
	delete[] tireWidhtArr;
}