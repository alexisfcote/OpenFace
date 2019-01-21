#include <iostream>
#include "Filter.h"

// Armadillo documentation is available at:
// http://arma.sourceforge.net/docs.html

// NOTE: the C++11 "auto" keyword is not recommended for use with Armadillo objects and functions

int main(int argc, char** argv)
{
	filter::Filter filt = filter::Filter(0.95);

	for (size_t i = 0; i < 50; i++)
	{
		std::cout << filt.filt(1) << std::endl;
	}
	return 0;
}