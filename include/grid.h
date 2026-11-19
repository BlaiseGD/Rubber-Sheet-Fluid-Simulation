#ifndef GRID_H
#define GRID_H
#pragma once
#include "stdlib.h"

//grid will be defined as square (at base)
typedef struct{
	int width;
	int height;
	int i;			//index helper for x
	int j;			//index helper for y
	float* gridArray;	//declare the grid array with float values
}Grid;

#endif


