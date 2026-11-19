#ifndef BODY_H
#define BODY_H
#pragma once

#include "raylib.h"

//defining shapes that a body can take
typedef enum{
	SHAPE_SPHERE,
	SHAPE_CUBE
}Shape; 

//defining a generic body with those attributes
typedef struct{
	Shape shape;
	Vector3 position;
	Vector3 velocity;
	float mass;
	float size;
	Color color;
	Color outline_color;
}Body;

//some prototypes for things that will come in handy during physics calculations.
float bodyVolume(const Body *b);
float bodyDragCoeff(const Body *b);
float bodyHalfHeight(const Body *b);
void updateBody(Body *b, float dt);

#endif
