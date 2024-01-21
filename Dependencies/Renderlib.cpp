#include <windows.h>
#include <iostream>

// Clears the buffer stream (input stream)
void cleared() {
	while (getchar() != '\n');
}

// Makes a character array into lowercase
void lowercase(char x[]) {
	int i = 0;
	while (i < strlen(x)) {
		x[i] = tolower(x[i]);
		i++;
	}
}

//Test to see if the user inputed an "exit" command
void test_for_exit(char x[]) {
	char test_for_exit_variable;
	if (strcmp(x, "exit") == 0||strcmp(x, "close") == 0 ||strcmp(x, "done") == 0 ||strcmp(x,"stop") == 0 ||strcmp(x,"terminate") == 0 ||strcmp(x,"finish") == 0 ||strcmp(x,"null") == 0 ||strcmp(x,"halte") == 0) {
		std::cout<< "Are you sure you want to close the game (y/n):\n **All progress wil be lost** \n";
		cleared();
		test_for_exit_variable = tolower(getchar());
		if (test_for_exit_variable == 'y') {
			std::cout<< "The game has closed successfully" << std::endl;
			exit(2);
		} else {
			std::cout<< "The game has continued" << std::endl;
		}
	}
}


// Defining global variable frame if frame is not already defined
#ifndef frame
short frame[960];
#endif

//Takes a value from -1 to 3 and changes the color of the terminal accordingly
void color_mapping(short input_color) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (input_color == -1) {
		SetConsoleTextAttribute(hConsole, 15);
	} else if (input_color == 0) {
		SetConsoleTextAttribute(hConsole, 32);
	} else if (input_color == 1) {
		SetConsoleTextAttribute(hConsole, 144);
	} else if (input_color == 2) {
		SetConsoleTextAttribute(hConsole, 240);
	} else if (input_color == 3) {
		SetConsoleTextAttribute(hConsole, 192);
	}
}

//Renders a 32 (width) by 30 (height) image in the terminal using colored double spaces
void render_scene(short x[960]) {
	int temp_render_scene = -1;
	for (int r = 0; r < 960;r++) {
		if (r%32 == 0) {
			color_mapping(-1);
			std::cout<< std::endl;
			temp_render_scene = -1;
		}	
		if (temp_render_scene != x[r]) {
			color_mapping(x[r]);
		} 
		std::cout << "  ";
		temp_render_scene = x[r];
	}
}

// This is the funciton you want to modify to create diffrent images.
//As is, this funciton takes the position of a hypothetical object and colors the square which corresponds to that position
void reset_variable_frame() {

    // This loop resets the variable "frame" to being completely zeros.
	// I would like to find a faster way to do this
    for (int i; i < 960; i = i + 16) {
        frame[0 + i] = 0;
        frame[1 + i] = 0;
        frame[2 + i] = 0;
        frame[3 + i] = 0;
        frame[4 + i] = 0;
        frame[5 + i] = 0;
        frame[6 + i] = 0;
        frame[7 + i] = 0;
        frame[8 + i] = 0;
        frame[9 + i] = 0;
        frame[10 + i] = 0;
        frame[11 + i] = 0;
        frame[12 + i] = 0;
        frame[13 + i] = 0;
        frame[14 + i] = 0;
        frame[15 + i] = 0;
    }
}

// This is the funciton you will most likely want to modify. It is the one that determins how pixels are colored.
short* create_scene(short position[2]) {

    // Using the function from earlier to reset the global variable "frame" to zeros
	// If you disable the reset_variable_frame this turns the progam into a drawing program.
    reset_variable_frame();

    // This colors the correct pixel to represent position
	frame[position[0]+position[1]*32] = 1;
	short* scene_pointer = frame;
	return scene_pointer;
}
