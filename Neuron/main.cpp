#include <SFML/Graphics.hpp>
#include "Neuron.h"
#include <vector>
#include <iostream>
#include "Point.h"

void TrainNeuron(Neuron & n, std::vector<Point> & points, bool train = true);

int main()
{
	int number;
	Neuron n(2);
	std::cout << "Neuron guesses wether point is below or above y = 2 * x + 5\n";
	std::cout << "Insert number of points: \n";
	std::cin >> number;
	std::cout << "Press + to increase learning rate, press - to decrease learning rate\n";
	std::cout << "Current learning rate: " + std::to_string(n.GetLearningRate()) << "\n";
	std::cout << "Press any other button to train the neuron (one iteration)\n";

	srand((unsigned int)time(nullptr));
	sf::RenderWindow window(sf::VideoMode(500, 500), "neuron");

	std::string before = n.ToString();

	std::vector<Point> points;
	for(int i = 0; i < number; ++i)
		points.emplace_back(500.f, 500.f, [](float x) { return 2 * x + 5; });

	TrainNeuron(n, points, false);


	while(window.isOpen())
	{
		sf::Event e;
		while(window.pollEvent(e))
		{
			if(e.type == sf::Event::Closed)
				window.close();
			if(e.type == sf::Event::KeyPressed)
			{
				switch(e.key.code)
				{
				case sf::Keyboard::Add:
					n.ChangeLearningRate(0.05f);
					std::cout << "Current learning rate: " + std::to_string(n.GetLearningRate()) << "\n";
					break;
				case sf::Keyboard::Subtract:
					n.ChangeLearningRate(-0.05f);
					std::cout << "Current learning rate: " + std::to_string(n.GetLearningRate()) << "\n";
					break;
				case sf::Keyboard::Escape:
					window.close();
					break;
				default:
					TrainNeuron(n, points);
					break;
				}
			}
		}

		window.clear();

		for(auto & p : points)
			window.draw(p);

		window.display();
	}

	return 0;
}


void TrainNeuron(Neuron & n, std::vector<Point> & points, bool train)
{
	static int iteration = 0;
	int wrong = 0, right = 0;
	for(auto & p : points)
	{
		bool ok;
		ok = p.GetLabel() == n.Guess(p, p.GetLabel(), train);
		p.SetMarker(ok);
		
		wrong += ok ? 0 : 1;
		right += ok ? 1 : 0;
	}

	std::cout << "iteration : " << iteration << ", results: \n" <<
		"wrong: " << wrong << "\n" <<
		"right: " << right << "\n";

	++iteration;
}
