#include <iostream>
#include <string.h>
#include <windows.h>

// I know conio is outdated. Can't get ncurses to work
#include <conio.h>
#include "Dependencies/Renderlib.h"



// The main function starts here
int main() { 
	
	std::cout<< "Welcome to mini adventure land. Please enter a name for your character:\n";
	char character_name[20];
	bool is_name_chosen = true;
	while (is_name_chosen) {
		std::cin.get(character_name, 20);
		test_for_exit(character_name);
		cleared();
		lowercase(character_name);
		character_name[0] = toupper(character_name[0]);
		std::cout<< "Your name is " << character_name << std::endl << "Do you want to keep it? (y/n): ";
		if (tolower(getchar()) == 'y') {
			is_name_chosen = false;
		} else {
			std::cout << "Please input your new character name: " << std::endl;
			cleared();
		}
	
	}

	std::cout<< "Perfect! This game is a small adventure game where you can explore a 32 by 32 area." << std::endl
	<< "The terminal will display your position using text for the 256 pixels\n" << std::endl
	<< "The blue pixel is you" << std::endl;

	// In the future: \nThe red pixels are ennemies\nThe green pixels are passive creatures


	// The loop for the game is started
	char command;
	short character_position[2] = {10,10};
	while (true) {
		command = getch();
		if (command == int('w')&&character_position[1] != 0) {
			character_position[1]--;
		} else if (command == int('a')&&character_position[0] != 0) {
			character_position[0]--;
		} else if (command == int('s')&&character_position[1] != 29) {
			character_position[1]++;
		} else if (command == int('d')&&character_position[0] != 31) {
			character_position[0]++;

		} else if (command == 'n') {
			exit(3);
		}
		render_scene(create_scene(character_position));
	}
	return 0;
}
