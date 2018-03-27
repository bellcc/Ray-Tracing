#include <map>
#include <string>
#include "Defs.h"
#include "Utilities.h"

int main(int argc, char *argv[]) {
	float a = 0, b = 1;
	swap(a, b);
	std::cout << a << " " << b << std::endl;

	std::cout << normalizeDegrees(0) << std::endl; // --> 0
	std::cout << normalizeDegrees(1) << std::endl; // --> 1
	std::cout << normalizeDegrees(-1) << std::endl; // --> 359
	std::cout << normalizeDegrees(-721) << std::endl; // --> 1

	std::cout << normalizeRadians(0) << std::endl; // --> 0
	std::cout << normalizeRadians(1) << std::endl; // --> 1
	std::cout << normalizeRadians(3 * M_PI) << std::endl; // --> M_PI
	std::cout << normalizeRadians(-31 * M_PI) << std::endl; // --> M_PI

	std::cout << rad2deg(0) << std::endl; // --> 0
	std::cout << rad2deg(180) << std::endl; // -> M_PI
	std::cout << rad2deg(360) << std::endl; //
	std::cout << rad2deg(-720) << std::endl; // --> -M_2PI


	return 0;
}
