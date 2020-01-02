#pragma once
#include<iostream>

class GeometricShape
{
public:
	virtual double computeArea() = 0;
	virtual void initShape(int x, int y) = 0;
	virtual ~GeometricShape() {

	}
};