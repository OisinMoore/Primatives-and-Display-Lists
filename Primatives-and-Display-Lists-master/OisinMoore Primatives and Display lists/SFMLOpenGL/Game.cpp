#include "Game.h"

// // Uncomment for Part 2
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
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

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

	 // Uncomment for Part 2
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
	 // Uncomment for Part 2
	 // ********************
}

void Game::update()
{

	 // Uncomment for Part 2
	 // ********************
	elapsed = clock.getElapsedTime();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (!flip)
		{
			flip = true;
			current++;
			if (current > primatives)
			{
				current = 1;
			}
		}
		else
			flip = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (!flip)
		{
			flip = true;
			current--;
			if (current < primatives)
			{
				current = 9;
			}
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
		glRotatef(1, 0.0f, 0.0f, 1.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		glRotatef(-1, 0.0f, 0.0f, 1.0f);
	}
	cout << "Update up" << endl;
	
	// Translation
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		glTranslatef(0.01f, 0.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		glTranslatef(-0.01f, 0.0f, 0.0f);
	}

	// Scale
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		glScalef(1.1f, 1.1f, 1.0f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		glScalef(0.9f, 0.9f, 1.0f);
	}
}

void Game::draw()
{

	 // Uncomment for Part 2
	 // ********************
	cout << "Draw up" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Investigate Here!!!!!

	cout << "Drawing Primative " << current << endl;
	glCallList(current);
	 // Uncomment for Part 2
	 // ********************

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}