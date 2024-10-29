#include <SFML/Graphics.hpp>
#include "handlers.h"
#include "FileManager.h"
const int WINDOW_HEIGHT = 600;
const int WINDOW_WIDTH = 800;
const std::string WINDOW_NAME = "";
const std::string INPUT_FILE_NAME = "input.txt";
const std::string OUTPUT_FILE_NAME = "output.txt";

int main()
{
	// window creating
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME, sf::Style::Default, settings);

	// some work
	std::vector<std::shared_ptr<Shape>> shapes = LoadShapesFromFile(INPUT_FILE_NAME);
	SaveResultsToFile(shapes, OUTPUT_FILE_NAME);

	bool isMove = false;

	while (window.isOpen())
	{
		window.clear(sf::Color::White);
		ListenEvents(window, shapes, isMove);
		DrawShapes(window, shapes);
		window.display();
	}
}