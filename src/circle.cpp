#include <circle.h>


using namespace std;


float CalculateCenterDistance(float x2, float x1, float y2, float y1)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));// возвращаем расстояние между центрами окружностей
}

void WriteCircleIntersections(vector <Circle>& allCircles)// возвращает список фигур, с которыми пересекается выбранный экземпляр
{
	int index = 0;
	for (size_t i = 0; i < allCircles.size(); i++)
	{
		for (size_t j = 0; j < allCircles.size(); j++)
		{
			if (j != i) 
			{
				if (CalculateCenterDistance(allCircles[j].GetXcoord(), allCircles[i].GetXcoord(), allCircles[j].GetYcoord(), allCircles[i].GetYcoord()) <= (allCircles[j].GetRadios() + allCircles[i].GetRadios()))
				{
					allCircles[i].intersections[index] = allCircles[j].name;
					index++;
				}
			}
		}
		index = 0;
	}
}

