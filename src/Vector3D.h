#ifndef GUARD_Vector3D_h
#define GUARD_Vector3D_h

#include <iostream>
#include "Point3D.h"

//===================================
// Vector3D
//===================================

class Vector3D {

public:
	/* constructors */
	Vector3D();													// Null Vector
	Vector3D(const double, const double, const double);			// Vector <x, y, z>
	Vector3D(const Point3D&, const Point3D&);					// Vector constrcuted from initial and terminal point

	/* accessors */
	double get_x() const { return x; }			// return x
	double get_y() const { return y; }			// return y
	double get_z() const { return z; }			// return z

	/* member operations */
	Vector3D& operator+=(const Vector3D&);		// compound addition
	Vector3D& operator-=(const Vector3D&);		// compound subtraction

	/* input */
	friend std::istream& operator>>(std::istream&, Vector3D&);	// input a vector

private:
	double x;		// x component of the vector
	double y;		// y component of the vector
	double z;		// z component of the vector

};

/* non-member operations */
Vector3D operator+(const Vector3D&, const Vector3D&);			// add two vectors
Vector3D operator-(const Vector3D&, const Vector3D&);			// subtract two vectors
double dot_product(const Vector3D&, const Vector3D&);			// dot product
Vector3D cross_product(const Vector3D&, const Vector3D&);		// cross product
Vector3D scale(const Vector3D&, const double);					// scale a vector
double magnitude(const Vector3D&);								// get the magnitude of a vector
Vector3D to_unit_vector(const Vector3D&);						// create a unit vector from a vector
double scalar_projection(const Vector3D&, const Vector3D&);		// the scalar projection of the second vector on the first
Vector3D vector_projection(const Vector3D&, const Vector3D&);	// the vector projection of the second vector on the first

/* comparisons */
bool null_vector(const Vector3D&);								// returns true if the vector is a null vector
bool parallel(const Vector3D&, const Vector3D&);				// returns true if the vectors are parallel
bool perpendicular(const Vector3D&, const Vector3D&);			// returns true if the vectors are perpendicular
bool skew(const Vector3D&, const Vector3D&);					// returns true if the vectors are skew

/* output */
std::ostream& operator<<(std::ostream&, const Vector3D&);		// prints a vector in the form <x, y, z>

#endif