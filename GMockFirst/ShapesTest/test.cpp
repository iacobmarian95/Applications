#include"gtest/gtest.h"
#include"gmock/gmock.h"

#include"ShapeFactory.h"


TEST(ShapeFactoryTest, CreateShapeMethod) {
	std::unique_ptr<GeometricShape> shape = ShapeFacory::createShape(1);
	ASSERT_TRUE(shape != nullptr);

	shape = ShapeFacory::createShape(2);
	ASSERT_TRUE(shape != nullptr);

	shape = ShapeFacory::createShape(5);
	ASSERT_TRUE(shape == nullptr);
}

TEST(RectangleTest, ComputeRectangleArea) {
	auto shape = ShapeFacory::createShape(2);
	shape->initShape(3, 10);
	ASSERT_TRUE(shape->computeArea() == 30.);
}

TEST(TriangleTest, ComputeTriangleArea) {
	auto shape = ShapeFacory::createShape(1);
	shape->initShape(5, 2);
	ASSERT_TRUE(shape->computeArea() == 5.);
}