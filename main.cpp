#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
// You can remove any includes that you don't need. A lot of these are artifacts of the debugging process, and they're likely the things you'll need for your program anyway, so it isn't necessarily a problem to just leave them as they are.

// Change these to your liking. 
uint windowWidth {640};
uint windowHeight {360};
int maxFramerate {60};

int main() {
	
	// Create the clock and a time variable to store deltaTime.
	sf::Clock clock;
	sf::Time deltaTime;

	// Create the window.
	sf::Window window(sf::VideoMode({windowWidth,windowHeight}), "YourProject"); // The OpenGL context is created automatically when this is called. If you want to mess around with the context, check the SFML documentation.
	window.setFramerateLimit(maxFramerate); // Comment this line out for uncapped.
	// window.setVerticalSyncEnabled(true); 
	// Only one of setFramerateLimit and setVerticalSyncEnabled can be called. If you use one, comment the other out. 

	bool running {true};
	while (running) { // Primary execution loop. This will run for as long as the window is open. 

		while (const std::optional event = window.pollEvent()) { // This while-loop condition will only fail if there are no events left in the window.pollEvent() queue. Thus, for each iteration of this loop, until it fails, it pops one event off the queue, and holds onto it in the event variable...

			if (event->is<sf::Event::Closed>()) { // ... and if that event is sf::Event::Closed...
				running = false; // ... close the window.
			}
			// You can include other event handling here (like input handling, or maybe logic for if the window is to be resized, etc).

		} // If the program makes it out of this loop, that means we can start the actual logic of the frame.

		// This is the "draw step". It's where we actually draw everything to the screen.
		// 1. Clear the framebuffer.
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// 2. Draw everything to the framebuffer that you must.
		// draw calls go here :3

		// 3. Draw the framebuffer.
		window.display();

		// 4. Save the deltaTime and restart the clock.
		deltaTime = clock.restart();
	}

	return 0;
}
