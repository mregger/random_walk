#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Logger.h"

using namespace std;

//by Eduardo"

Logger::Logger(string filename)
{
  this->filename = filename;
}

void Logger::write_map(vector<vector<double>>& map)
{
  ofstream f;
  f.open(this->filename);
  for(int i = 0; i < map.size()-1; i++)
  {
    for(int j = 0; j < map.at(i).size()-1; j++)
    {
      f << map[i][j] << ",";
      //cout << map[i][j] << "-\n";
    }
    f << "\n";
  }
  f.close();
}

void Logger::write_series(vector<double> series)
{
  ofstream f;
  f.open(this->filename);
  for(int i = 0; i < series.size(); i++)
  {
    f << i << "," << series.at(i) << "\n";
  }
  f.close();
}

void Logger::write_linked_list(position*node)
{
  ofstream f;
  f.open(this->filename);
  //f << 0 << ", " << 0 << "\n";
  while(node->get_position_id() > 0)
  {
    double x = node->get_x();
    double y = node->get_y();

    f << x << ", " << y << "\n";
    node = node->get_parent();
  }
  f.close();
}
