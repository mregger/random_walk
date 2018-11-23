#include "Walker.h"

using namespace std;

//by Eduardo"

Walker::Walker(double step, double x_bound, double y_bound):current_position(new position(NULL))
{
  this->step_size = step;
  srand(time(0));
  this->x_bound = x_bound;
  this->y_bound = y_bound;
  this->backtrack_threshhold = this->step_size;
  this->current_position.set_angle(99);
  this->current_position.set_coordinates(0, 0);
}

position* Walker::walk(int n, bool self_avoid)
{
  for(int i = 0; i < n; i++)
  {
    //this gets a random int from 0 to 32767, and then converts it
    //to a random number from 0 to 2 pi
    double r = (double)rand() * (2*PI) /((double)this->biggus_number);

    double x = step_size * cos(r) + current_position.get_x();
    double y = step_size * sin(r) + current_position.get_y();
    double previous_angle = current_position.get_angle();
    double d = 99;
    if(current_position.get_parent())
    {
      d = sqrt(pow(current_position.get_parent()->get_x()-x,2) + pow(current_position.get_parent()->get_y()-y,2));
    }
    //cout << d <<"\n";
    bool not_backtracking = 1;

    if(self_avoid && previous_angle > 50)
    {
      not_backtracking = 1;
    }

    //if(self_avoid && this->not_backtracking(x, y))
    else if(self_avoid && d < this->backtrack_threshhold)
    {
      not_backtracking = 0;
    }

    if(this->within_bounds(x, y) and not_backtracking)
    {
      //cout << x << " -- " << y << "\n";
      position temp = new position(current_position);
      temp.set_coordinates(x, y);
      current_position = temp;
    }
    else
    {
      i--;
    }
  }
  position*pointer = & current_position;
  return pointer;
}

bool Walker::within_bounds(double x, double y)
{
  if(x > -this->x_bound && x < this->x_bound && y > -this->y_bound && y < this->y_bound)
    return 1;
  else
    return 0;
}

double Walker::calculate_r2()
{
  position* temp = &this->current_position;
  double r = 0;
  int n = 0;
  while(temp->get_position_id() > 0)
  {
    r += temp->get_r2();
    temp = temp->get_parent();
    n += 1;
  }
  r = r/((double)n);
  return r;
}

bool Walker::not_backtracking(double x, double y)
{
  position*node = &current_position;
  while(node->get_position_id() > 0)
  {
    double node_x = node->get_x();
    double node_y = node->get_y();
    if(sqrt(pow(x-node_x, 2) + pow(y-node_y, 2)) > step_size)
    {
      return 0;
    }
    node = node->get_parent();
  }
  return 1;
}
