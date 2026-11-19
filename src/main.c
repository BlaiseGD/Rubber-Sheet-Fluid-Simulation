#define RAYMATH_IMPLEMENTATION
#define _USE_MATH_DEFINES
#include "render.h"
#include "grid.h"
#include "raymath.h"
//#include "stdio.h" //for checking debugging through printing to console

int main(void){

	const int screenWidth = 1600;
	const int screenHeight = 900;
	const int gridWidth = 10;
	const int gridHeight = 10;

	const Vector3 origin = (Vector3){0.0f, 0.0f, 0.0f};

	//SetConfigFlags(FLAG_FULLSCREEN_MODE);		maybe later
	InitWindow(screenWidth, screenHeight, "3d camera free");
	Grid mainGrid;
	mainGrid.width = gridWidth;
	mainGrid.height = gridHeight;
	mainGrid.gridArray = (float*)malloc(sizeof(float) * mainGrid.width * mainGrid.height);

	float cameraX = 10.0f;
	float cameraY = 10.0f;
	float cameraZ = 10.0f;

	Camera3D camera = {0};
	//bc it's Y-up think of it as X: right-left, Y: up and down, Z: depth (forward/backward)
	camera.position = (Vector3){cameraX, cameraY, cameraZ};
	camera.target = origin;
	camera.up = (Vector3){0.0f, 0.0f, 1.0f}; //Raylib iy Y-up by default so its in xzy order here
	camera.fovy = 45.0f; //y fov is 45 deg
	camera.projection = CAMERA_PERSPECTIVE;

	Body cube;
	cube.shape = SHAPE_CUBE;
	cube.position = (Vector3){0.0f, 0.0f, 35.0f};
	cube.velocity = (Vector3){0.0f, 0.0f, 0.0f};
	cube.mass = 10.0f; 	//I just put in an arbitrary one for now
	cube.size = 2.0f;	//this is it's l, w, & h
	cube.color = RED;
	cube.outline_color = BLACK;

	EnableCursor();
	SetTargetFPS(60);
	float elapsedTime = 0.0f;
	while(!WindowShouldClose()){
		float dt = GetFrameTime();
		UpdateCamera(&camera, CAMERA_CUSTOM);
		if(IsKeyPressed(KEY_Z)){
			camera.position = Vector3RotateByAxisAngle(camera.position, (Vector3){0.0f, 0.0f, 1.0f}, 30.0f*DEG2RAD);
		}
		BeginDrawing();
		ClearBackground(RAYWHITE);
		BeginMode3D(camera);
			drawMesh();
			drawBody(&cube);
		EndMode3D();
		EndDrawing();
		elapsedTime += dt;	//may need this later
		updateBody(&cube, dt);
	}
	CloseWindow();
	return 0;
}
