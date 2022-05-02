#pragma once
#include <random>

using namespace std;

class Utilities
{
public:
  static int randomNumber(int begin, int end)
  {
    random_device seed;
    mt19937 engine(seed());
    uniform_int_distribution<int> uniformDist(begin, end);
    return uniformDist(engine);
  }
};
