#include "Point3D.h"

//============================
// constructors
//============================

// Origin
Point3D::Point3D() : x(0.0), y(0.0), z(0.0) {}

// Point (x, y, z)
Point3D::Point3D(const double x, const double y, const double z) : x(x), y(y), z(z) {}

/* input / output */
// input a point
std::istream& operator>>(std::istream& is, Point3D& p) {
	double x, y ,z;

	is >> x >> y >> z;

	p.x = x;
	p.y = y;
	p.z = z;

	is.clear();

	return is;
}

// output a point in the form (x, y, z)
std::ostream& operator<<(std::ostream& os, Point3D p) {
	os << "(" << p.get_x() << ", " << p.get_y() << ", " << p.get_z() << ")";
	return os;
}