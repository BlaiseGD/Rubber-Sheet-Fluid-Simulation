#include "grid.h"
#include "raylib.h"

void drawMesh(int w, int h, camera3D c){

	grid mainGrid;
	mainGrid.width = w;
	mainGrid.height = h;
	mainGrid.gridArray = (float*)malloc(sizeof(float) * w * h);

	while(!WindowShouldClose()){

	UpdateCamera(&c, CAMERA_CUSTOM); //pass camera referenced, and mode
	if(IsKeyPressed(KEY_Z)){
		c.position = Vector3RotateByAxisAngle((Vector3){0.0f, 30.0f*sin(30.0f*DEG2RAD), 0.0f}, c.position, 30.0f * DEG2RAD);
	}
	BeginDrawing();
	ClearBackground(RAYWHITE);
		BeginMode3D(camera);
			DrawCube((Vector3){0.0f, 0.0f, 0.0f}, 2.0f, 2.0f, 2.0f, RED); //the startPos then lwh
			DrawCubeWires((Vector3){0.0f, 0.0f, 0.0f}, 2.0f, 2.0f, 2.0f, MAROON); //same thing but just the outline of mesh
			DrawGrid(10, 1.0f); //how the grid is subdivided, distance between each subdivision
		EndMode3D();
	EndDrawing();
	}
}
