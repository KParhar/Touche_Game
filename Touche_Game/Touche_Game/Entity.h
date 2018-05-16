#pragma once
#include <map>

class Component {};

class Entity
{
public:
	std::map<char*, Component*> components;

	void addComponent(char* name, Component* c);
	Component* getComponent(char* name);
};


