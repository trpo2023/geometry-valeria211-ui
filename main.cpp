#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <circle.h>
using namespace std;

int main()
{
	string path = "geometry.txt";
	AnalyseData data;
	map <string, vector<string>> parsedCircleData = data.TakeWktDataForCircle(path);
	
	int circlesCount = 0;
	for (auto circle : parsedCircleData)
		circlesCount++;

	vector <Circle> circles(circlesCount);// объявляем массив окружностей 

	int circleIndex = 0;
	// построение объектов на основе полученных данных из словаря parsedCircleData
	for (auto circle : parsedCircleData) 
	{
		circles[circleIndex].SetXcoord(stof(circle.second[0]));// по индексу 0 лежит Xcoord
		circles[circleIndex].SetYcoord(stof(circle.second[1]));// по индексу 1 лежит Ycoord
		circles[circleIndex].SetRadious(stof(circle.second[2]));// по индексу 2 лежит radious
		circles[circleIndex].name = "Circle_" + to_string(circleIndex+1);
		
		circleIndex++;
	}

	WriteCircleIntersections(circles);// заполняем поле intersections для каждого объекта circle

	cout << "\n*----- Data View -----*\n\n";// вывод данных о моделировании 
	for (auto circle : circles)
	{
		cout << circle.name + "(" + to_string(circle.GetXcoord()) + " " + to_string(circle.GetYcoord()) + ","
			+ to_string(circle.GetRadios()) + ")\nPerimeter = " + to_string(circle.CalculatePerimeter(circle.GetRadios()))
			+ "\narea = " + to_string(circle.CalculateArea(circle.GetRadios())) + "\nintersects:\n";

		for (string name : circle.intersections) 
			if(name != "")
				cout << name + "\n";

		cout << "----------\n\n";
	}

	//Graphics circle;
	//circle.DrawCircles(circles);// графическое представление моделей 
}