#include "Vector3D.h"
#include <math.h>
#include <stdexcept>

//============================
// constructors
//============================

// Null Vector
Vector3D::Vector3D() : x(0.0), y(0.0), z(0.0) {}

// Vector <x, y, z>
Vector3D::Vector3D(const double x, const double y, const double z) : x(x), y(y), z(z) {}

// Vector constructed from initial and terminal points
Vector3D::Vector3D(const Point3D& p1, const Point3D& p2) {
	x = p2.get_x() - p1.get_x();
	y = p2.get_y() - p1.get_y();
	z = p2.get_z() - p1.get_z();
}

//============================
// member operations
//============================

// compound addition
Vector3D& Vector3D::operator+=(const Vector3D& v2) {
	x += v2.x;
	y += v2.y;
	z += v2.z;

	return *this;
}

// compound subtraction
Vector3D& Vector3D::operator-=(const Vector3D& v2) {
	x -= v2.x;
	y -= v2.y;
	z -= v2.z;

	return *this;
}

//============================
// non-member operations 
//============================

// add two vectors
Vector3D operator+(const Vector3D& v1, const Vector3D& v2) {
	Vector3D ret = v1;

	ret += v2;

	return ret;
}

// subtract two vectors
Vector3D operator-(const Vector3D& v1, const Vector3D& v2) {
	Vector3D ret = v1;

	ret -= v2;

	return ret;
}

// take the dot product of two vectors
double dot_product(const Vector3D& v1, const Vector3D& v2) {
	return (v1.get_x() * v2.get_x() 
			+ v1.get_y() * v2.get_y() 
			+ v1.get_z() * v2.get_z());
}

// take the cross product of two vectors
Vector3D cross_product(const Vector3D& v1, const Vector3D& v2) {
	double x = (v1.get_y() * v2.get_z()) - (v1.get_z() * v2.get_y());
	double y = -(v1.get_x() * v2.get_z()) + (v1.get_z() * v2.get_x());		// sign change
	double z = (v1.get_x() * v2.get_y()) - (v1.get_y() * v2.get_x());

	return Vector3D(x, y, z);
}

// scale the vector by a factor of scale_factor <x, y, z> -> <scale_factor * x, scale_factor * y, scale_factor * z>
Vector3D scale(const Vector3D& v, const double scale_factor) {
	return Vector3D(scale_factor * v.get_x(), scale_factor * v.get_y(), scale_factor * v.get_z());
}

// get the magnitude of a vector <x, y, z> returns sqrt(x^2 + y^2 + z^2)
double magnitude(const Vector3D& v) {
	return sqrt(pow(v.get_x(), 2) + pow(v.get_y(), 2) + pow(v.get_z(), 2));
}

// creates a unit vector from the given vector
Vector3D to_unit_vector(const Vector3D& v) {
	// if the vector is a null vector its magnitude is zero
	// we will encounter division by 0 in the next line, so throw domain_error
	if (null_vector(v))
		throw std::domain_error("Cannot Create A Unit Vector From A Null Vector");
	return scale(v, 1 / magnitude(v));
}

// the scalar projection of the second vector on the first
double scalar_projection(const Vector3D& v1, const Vector3D& v2) {
	if (null_vector(v1) || null_vector(v2))
		return 0;
	return dot_product(v1, v2) / magnitude(v1);
}

// the scalar projection of the second vector on the first
Vector3D vector_projection(const Vector3D& v1, const Vector3D& v2) {
	if (null_vector(v1) || null_vector(v2))
		return Vector3D(0, 0, 0);
	return scale(v1, (dot_product(v1, v2) / pow(magnitude(v1), 2)));
}

//============================
// comparisons
//============================

// returns true if the vector is a null vector (i.e. <0, 0, 0>)
bool null_vector(const Vector3D& v) {
	return (v.get_x() == 0.0 && v.get_y() == 0.0 && v.get_z() == 0.0);
}

// returns true if the vectors are parallel (i.e. their cross product results in a null vector)
bool parallel(const Vector3D& v1, const Vector3D& v2) {
	// if either vector is a null vector then the two cannot be parallel
	if (null_vector(v1) || null_vector(v2))
		return false;
	return (null_vector(cross_product(v1, v2)));
}

// returns true if the vectors are perpendicular (i.e. their dot product is 0)
bool perpendicular(const Vector3D& v1, const Vector3D& v2) {
	// if either vector is a null vector then the two cannot be perpendicular
	if (null_vector(v1) || null_vector(v2))
		return false;
	return (dot_product(v1, v2) == 0);
}

// returns true if two vectors are skew (i.e. they are neither parallel nor perpendicular and neither is a null vector)
bool skew(const Vector3D& v1, const Vector3D& v2) {
	if (null_vector(v1) || null_vector(v2))
		return false;
	return (parallel(v1, v2) == false && perpendicular(v1, v2) == false);
}

//============================
// input / output 
//============================

// input a vector
std::istream& operator>>(std::istream& is, Vector3D& v) {
	double x, y, z;

	is >> x >> y >> z;

	v.x = x;
	v.y = y;
	v.z = z;

	is.clear();

	return is;
}

// output a vector as <x, y, z>
std::ostream& operator<<(std::ostream& os, const Vector3D& v) {
	os << "<" << v.get_x() << ", " << v.get_y() << ", " << v.get_z() << ">";
	return os;
}