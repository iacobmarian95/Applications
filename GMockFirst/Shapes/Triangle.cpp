#include "Triangle.h"



Triangle::Triangle()
{
}

double Triangle::computeArea() {
	std::cout << "Triangle Are : " << std::endl;
	return 0.5 * m_base * m_height;
}

void Triangle::initShape(int x, int y){
	//std::cout << "Type the base and height of the triangle....." << std::endl;
	//std::cin >> this->m_base >> this->m_height;

	m_base = x;
	m_height = y;
}

Triangle::~Triangle()
{
}
