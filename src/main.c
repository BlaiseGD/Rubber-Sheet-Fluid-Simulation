#include "raylib.h"
#define RAYMATH_IMPLEMENTATION
#define _USE_MATH_DEFINES
#include "raymath.h"
#include "math.h"

int main(void){
	const int screenWidth = 800;
	const int screenHeight = 450;
	const Vector3 origin = (Vector3){0.0f, 0.0f, 0.0f};
	
	InitWindow(screenWidth, screenHeight, "3d camera free");

	
	float cameraX = 10.0f;	//r*cos(theta)
	float cameraY = 10.0f;	//r*sin(theta)
				//No Z bc height doesn't vary (could add later?

	//the radius is just the camera distance from the origin
	int radius = cameraX;
	Camera3D camera = {0};
	camera.position = (Vector3){10.0f, 10.0f, 10.0f};
	camera.target = origin;
	camera.up = (Vector3){0.0f, 1.0f, 0.0f};
	camera.fovy = 45.0f; //y fov is 45 deg
	camera.projection = CAMERA_PERSPECTIVE;


	Vector3 cubePosition = {0.0f, 0.0f, 0.0f};

	DisableCursor();
	SetTargetFPS(60);

	while(!WindowShouldClose()){
		UpdateCamera(&camera, CAMERA_CUSTOM); //pass camera referenced, and mode
		if(IsKeyPressed(KEY_Z)){
			camera.position = Vector3RotateByAxisAngle((Vector3){0.0f, 30.0f*sin(30.0f*DEG2RAD), 0.0f}, camera.position, 30.0f * DEG2RAD);
		}

		BeginDrawing();
		ClearBackground(RAYWHITE);

		BeginMode3D(camera);
			DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED); //the startPos then lwh
			DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON); //same thing but just the outline of mesh
			DrawGrid(10, 1.0f); //how the grid is subdivided, distance between each subdivision
		EndMode3D();
		EndDrawing();

	}
	CloseWindow();
	return 0;
}
