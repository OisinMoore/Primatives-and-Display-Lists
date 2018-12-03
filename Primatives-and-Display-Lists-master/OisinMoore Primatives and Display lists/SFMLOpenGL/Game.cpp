#include "Game.h"

// // Bool i use to change the shape
// // ********************
bool flip = false;
int current = 1;
// // ********************

 Game::Game() : window(VideoMode(800, 600), "OpenGL"), primatives(10)
{
	 // Uncomment for Part 2
	 // ********************
	 index = glGenLists(primatives);
	 // ********************
	 std::cout << "W = Move Up, S = Move Down" << std::endl;
	 std::cout << "A = Move Left, D = Move Right" << std::endl;
	 std::cout << "Up = Rotate Clockwise, Down = rotate Anti-clockwise" << std::endl;
	 std::cout << "Right = Scale Up, Left = Scale Down" << std::endl;
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		//cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}

		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	 // Draws each shape using openGl
	 // ********************
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);


	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, -2.0, -5.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 1, GL_COMPILE);
	glBegin(GL_POINTS);
	{
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.2, 0.0, -2.0);
		glVertex3f(-2.0, -2.0, -2.0);
		glVertex3f(2.0, -2.0, -2.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 2, GL_COMPILE);
	glBegin(GL_LINES);
	{
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-0.7f, -0.6f, -2.0);
		glVertex3f(0.7f, 0.6f, -2.0);
		
	}
	glEnd();
	glEndList();

	glNewList(index + 3, GL_COMPILE);
	glBegin(GL_LINE_STRIP);
	{
		
		glColor3f(1.0f, 7.0f, 2.0f);
		glVertex3f(0.1, 0.4, -2.0);
		glVertex3f(0.2, -0.4, -2.0);
		glVertex3f(0.3, -0.4, -2.0);
		glVertex3f(0.4, 0.4, -2.0);
		glVertex3f(0.5, 0.4, -2.0);
		glVertex3f(0.6, 0.4, -2.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 4, GL_COMPILE);
	glBegin(GL_LINE_LOOP);
	{
		glColor3f(9.0f, 4.0f, 0.0f);
		glVertex3f(-0.7, 0.4, -2.0);
		glVertex3f(-0.5, -0.4, -2.0);
		glVertex3f(-0.3, -0.4, -2.0);
		glVertex3f(-0.1, 0.4, -2.0);
		glVertex3f(0.1, 0.4, -2.0);
		glVertex3f(0.3, -0.4, -2.0);
		glVertex3f(0.5, -0.4, -2.0);
		glVertex3f(0.7, 0.4, -2.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 5, GL_COMPILE);
	glBegin(GL_TRIANGLE_STRIP);
	{
		glColor3f(1.0f, 0.0f, 8.0f);
		glVertex3f(-0.7, 0.4, -2.0);
		glVertex3f(-0.5, -0.4, -2.0);
		glVertex3f(-0.3, -0.4, -2.0);
		glVertex3f(-0.1, 0.4, -2.0);
		glVertex3f(0.1, 0.4, -2.0);
		glVertex3f(0.3, -0.4, -2.0);
		glVertex3f(0.5, -0.4, -2.0);
		glVertex3f(0.7, 0.4, -2.0);
	}
	glEnd();
	glEndList();
	
	glNewList(index + 6, GL_COMPILE);
	glBegin(GL_TRIANGLE_FAN);
	{
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-0.4, 0.0, -2.0);
		glVertex3f(-0.2, -0.4, -2.0);
		glVertex3f(0.0, -0.5, -2.0);
		glVertex3f(0.2, -0.6, -2.0);
		glVertex3f(0.4, 0.4, -2.0);
		glVertex3f(0.6, 0.5, -2.0);
		glVertex3f(0.8, 0.6, -2.0);
		
	}
	glEnd();
	glEndList();

	glNewList(index + 7, GL_COMPILE);
	glBegin(GL_QUADS);
	{
		glColor3f(4.0f, 0.0f, 8.0f);
		glVertex3f(0.0, 0.0, -2.0);
		glVertex3f(0.2, -0.2, -2.0);
		glVertex3f(0.4, 0.2, -2.0);
		glVertex3f(0.6, -0.4, -2.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 8, GL_COMPILE);
	glBegin(GL_QUAD_STRIP);
	{
		glColor3f(1.0f, 9.0f, 15.0f);
		glVertex3f(-0.4, -0.4, -2.0);
		glVertex3f(0.0, 0.2, -2.0);
		glVertex3f(0.4, 0.2, -2.0);
		glVertex3f(0.8, -0.4, -2.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 9, GL_COMPILE);
	glBegin(GL_POLYGON);
	{
		glColor3f(2.0f, 8.0f, 0.0f);
		glVertex3f(-0.2, 0.6, -2.0);
		glVertex3f(-0.1, 0.5, -2.0);
		glVertex3f(-0.1, 0.2, -2.0);
		glVertex3f(-0.2, 0.1, -2.0);
		glVertex3f(-0.4, 0.1, -2.0);
		glVertex3f(-0.5, 0.2, -2.0);
		glVertex3f(-0.5, 0.5, -2.0);
		glVertex3f(-0.4, 0.6, -2.0);
		
		
	}
	glEnd();
	glEndList();
	 // ********************
}

void Game::update()
{

	 // Sets numbers for each shape to be drawn
	 // ********************
	elapsed = clock.getElapsedTime();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
	{
		if (!flip)
		{
			flip = true;
			current = 1;

		}
		else
			flip = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
	{
		if (!flip)
		{
			flip = true;
			current = 2 ;

		}
		else
			flip = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
	{
		if (!flip)
		{
			flip = true;
			current = 3;

		}
		else
			flip = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
	{
		if (!flip)
		{
			flip = true;
			current = 4;

		}
		else
			flip = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
	{
		if (!flip)
		{
			flip = true;
			current = 5;

		}
		else
			flip = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
	{
		if (!flip)
		{
			flip = true;
			current = 6;
		}
		else
			flip = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7))
	{
		if (!flip)
		{
			flip = true;
			current = 7;
		}
		else
			flip = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8))
	{
		if (!flip)
		{
			flip = true;
			current = 8;
		}
		else
			flip = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9))
	{
		if (!flip)
		{
			flip = true;
			current = 9;
		}
		else
			flip = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0))
	{
		if (!flip)
		{
			flip = true;
			current = 10;
		}
		else
			flip = false;
	}

	if (flip)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}
	 // ********************
	 // Rotation
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		glRotatef(0.1, 0.0f, 0.0f, 1.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		glRotatef(-0.1, 0.0f, 0.0f, 1.0f);
	}
	//cout << "Update up" << endl;
	
	// Translation
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		glTranslatef(-0.005f, 0.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		glTranslatef(0.005f, 0.0f, 0.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		glTranslatef(0.0f, 0.005f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		glTranslatef(0.0f, -0.005f, 0.0f);
	}

	// Scale
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		glScalef(1.01f, 1.01f, 1.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		glScalef(0.99f, 0.99f, 1.0f);
	}
}

void Game::draw()
{

	 // Draws current shape
	 // ********************
	//cout << "Draw up" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Investigate Here!!!!!

	//cout << "Drawing Primative " << current << endl;
	glCallList(current);
	 // Uncomment for Part 2
	 // ********************

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}