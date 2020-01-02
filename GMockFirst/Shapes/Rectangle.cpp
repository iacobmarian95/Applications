#include "Rectangle.h"

Rectangle::Rectangle()
{
}

void Rectangle::initShape(int x, int y) {
	//std::cout << "Type the length and height of the rectangle....." << std::endl;
	//std::cin >> this->m_length >> this->m_height;
	
	m_length = x;
	m_height = y;
}

double Rectangle::computeArea() {
	std::cout << "Rectangle Area : " << std::endl;
	return m_height * m_length;
}

Rectangle::~Rectangle()
{
}
