#include <math.h>
#include <stdlib.h>
#include "eingabeTrafo.h"

const float PI = 3.14;

// Gib Werte zurück, ob an der gegebenen Position ein Zeichen ausgegeben werden soll
int checkLocationPrint(int x, int y, int xDim, int yDim)
{
	// x und y auf bildfläche bzgl. pi skalieren, damit kurve bild ausfüllt
	float scaledX = (double)x/(double)xDim;
	float scaledY = (double)y/(double)yDim*2.0 - 1 ;

	float sinValue = sin(scaledX*4*PI);
	if(fabs(scaledY-sinValue) < 0.075)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
