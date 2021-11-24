/*!**************************************************************************/
/*	\file 		ComputeMean_Parallel_Programming.cpp
 *
 *	\description 	Computes mean of a set of pre-defined sensor readings. Multi-threading concept is used to perform this task.
 *	\author		Pradeep Siddagangaiah
 *	\date		24-November-2020
 */
/***************************************************************************/

#include <iostream>
#include <cstdio>
#include <thread>

static double SUM;
static int COUNTER;

class SensorReading {

public:
	SensorReading(){}
	void operator()(int x)
	{
		SUM += x;
		COUNTER++;
	}

	void computeMean() {
		std::cout << SUM / COUNTER << std::endl;
	}
};
int main(int argc, char *argv[]) {
	SensorReading sensorReading;
	for (float i = 0; i < 10; i += 0.5) {
		// Enter sensor readings
		std::thread th1(sensorReading,i);
		th1.join();
	}

	// Compute the mean of all the sensor readings
	sensorReading.computeMean();

	std::cin.get();

	return 0;
}
