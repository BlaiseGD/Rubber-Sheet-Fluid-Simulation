#include "render.h"
#include "raylib.h"
//#include "raymath.h" will likely need
#include "rlgl.h"

void drawBody(const Body *b){
	//DEFAULT CASE IS CUBE
	switch(b->shape){
		case SHAPE_CUBE:
			DrawCube(b->position, b->size, b->size, b->size, b->color);
			DrawCubeWires(b->position, b->size, b->size, b->size, b->outline_color);
			break;
		case SHAPE_SPHERE:
			DrawSphere(b->position, bodyHalfHeight(b), b->color);
			DrawSphereWires(b->position, bodyHalfHeight(b), 6, 6, b->outline_color);
			break;
		default:
			DrawCube(b->position, b->size, b->size, b->size, b->color);
			DrawCubeWires(b->position, b->size, b->size, b->size, b->outline_color);
			break;
	}
}


void drawMesh(){
	rlPushMatrix();
	rlRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	DrawGrid(10, 1.0f); //how the grid is subdivided, distance between each subdivision (10x10, 1.0 spacing)
	rlPopMatrix();
}
