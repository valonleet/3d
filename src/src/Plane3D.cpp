#include "Plane3D.h"

//============================
// constructors
//============================

// empty plane (a=b=c=d=0)
Plane3D::Plane3D() : a(0.0), b(0.0), c(0.0), d(0.0), normal() {}

// constructs a plane with the given a, b, c, d constants
Plane3D::Plane3D(const double a, const double b, const double c, const double d) : a(a), b(b), c(c), d(d), normal(a, b, c) {}

// constructs a plane using 3 points on the plane
Plane3D::Plane3D(const Point3D& p1, const Point3D& p2, const Point3D& p3) {
	Vector3D v1(p1, p2);													// create a vector on the plane using two points on the plane
	Vector3D v2(p1, p3);													// create another vector on the plane

	normal = cross_product(v1, v2);											// normal == the cross product of two vectors on the plane

	a = normal.get_x();														// Set the constants accordingly
	b = normal.get_y();														// ...
	c = normal.get_z();														// ...

	d = (-1.0 * a * p1.get_x()) - (b * p1.get_y()) - (c * p1.get_z());		// solve for d (ax+by+cz+d == 0 -> d = -ax-by-cz) plug in x, y, and z from a point on the plane
}

// constructs a plane from the given normal vector and d value (default d = 0.0)
Plane3D::Plane3D(const Vector3D& n, const double d = 0.0) : normal(n), a(n.get_x()), b(n.get_y()), c(n.get_z()), d(d) {}

// constructs a plane from the given normal vector and point on the plane
Plane3D::Plane3D(const Vector3D& n, const Point3D& p) : normal(n), a(n.get_x()), b(n.get_y()), c(n.get_z()) {
	d = (-1.0 * a * p.get_x()) - (b * p.get_y()) - (c * p.get_z());
}

/* comparisons */
// returns true if the plane is empty (i.e. the normal vector is a null vector)
bool empty_plane(const Plane3D& p) {
	return null_vector(p.get_normal());
}

// returns true if two planes are parallel (i.e. their normal vectors are parallel)
bool parallel(const Plane3D& p1, const Plane3D& p2) {
	if (empty_plane(p1) || empty_plane(p2))
		return false;
	return (parallel(p1.get_normal(), p2.get_normal()));
}

// returns true if two planes are perpendicular (i.e. their normal vectors are perpendicular)
bool perpendicular(const Plane3D& p1, const Plane3D& p2) {
	return (perpendicular(p1.get_normal(), p2.get_normal()));
}

/* input / output */
// input a plane
std::istream& operator>>(std::istream& is, Plane3D& p) {
	double a, b, c, d;

	is >> a >> b >> c >> d;

	p.a = a;
	p.b = b;
	p.c = c;
	p.d = d;
	p.normal = Vector3D(a, b, c);

	is.clear();

	return is;
}

// output a plane as ax + by + cz + d = 0
std::ostream& operator<<(std::ostream& os, const Plane3D& p) {
	os << p.get_a() << "x + " << p.get_b() << "y + " << p.get_c() << "z + " << p.get_d() << " = 0";
	return os;
}