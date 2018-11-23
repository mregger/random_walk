#include <iostream>
#include <string>
#include "Walker.h"
#include "position.h"
#include "Logger.h"

using namespace std;

//by Eduardo"

int main()
{
  double step_size = 1.0;
  string filename = "rr2.csv";
  double steps = 100;
  double x_bound = 1000;
  double y_bound = 1000;
  bool self_avoid = 1;
  Logger l(filename);
  vector<double> r_values;

  cout << "Running.";
  for(int i = 0; i  < steps; i++)
  {
    Walker w(step_size, x_bound, y_bound);
    position* p;
    p = w.walk(i, self_avoid);
    r_values.push_back(w.calculate_r2());
    cout << ".";
  }
  cout << "\n";
  l.write_series(r_values);

  Walker w(1, x_bound, y_bound);
  position* p;
  p = w.walk(400, self_avoid);
  Logger test_log("r.csv");
  test_log.write_linked_list(p);
}
