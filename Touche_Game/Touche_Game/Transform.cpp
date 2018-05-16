#include "Transform.h"

bool Transform::init(float X, float Y, int W, int H, float R)
{
	x = X;
	y = Y;
	w = W;
	h = H;
	rot = R;
	return true;
}

void Transform::setPosition(int X, int Y)
{
	x = X;
	y = Y;
}

void Transform::setCenterPosition(int X, int Y)
{
	x = X - (w / 2);
	y = Y - (h / 2);
}

void Transform::move(float X, float Y)
{
	x += X;
	y += Y;
}

int Transform::getX()
{
	return (int)x;
}

int Transform::getY()
{
	return (int)y;
}

int Transform::getW()
{
	return w;
}

int Transform::getH()
{
	return h;
}