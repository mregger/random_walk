#include "position.h"

using namespace std;

//by Eduardo"

position::position(position*p)
{
  this->parent = p;
  if(this->parent)
    this->position_id = this->parent->get_position_id() + 1;
  else
    this->position_id = 0;
}

position::~position()
{
  //cout << "bye! " << this->position_id;
}

void position::set_coordinates(double x, double y)
{
  this->x = x;
  this->y = y;
}

void position::set_angle(double angle)
{
  this->angle = angle;
}

position* position::get_parent()
{
  return parent;
}

int position::get_position_id()
{
  return position_id;
}

double position::get_x()
{
  return this->x;
}

double position::get_y()
{
  return this->y;
}

double position::get_angle()
{
  return this->angle;
}

double position::get_r2()
{
  return (pow(this->x, 2) + pow(this->y, 2));
}
