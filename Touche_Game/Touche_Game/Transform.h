#pragma once
#include "Entity.h"

class Transform :
	public Component
{
public:
	float x, y;
	int w, h;
	float rot;

	bool Transform::init(float X, float Y, int W, int H, float R = 0.0);
	void Transform::setPosition(int X, int Y);
	void Transform::setCenterPosition(int X, int Y);
	void Transform::move(float x, float y);
	
	int Transform::getX();
	int Transform::getY();
	int Transform::getW();
	int Transform::getH();
};

