#include <stdio.h>
#include "eingabeTrafo.h"


int main()
{
	const int xDimension = 160;
	const int yDimension = 40;
	// Male einen schönen Rundbogen
	for (int y = 0; y < yDimension; ++y)
	{
		for (int x = 0; x < xDimension; ++x)
		{
			if(checkLocationPrint(x,y,xDimension,yDimension))
			{
				printf("#");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}
