#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <functional>

class Point : public sf::Drawable
{
public: 
	float x, y;

	Point(float boundX, float boundY, std::function<float(float)> line);

	int GetLabel() const { return lineFunction(x) > y ? 1 : -1; }

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	void SetMarker(bool value) { marker.setFillColor(value ? sf::Color::Green : sf::Color::Red); }

	operator std::vector<float>()
	{
		return { x, y };
	}

	std::string ToString() const { return "{ " + std::to_string(x), + " " + std::to_string(y) + " }"; }

private:
	sf::CircleShape shape;
	sf::CircleShape marker;
	std::function<float(float)> lineFunction;
};