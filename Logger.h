#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "position.h"

using namespace std;

class Logger
{
private:
  string filename;
public:
  Logger(string);

  void write_map(vector<vector<double>>&);

  void write_linked_list(position*);

  void write_series(vector<double>);
};
