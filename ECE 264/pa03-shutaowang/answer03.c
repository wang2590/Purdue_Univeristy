#include "pa03.h"
double integrate1(Range rng)
{

	double deltaX = (rng.upperlimit - rng.lowerlimit) / rng.intervals;
	double height = 0;
	double sumIntegral = 0;
	for(int i = 0;i < rng.intervals;i++)
	{
		double width =(deltaX * i + rng.lowerlimit ); 
		height = func(width);
		sumIntegral += height * deltaX;
	} 
	return sumIntegral;
	//Perform numerical integration of the function func(x)
	//INPUT: Range rng -- the lower and upper limits of the integration
	//                    and the number of intervals to integrate over
	//OUTPUT: Return the result of the integration

}

void integrate2(RangeAnswer * rngans)
{
	rngans -> answer = integrate1(rngans -> rng);

	//Perform numerical integration of the function func(x)
	//INPUT: RangeAnswer * rngans 
	//              -- the lower and upper limits of the integration
	//                 and the number of intervals to integrate over
	//OUTPUT: The result of the integration should be placed in rngans->answer

	//You should try to call integrate1 when implementing integrate2
}
