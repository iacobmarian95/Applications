#pragma once
#include"GeometricShape.h"
#include"iostream"

class Triangle : public GeometricShape
{
public:
	Triangle();
	double computeArea() override;
	void initShape(int x, int y) override;
	~Triangle();
	
private:
	int m_base;
	int m_height;
};

