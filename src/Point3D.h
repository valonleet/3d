#ifndef GUARD_Point3D_h
#define GUARD_Point3D_h

#include <iostream>

//===================================
// Point3D:
// A point in 3D space
//===================================

class Point3D {

public:
	/* constructors */
	Point3D();												// constructs a point (0, 0, 0)
	Point3D(const double, const double, const double);		// constructs the point (x, y, z)

	/* accessors */
	double get_x() const { return x; }			// return x
	double get_y() const { return y; }			// return y
	double get_z() const { return z; }			// return z

	/* input */
	friend std::istream& operator>>(std::istream&, Point3D&);	// input a point

private:
	double x;		// x position of the point
	double y;		// y position of the point
	double z;		// z position of the point
};

/* ouput */
std::ostream& operator<<(std::ostream&, const Point3D);			// output a point in the form (x, y, z)

#endif