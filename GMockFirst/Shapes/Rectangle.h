#pragma once
#include"GeometricShape.h"
#include<iostream>

class Rectangle : public GeometricShape 
{
public:
	Rectangle();
	double computeArea() override;
	void initShape(int x, int y) override;
	~Rectangle();
private:
	int m_height;
	int m_length;
};

