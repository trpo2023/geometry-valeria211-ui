#pragma once 

using namespace std;

class Circle 
{

private: 

	float xCoord = 0;
	float yCoord = 0;
	float radious = 0;

public:

	float GetXcoord() { return xCoord; }
	float GetYcoord() { return yCoord; }
	float GetRadios() { return radious; }

	void SetXcoord(float x) { xCoord = x; }
	void SetYcoord(float y) { yCoord = y; }
	void SetRadious(float rad) { radious = rad; }

	string name = "";
	string intersections[10];

public: 

	double CalculatePerimeter(float r) 
	{
		return  2 * r * M_PI;
	}
	
	double CalculateArea(float r) 
	{
		return r * r * M_PI;
	}
};
class ReadFromFile 
{

protected:

	vector <string> dataFromFile(string path)// записываем данные из файла в массив строк
	{
		string line = "";
		int index = 0;
		int dataSize = 0;

		ifstream checkLines(path);
		if (checkLines.is_open())
			while (getline(checkLines, line)) 
				dataSize++;
				
		line = "";
		vector<string> data(dataSize);

		ifstream in(path);
		if (in.is_open())
		{
			while (getline(in,line))
			{
				data[index] = line;
				index++;
			}
		}
		in.close();
		return data;
	}
};
class AnalyseData : ReadFromFile
{
public:

	map <string, vector<string>> TakeWktDataForCircle(string path) 
	{
		int circleWordLenght = 6; // ожидаемая длина слова "circle"
		vector <string> lowercaseData(dataFromFile(path).size());// Объявляем массив строк чтобы привести все в нижний регистр

		lowercaseData = dataFromFile(path);// кладем сюда всю информацию с файла WKT

		map <string, vector<string>> parsedData;// объявляем словарик 
		vector <string> coordArray(parsedData.size());// объявляем массив координат для круга 

		for (size_t i = 0; i < lowercaseData.size();i++)// приводим весь текст в нижний регистр и записываем его в новый массив строк 
			for (size_t j = 0; j < lowercaseData[i].size(); j++)// идем по всей строке
				lowercaseData[i][j] = tolower(lowercaseData[i][j]); // приводим символы в нижний регистр 
	
		int expectedErrorLine = 0;
		int circleIndex = 0;
		for (auto line: lowercaseData)// перебираем все строки в полученном массиве
		{	
			if (line.substr(0, circleWordLenght) == "circle")// проверяем правильность ввода и наличия ключевого слова "circle"
			{
				parsedData[line.substr(0, circleWordLenght) + '_' + to_string(circleIndex)] = ParseString(line);// кладем массив координат;
				circleIndex++;
			}

			else 
				cout << "Error at column 0" << " at line " << expectedErrorLine << ": expected 'circle'.\n"
				<<"This cricle does not go at total list...";

			expectedErrorLine++;	
		}
		return parsedData;
	}

private:

	vector <string> ParseString(string line)// получает строку из массива строк , возвращает массив координат  
	{
		vector<string> coordArray(3);//объявляем массив координат и радиусов
		string numbers = "0123456789. ";
		string parsedString = ""; // сюда будем классать исключительно координаты и радиус круга

		int countOfOpenBracets = 0, countOfCloseBracets = 0;
		for (size_t i = 0; i < line.length(); i++)// находим кол-во открываюющихся и закрывающихся скобок в строке
		{
			if (line[i] == '(')
				countOfOpenBracets++;

			else if (line[i] == ')')
				countOfCloseBracets++;
		}
		
		if (countOfOpenBracets > 1 || countOfCloseBracets > 1) // проверям кол-во открывающих и закрываюих скобок
		{
			cout << "Bracket's format error! Check the spelling of bracket's in the file.";
			cout << "\nClosing the process...";
			exit(EXIT_SUCCESS);
		}

		// circle(1 2, 3.1( Error at column 15: expected ')
		if (line[6] != '(')// проверка открывающей скобки
		{
			cout << "Error at column 6: expected '('";
			cout << "\nClosing the process...";
			exit(EXIT_SUCCESS);
		}

		if (line[line.length() - 1] != ')')// проверка закрывающей скобки
		{
			cout << "Error at column " << (line.length() - 1) << ": expected '('";
			cout << "\nClosing the process...";
			exit(EXIT_SUCCESS);
		}
			
		int indexOfOpenBracket = 0, indexOfCloseBracket = 0;// запоминаем индекс открывающией и закрывающей скобки
		for (size_t i = 0; i < line.length(); i++) 
		{
			if (line[i] == '(')
				indexOfOpenBracket = i;

			else if (line[i] == ')')
				indexOfCloseBracket = i;
		}
		// circle(x1 2, 3.0) Error at column 7: expected '<double>'
		string forbiddenBracketsSymbols = "qwertyuiop[]asdfghjkl;'zxcvbnm/`-=QWERTYUIOPASDFGHJKLZXCVBNM";
		for(size_t i=indexOfOpenBracket+1;i<indexOfCloseBracket-1;i++)// проверка правильности написания внутри скобок 
			for (size_t j = 0; j < forbiddenBracketsSymbols.length(); j++)
				if (line[i] == forbiddenBracketsSymbols[j]) 
				{
					cout << "Erorr at column " << i << ": expected '<double>'";
					cout << "\nClosing the process...";
					exit(EXIT_SUCCESS);
				}
			
		for (size_t i = 0; i < line.length(); i++) 
			for (size_t j = 0; j < numbers.length(); j++) 
				if (line[i] == numbers[j]) 
				{
					parsedString += line[i];
					break;
				}

		string coordString = "";
		int index = 0;
		for (size_t i = 0; i < parsedString.length(); i++) 
		{
			if (parsedString[i] != ' ' && parsedString[i] != ',')
				coordString += parsedString[i];

			else
			{
				coordArray[index] = coordString;
				index++;
				coordString = "";
			}

			if (i == parsedString.length()-1)
				coordArray[index] = coordString;
		}
		//circle(1.0 2.1, 3) 123 Error at column 19: unexpected token
		if (indexOfCloseBracket != line.length()-1)//ловим unexpected token если он есть 
		{
			cout << "Error at column " << indexOfCloseBracket + 1 << ": unexpected token";
			cout << "\nClosing the process...";
			exit(EXIT_SUCCESS);
		}
		return coordArray;// возвращает неотсортированный массив координат , index[0] - xCoord, index[1] - yCoord, index[2] - radious
	}
};


float CalculateCenterDistance(float x2, float x1, float y2, float y1);

void WriteCircleIntersections(vector <Circle>& allCircles);