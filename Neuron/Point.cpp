#include "Point.h"

Point::Point(float boundX, float boundY, std::function<float(float)> line)
{
	x = (float)rand() / RAND_MAX * boundX;
	y = (float)rand() / RAND_MAX * boundY;
	lineFunction = line;

	float radius = 6.f;

	shape.setFillColor(GetLabel() == 1 ? sf::Color::Yellow : sf::Color::Blue);
	shape.setRadius(radius);
	shape.setOrigin(radius, radius);
	shape.setPosition(x, y);

	marker.setRadius(radius / 2);
	marker.setOrigin(radius / 2, radius / 2);
	marker.setPosition(x, y);
	marker.setFillColor(sf::Color::Transparent);
}

void Point::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(shape);
	target.draw(marker);
}
