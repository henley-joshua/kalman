#pragma once
#include <random>
#include <Eigen/Dense>

struct Measurement {
	double noisyPosition;
	double truePosition;
	double trueVelocity;
};

class Simulator {

public:

	Simulator(
		double dt = 0.1, double x0 = 0.0,
		double v0 = 60.0, double sigmaA = 2.0,
		double sigmaZ = 8.0, unsigned seed = std::random_device{}());

	Measurement step();

private:
	double dt_, sigmaA_, sigmaZ_;
	Eigen::Vector2d x_;
	Eigen::Matrix2d F_;
	Eigen::Vector2d G_;
	Eigen::RowVector2d H_;
	std::mt19937 rng_;
	std::normal_distribution<double> accelNoise_, measNoise_;
};
