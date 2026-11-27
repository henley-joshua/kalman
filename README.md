# Kalman

## Compiling

Run the following command from the project root to compile and run the program in linux:

```g++ -I deps/eigen -Wall src/filter/main.cpp src/filter/simulate.cpp -o simulator```

This will create an output binary 'simulator' which can be run using the command './simulator'
In its current state, this will loop through 51 iterations of stepping through simulated measurement data, printing the noisy position measurement along with the "actual" values

## Simulator

The simulator class exists to provide pseudo-random data to the kalman filter. This class acts as a measurement tool that would gather real data and supply it to the filter.
The simulator uses random's std::mt19937 to generate a pseudo-random value, and then std::normal_distribution turns this values into Gaussian noise according to the normal distribution, as a Kalman filter would expect.

std::random_device exists to generate a random seed each run so that no two runs are the same. In any case, this value exists in the constructor for testing purposes. Repeating the same seed multiple times can allow for confirming fixes/changes to the Kalman filter have worked with the same data. Down the line, this could potentially open the door to visualizing how changing variances affects the filter's results compared to the actual position of the measured object.

## Dependencies

The current implementation uses the eigen library, stored as a submodule in the 'deps' folder. Since this only depends on the standard library and is all header files, compilation only needs to include the eigen folder to succeed.
