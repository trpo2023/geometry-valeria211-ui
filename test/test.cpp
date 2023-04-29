#ifndef CIRCLE_TEST
#define CIRCLE_TEST

#include <string>
#include <vector>
#include <math.h>

#include <ctest.h>

#include <circle.h>

using namespace std;

float CalculateCenterDistance(float x2, float x1, float y2, float y1);

CTEST(distance, positive_values)
{
    float x1 = 0, x2 = 1, y1 = 0, y2 = 1;
    float distance = CalculateCenterDistance(x2, x1, y2, y1);
    float expected = sqrt(2.0f);
    ASSERT_EQUAL(expected, distance);
}

CTEST(distance, negative_values)
{
    float x1 = -1, x2 = 1, y1 = -1, y2 = 1;
    float distance = CalculateCenterDistance(x2, x1, y2, y1);
    float expected = sqrt(8.0f);
    ASSERT_EQUAL(expected, distance);
}

CTEST(distance, zero_values)
{
    float x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    float distance = CalculateCenterDistance(x2, x1, y2, y1);
    float expected = 0.0f;
    ASSERT_EQUAL(expected, distance);
}

CTEST(distance, large_values)
{
    float x1 = 10000000, x2 = 10000001, y1 = 10000000, y2 = 10000001;
    float distance = CalculateCenterDistance(x2, x1, y2, y1);
    float expected = sqrt(2.0f);
    ASSERT_EQUAL(expected, distance);
}

///////////////////////////////////////////////////////////

/*void WriteCircleIntersections(std::vector<Circle>& allCircles); 


 CTEST(circle_intersections, test1)
 {
    
     Circle c1(0, 0, 1);
     Circle c2(3, 0, 1);

     vector<Circle> allCircles;
     allCircles.push_back(c1);
     allCircles.push_back(c2);

     WriteCircleIntersections(allCircles);
    
     ASSERT_STR("Circle 2", allCircles[0].intersections[0].c_str());

     ASSERT_STR("", allCircles[1].intersections[0].c_str());
}*/


#endif







