#include <SFML/Graphics.hpp>
#include "Header.h"
#include "functions.h"
#include "bat.h"
#include "text.h"
#include "brick.h"
#include "ball.h"
#include "brickrow.h"

using namespace sf;
int main()
{
	RenderWindow window(
		VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
		WINDOW_TITLE,
		Style::Titlebar | Style::Close
	);
	window.setFramerateLimit(60);

	Ball ball;
	ballInit(ball);
	Bat bat;
	batInit(bat);
	Textobj scoreText;
	TextobjInit(scoreText, ball.score);
	BrickField field;
	brickFieldInit(field);


	while (window.isOpen())
	{
		
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		
		ballUpdate(ball);
		batUpdate(bat);
		TextobjUpdate(scoreText, ball.score);
		brickFieldUpdate(field);

		
		ballCollidedWithBat(ball, bat);
		ballCollidedWithBricks(ball, field);


		window.clear();
		brickFieldDraw(window, field);
		ballDraw(window, ball);
		batDraw(window, bat);
		textDraw(window, scoreText);
		window.display();
	}

	return 0;
}