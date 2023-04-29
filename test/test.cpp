#ifndef CIRCLE_TEST
#define CIRCLE_TEST

#include <gtest/gtest.h>


#include <iostream>
#include "circle.h"
#include <string>


TEST(WriteCircleIntersectionsTest, Test1)
 {
  vector<Circle> circles{
    Circle("A", 0.0, 0.0, 5.0),
    Circle("B", 0.0, 10.0, 5.0),
    Circle("C", 10.0, 0.0, 5.0),
    Circle("D", 10.0, 10.0, 5.0)
  };
  WriteCircleIntersections(circles);

  
  ASSERT_EQ(circles[0].intersections.size(), 1);
  ASSERT_EQ(circles[0].intersections[0], "B");
  ASSERT_EQ(circles[1].intersections.size(), 1);
  ASSERT_EQ(circles[1].intersections[0], "A");
  ASSERT_EQ(circles[2].intersections.size(), 1);
  ASSERT_EQ(circles[2].intersections[0], "D");
  ASSERT_EQ(circles[3].intersections.size(), 1);
  ASSERT_EQ(circles[3].intersections[0], "C");
}

TEST(WriteCircleIntersectionsTest, Test2) {
  
  vector<Circle> circles{
    Circle("A", 0.0, 0.0, 2.0),
    Circle("B", 4.0, 4.0, 2.0),
    Circle("C", 8.0, 0.0, 2.0)
  };
  WriteCircleIntersections(circles);

  
  ASSERT_EQ(circles[0].intersections.size(), 0);
  ASSERT_EQ(circles[1].intersections.size(), 0);
  ASSERT_EQ(circles[2].intersections.size(), 0);
}


TEST(CalculateCenterDistanceTest, Test1) {
  
  float x1 = 0.0, y1 = 0.0, x2 = 0.0, y2 = 1.0;
  float expected_distance = 1.0;

  float actual_distance = CalculateCenterDistance(x2, x1, y2, y1);

  
  ASSERT_FLOAT_EQ(expected_distance, actual_distance);
}


TEST(CalculateCenterDistanceTest, Test2) 
{
  
  float x1 = 2.0, y1 = 2.0, x2 = 5.0, y2 = 6.0;
  float expected_distance = 5.0;

  float actual_distance = CalculateCenterDistance(x2, x1, y2, y1);

  ASSERT_FLOAT_EQ(expected_distance, actual_distance);
}

#endif







