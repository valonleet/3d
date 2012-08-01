#ifndef GUARD_Plane3D_h
#define GUARD_Plane3D_h

#include "Point3D.h"
#include "Vector3D.h"
#include <iostream>

//===============================================================
// Plane:
// Mathematical Equation: ax + by + cz + d == 0
// Where <a, b, c> is the vector normal to the plane
//
// Class Invariant:
// a, b, c, and d represent the constants in the plane equation
// Vector3D normal will always be equal to <a, b, c>
//================================================================

class Plane3D {

public:
	/* construcotrs */
	Plane3D::Plane3D();																// constructs an empty plane (a=b=c=d=0)
	Plane3D::Plane3D(const double, const double, const double, const double);		// constructs a plane with the given a, b, c, d constants
	Plane3D::Plane3D(const Point3D&, const Point3D&, const Point3D&);				// constructs a plane using three points on the plane
	Plane3D::Plane3D(const Vector3D&, const double);								// constructs a plane from the given normal vector and d value (default d = 0.0)
	Plane3D::Plane3D(const Vector3D&, const Point3D&);								// constructs a plane from the given normal vector and point on the plane

	/* accessors */
	double get_a() const { return a; }						// return a
	double get_b() const { return b; }						// return b
	double get_c() const { return c; }						// return c
	double get_d() const { return d; }						// return d
	Vector3D get_normal() const { return normal; }			// return normal

	/* input */
	friend std::istream& operator>>(std::istream&, Plane3D&);		// input a plane
			
private:
	double a;				// constant a in the plane equation (x component of the normal vector)
	double b;				// constant b in the plane equation (y component of the normal vector)
	double c;				// constant c in the plane equation (z component of the normal vector)
	double d;				// constant d in the plane equation (moves the plane up and down on the normal vector)
	Vector3D normal;		// Vector3D that is normal to the plane
};

/* comparisons */
bool empty_plane(const Plane3D&);							// returns true if the plane is empty (i.e. the normal vector is a null vector)
bool parallel(const Plane3D&, const Plane3D&);				// returns true if two planes are parallel (i.e. their normal vectors are parallel)
bool perpendicular(const Plane3D&, const Plane3D&);			// returns true if two planes are perpendicular (i.e. their normal vectors are perpendicular)

/* output */
std::ostream& operator<<(std::ostream&, const Plane3D&);	// output a plane in the form ax + by + cz + d = 0

#endif