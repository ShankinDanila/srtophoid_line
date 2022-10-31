#include <iostream>
#include "include/Strophoid.h"
#include "gtest/gtest.h"
using namespace lab2;

TEST(StrophoidConctructor, DefaultConstructor) {
  Strophoid a1;
  Point point1 = a1.getPoint();
  EXPECT_EQ(0, point1.x);
}

TEST(StrophoidMethods, SetterX) {
  Strophoid a;
  Point newPoint{ 5, 0 };
  a.setPoint(newPoint);
  EXPECT_EQ(a.getPoint().x, newPoint.x);
}

TEST(StrophoidMethods, SetterY) {
  Strophoid a;
  Point newPoint{ 0, 5 };
  a.setPoint(newPoint);
  EXPECT_EQ(a.getPoint().y, newPoint.y);
}

TEST(StrophoidMethods, Value) {
  Strophoid a;
  Point point{ 4, 0 };
  a.setPoint(point);
  Point y0 = a.value(2);
  double err = 0.001;
  EXPECT_NEAR(y0.y, 1.1547, err);
}

TEST(StrophoidMethods, Distant) {
  Strophoid a;
  Point point{ 4, 0 };
  a.setPoint(point);
  double angle = 60.0;
  double rad = a.distant(angle);
  double err = 0.001;
  EXPECT_NEAR(rad, 4.0, err);
}

TEST(StrophoidMethods, Radius) {
  Strophoid a;
  Point point{ 4, 0 };
  a.setPoint(point);
  double rad = a.radius();
  double err = 0.001;
  EXPECT_NEAR(5.6568, rad, err);
}

TEST(StrophoidMethods, SquareLoops) {
  Strophoid a;
  Point point{ 4, 0 };
  a.setPoint(point);
  double sl = a.squareLoop();
  double err = 0.01;
  EXPECT_NEAR(6.8627, sl, err);
}

TEST(StrophoidMethods, SquareBranches) {
  Strophoid a;
  Point point{ 4, 0 };
  a.setPoint(point);
  double sb = a.squareBranches();
  double err = 0.01;
  EXPECT_NEAR(57.1327, sb, err);
}

TEST(StrophoidMethods, Volume) {
  Strophoid a;
  Point point{ 4, 0 };
  a.setPoint(point);
  double vol = a.volume();
  double err = 0.01;
  EXPECT_NEAR(10.6484, vol, err);
}

int main() {
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
