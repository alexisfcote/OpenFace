#include <iostream>
#include <armadillo>
#include "filter.h"



//
namespace filter {
	Filter::Filter(float alpha)
	{
		std::cout << "Armadillo version: " << arma::arma_version::as_string() << std::endl;
		this->alpha = alpha;
		z = 0;
	}
	Filter::Filter(float alpha, float z)
	{
		std::cout << "Armadillo version: " << arma::arma_version::as_string() << std::endl;
		this->alpha = alpha;
		this->z = z;
	}

	Filter::~Filter()
	{
	}

	float Filter::filt(float val) {
		z = alpha*z + (1 - alpha)*val;
		return z;
	}

}

// Armadillo documentation is available at:
// http://arma.sourceforge.net/docs.html

// NOTE: the C++11 "auto" keyword is not recommended for use with Armadillo objects and functions