#include "header1.h"
#include <math.h>

double Box::volume(double num) {
	return height * width * length*num;
}

double Box::diagonal() {
	return sqrt(height * height + width*width + length*length );
}

Box::Box(double lengthVal,double widthVal,double heightVal){
	length = lengthVal;
	width = widthVal;
	height = heightVal;
}