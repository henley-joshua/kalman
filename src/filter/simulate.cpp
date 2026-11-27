#include <iostream>
#include "simulate.hpp"


Simulator::Simulator(double dt, double x0, double v0,
		     double sigmaA, double sigmaZ, unsigned seed) 
	: dt_(dt), sigmaA_(sigmaA), sigmaZ_(sigmaZ), x_(x0, v0),
	  rng_(seed), accelNoise_(0.0, sigmaA),
	  measNoise_(0.0, sigmaZ)
{
	F_ << 1, dt,
	      0, 1;
	G_ << 0.5 * dt * dt, dt;
	H_ << 1, 0;
}

Measurement Simulator::step() {
	x_ = F_ * x_ + G_ * accelNoise_(rng_);
	double z = (H_ * x_)(0) + measNoise_(rng_);
	return {z, x_(0), x_(1)};
}
