#pragma once

#include <IO_API/IO_API_3D.h>
#include <iostream>



void* tex;
void* mesh;
void IO_appStart() {
	// Ran at the start of our app...
	std::string path = IO_getDirData();
	path += "Textures/Bullet.png";
	//tex = IO_getTexture(path.c_str());
	path = IO_getDirData();
	path += "Meshes/Shield.obj";
	mesh = IO_getMesh(path.c_str());
}

void IO_appLoop() {
	// Ran every render frame of our app...
	/*IO_Point2Df points[] =
	{
		-0.5f, -0.5f,
		0.5f, -0.5f,
		0.0f, 0.5f
	};*/
	/*IO_Point2Df points[] =
	{
		-0.5f*50, -0.5f*50,
		0.5f, -0.5f*50,
		0.0f*50, 0.5f*50
	};*/
	/*IO_Point2Df points[] =
	{
		0.0f, 1.0f,
		1.0f, 1.0f,
		0.5f, 0.0f
	};
	for (uint32_t i = 0; i < 3; i++) {
		points[i].x *= 50;
		points[i].y *= 50;
		points[i].x += 50;
		points[i].y += 50;
	}
	IO_ColorR8G8B8 colors[] =
	{
		{255, 0, 0},
		{0, 255, 0},
		{0, 0, 255}
	};
	IO_drawTriangle2DRGBVertex(points, colors);*/
	//IO_drawRect(5, 5, 64, 64, 255, 125, 65, 255);
	//IO_drawTexture(tex, 5, 5, 64, 64);
	IO_drawMesh(mesh);
}

void IO_appEnd() {
	// Ran before quitting our app...
}