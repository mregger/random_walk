#include <iostream>
#include <cmath>
#ifndef BLUEBERRIES
#define BLUEBERRIES

using namespace std;

//by Eduardo"

class position
{
private:
	position* parent;
	double x;
	double y;
	double angle;
	int position_id;
public:
	position(position*p);

	void set_coordinates(double, double);

	void set_angle(double);

	position* get_parent();

	int get_position_id();

	double get_x();

	double get_y();

	double get_angle();

	double get_r2();

	~position();
};

#endif
