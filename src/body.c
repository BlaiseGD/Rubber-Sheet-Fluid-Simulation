#include "body.h"
#include "physics.h"


float bodyVolume(const Body *b){
	//DEFAULT CASE ASSUMED CUBE
	switch(b->shape){
		case SHAPE_CUBE:
			return b->size * b->size * b->size; 
		case SHAPE_SPHERE:
			return (4.0f/3.0f) * PI * b->size * b->size * b->size;
		default:
			return b->size * b->size * b-> size;
	}
}

float bodyDragCoeff(const Body *b){
	//DEFAULT CASE ASSUMED CUBE
	switch(b->shape){
		case SHAPE_CUBE:
			return 1.05;
		case SHAPE_SPHERE:
			return 0.47;
		default:
			return 1.05;
	}
}

float bodyHalfHeight(const Body *b){
	//DEFAULT CASE ASSUMED CUBE
	switch(b->shape){
		case SHAPE_CUBE:
			return b->size / 2;
		case SHAPE_SPHERE:
			return b->size / 2;
		default:
			return b->size / 2;
	}

}

void updateBody(Body *b, float dt){
	b->velocity.z -= GRAVITY * dt;		//9.81 m/s/s * time (s) --> acceleration (m/s/s) --> velocity (m/s)
	b->position.z += b->velocity.z * dt;	//same case m/s * s = m
	float floorZ = bodyHalfHeight(b);	//determines half shape height for collision checking
	if(b->position.z < floorZ){
		b->velocity.z = 0.0f;
		b->position.z = floorZ;
	}
}
