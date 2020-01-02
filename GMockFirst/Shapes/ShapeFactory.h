#pragma once
#include"Triangle.h"
#include"Rectangle.h"

class ShapeFacory {
public:
	static std::unique_ptr<GeometricShape> createShape(int type);
private:
	ShapeFacory();
};

std::unique_ptr<GeometricShape> ShapeFacory::createShape(int type) {
	switch (type)
	{
	case 1:
		return std::move(std::make_unique<Triangle>());
	case 2:
		return std::move(std::make_unique<Rectangle>());
	default:
		break;
	}

	return nullptr;
}