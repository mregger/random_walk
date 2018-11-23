#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "position.h"
#define PI 3.14159265

using namespace std;

//by Eduardo"

class Walker
{
private:
  int biggus_number = 32767;
  double step_size;
  double x_bound;
  double y_bound;
  double backtrack_threshhold;
  position current_position;

  bool within_bounds(double, double);
public:
  Walker(double, double, double);

  position* walk(int, bool);

  double calculate_r2();

  bool not_backtracking(double, double);
};
