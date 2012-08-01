#include "Vector3D.h"
#include "Point3D.h"
#include "Plane3D.h"
#include <stdexcept>

int main(void) {
	// 2 vectors
	Vector3D v1, v2;

	// 2 scale factors
	double scale_factor_1, scale_factor_2;

	// 2 points
	Point3D p1, p2;

	/* take two vectors as input*/
	std::cout << "enter a vector x y z: ";
	std::cin >> v1;
	std::cout << "enter another vector x y z: ";
	std::cin >> v2;

	/* take two scale factors as input */
	std::cout << "enter a scale factor: ";
	std::cin >> scale_factor_1;
	std::cout << "enter another scale factor: ";
	std::cin >> scale_factor_2;

	/* take two points as input */
	std::cout << "Enter a point x y z: ";
	std::cin >> p1;
	std::cout << "Enter another point x y z: ";
	std::cin >> p2;

	// create two planes from the given vectors and points
	Plane3D pl1(v1, p1);
	Plane3D pl2(v2, p2);

	std::cout << std::endl;

	/* test the Vector3D functions */
	std::cout << "v1: " << v1 << std::endl;
	std::cout << "v2: " << v2 << std::endl;
	std::cout << "v1 scaled by a factor of " << scale_factor_1 << " is " << scale(v1, scale_factor_1) << std::endl;
	std::cout << "v2 scaled by a factor of " << scale_factor_2 << " is " << scale(v2, scale_factor_2) << std::endl;
	std::cout << "v1 is a null vector: " << null_vector(v1) << std::endl;
	std::cout << "v2 is a null vector: " << null_vector(v2) << std::endl;
	std::cout << "v1 and v2 are parallel: " << parallel(v1, v2) << std::endl;
	std::cout << "v1 and v2 are perpendicular: " << perpendicular(v1, v2) << std::endl;
	std::cout << "v1 and v2 are skew: " << skew(v1, v2) << std::endl;
	std::cout << "v1 + v2 == " << v1 + v2 << std::endl;
	std::cout << "v1 - v2 == " << v1 - v2 << std::endl;
	std::cout << "v1 (dot) v2 == " << dot_product(v1, v2) << std::endl;
	std::cout << "v1 (cross) v2 == " << cross_product(v1, v2) << std::endl;
	std::cout << "the magnitude of v1 is: " << magnitude(v1) << std::endl;
	std::cout << "the magnitude of v2 is: " << magnitude(v2) << std::endl;

	try {
		Vector3D v1_unit = to_unit_vector(v1);
		std::cout << "v1 as a unit vector is: " << v1_unit << std::endl;
	}
	catch (std::domain_error e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Vector3D v2_unit = to_unit_vector(v2);
		std::cout << "v2 as a unit vector is: " << v2_unit << std::endl;
	}
	catch (std::domain_error e) {
		std::cout << e.what() << std::endl;
	}


	std::cout << "The scalar projection of v2 on v1 is: " << scalar_projection(v1, v2) << std::endl;
	std::cout << "The vector projection of v2 on v1 is: " << vector_projection(v1, v2) << std::endl;

	std::cout << std::endl;

	/* test the point functions */
	std::cout << "p1: " << p1 << std::endl;
	std::cout << "p2: " << p2 << std::endl;

	std::cout << std::endl;

	/* test the plane functions */
	std::cout << "pl1: " << pl1 << std::endl;
	std::cout << "pl2: " << pl2 << std::endl;
	std::cout << "pl1 is an empty plane: " << empty_plane(pl1) << std::endl;
	std::cout << "pl2 is an empty plane: " << empty_plane(pl2) << std::endl;
	std::cout << "pl1 and pl2 are parallel: " << parallel(pl1, pl2) << std::endl;
	std::cout << "pl1 and pl2 are perpendicular: " << perpendicular(pl1, pl2) << std::endl;

	return 0;
}