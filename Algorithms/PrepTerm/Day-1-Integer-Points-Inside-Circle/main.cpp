#include <cmath>
#include <iostream>

using namespace std;

long long maxIntegerPoints(double radius) {
  // Calculate total number of (x, y) integer pairs inside a circle of radius 'r'
  long long x = 1, y = (long long)radius;
  double radiusSquared = radius * radius;

  long long pointsInEachQuadrant = 0;
  for (; x < radius; ++x) {
    while (x * x + y * y >= radiusSquared)
      --y;
    pointsInEachQuadrant += y;
  } 

  // 4 * validPointsInsideSegment: Each quadrant has the same number of points due to symmetry,
  // since the circle is centered at the origin (0, 0).
  // 4 * ceil(radius) - 1: Accounts for the points on the axes.
  // +1 for the origin (0, 0).

  return 4 * (pointsInEachQuadrant + (ceil(radius) - 1)) + 1;
}

void solve() {
  double radius;
  cin >> radius;

  cout << maxIntegerPoints(radius) << endl;
}

int main() {
  long long t;
  cin >> t;
  while (t--)
    solve();
}