/* Copyright (C) 2019 Avery King <avery98@pm.me>
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
/* lines.hpp
 *
 *
 * This file contains the basic functionallity of Lines. It includes
 * what to do if the user selects a certain option in the main screen,
 * if the user wants to go back to the main menu, etc.
 *
 **/
#include <iostream>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
#include "liblines/liblines.hpp"
using namespace std;

// Function declarations
/*void coordinate(double xcoor1, double ycoor1, double xcoor2, double ycoor2);
void slope(double xcoor, double ycoor, double slope);
void generate_points(double slope, double y_intercept, int max_number, int starting_number);
void generate_point(double slope, double y_intercept, int number);
void write_generated_points_to_file(double slope, double y_intercept, int max_number, int starting_number, string file_name);

//void main_screen(string custom_data, string prompt_type);
void options(vector<string> option); // For use later on
*/

// Global variables
string answer;

vector<string> prompt() {
  vector<string> commands;
  string usr_input;

  cout << ">> ";
  getline(cin, usr_input);

  // Split the input and save it into 'commands'
  boost::split(commands, usr_input, boost::is_any_of(" "));
  return commands;
}

void options(vector<string> option) {
  if (option[0] == "coordinate") { // "coordinate" command
    double xcoor1, ycoor1, xcoor2, ycoor2;

    // Get the coordinate points from the user
    cout << "Enter coordinate point 1: ";
    cin >> xcoor1 >> ycoor1;

    cout << "Enter coordinate point 2: ";
    cin >> xcoor2 >> ycoor2;

    // Calculate the equation and so with two coordinate points
    coordinate(xcoor1, ycoor1, xcoor2, ycoor2);

    // Return to the prompt
    vector<string> commands = prompt();
    options(commands);
  }

  else if (option[0] == "slope") { // "slope" command
    // Variables
    double xcoor, ycoor, slope_value;

    // Get the slope from the user
    cout << "Enter the slope of the graph: ";
    cin >> slope_value;

    // Get the coordinate points from the user
    cout << "Enter the coordinate point to use: ";
    cin >> xcoor >> ycoor;

    // Calculate the equation
    slope(xcoor, ycoor, slope_value);

    // Return to the prompt
    vector<string> commands = prompt();
    options(commands);
  }

  else if (option[0] == "gencoor") { // "gencoor" command
    // Variables
    double y_intercept;
    double slope;
    int max_number;
    int starting_number;

    if (option[1] == "") { // default option
      // Get the y-intercept and slope
      cout << "What is the slope? ";
      cin >> slope;

      cout << "What is the y-intercept? ";
      cin >> y_intercept;

      cout << "What number do you want to start at? ";
      cin >> starting_number;

      // Get the amount of coordinate points the user wants
      cout << "What number should be the maximum generated (no decimals)? ";
      cin >> max_number;

      generate_points(slope, y_intercept, max_number, starting_number);

      // Return to the prompt
      vector<string> commands = prompt();
      options(commands);
    }

    else if (option[1] == "single") {
      double slope;
      double y_intercept;
      double number;

      // Get the slope
      cout << "What is the slope and y-intercept? ";
      cin >> slope >> y_intercept;

      // Get the number the user wants to use for x
      cout << "What is the number that x will be? ";
      cin >> number;

      // Generate a certain amount of coordinate points
      generate_point(slope, y_intercept, number);
    }

    else if (option[1] == "write") {
      // Get the and slope
      cout << "What is the slope and y-intercept? ";
      cin >> slope >> y_intercept;

      // Get the number the user wants to start at
      cout << "What number do you want to start at? ";
      cin >> starting_number;

      // Get the amount of coordinate points the user wants
      cout << "What number should be the maximum generated (no decimals)? ";
      cin >> max_number;

      cout << "The file will be named Coordinate Points.txt\n";
      cout << "It will be saved to your desktop\n\n";

      #ifdef __unix__
        write_generated_points_to_file(slope, y_intercept, max_number, starting_number, "~/Desktop/Coordinate Points.txt");
        // system("mv \"Coordinate Points.txt\" ~/Desktop");
      #elif _WIN32
        write_generated_points_to_file(slope, y_intercept, max_number, starting_number, "%userprofile%\\Desktop\\Coordinate Points.txt");
        // system("move \"Coordinate Points.txt\" %userprofile%\\Desktop");
      #endif

      // Return to the prompt
      vector<string> commands = prompt();
      options(commands);
    }

    else {
      cout << "Unknown option: " << option[1] << endl;
    }
  }

  else if (option[0] == "about") { // "about" command
    cout << "====================================\n";
    cout << "\t  Lines v2.1.1\n";
    cout << "====================================\n";
    cout << "  Copyright (C) 2019 Avery King\n\n";

    cout << "Partially made during a Xoads live stream. Thanks to everyone who supported\n";
    cout << "me when I showed them this calculator. I would like to thank my friends,\n";
    cout << "classmates, and my parents! THANK YOU SO MUCH!!!\n\n";

    cout << "Lines  Copyright (C) 2019  Avery King\n";
    cout << "This program comes with ABSOLUTELY NO WARRANTY; for details type `copyright'.\n";
    cout << "This is free software, and you are welcome to redistribute it\n";
    cout << "under certain conditions; type `copyright' for details.\n";

    // Return to the prompt
    vector<string> commands = prompt();
    options(commands);
  }

  else if (option[0] == "help") { // "help" command
    cout << "Available commands:\n";
    cout << "\t* coordinate\n";
    cout << "\t* slope\n";
    cout << "\t* gencoor:\n";

    cout << "\t\t- No option (default)\n";
    cout << "\t\t- write\n";
    cout << "\t\t- single\n";

    cout << "\t* about\n";
    cout << "\t* copyright\n";
    cout << "\t* exit\n";

    cout << "For more help on these commands, and for more help on Lines,\n";
    cout << "please visit the Lines wiki\n";

    // Return to the prompt
    vector<string> commands = prompt();
    options(commands);
  }

  else if (option[0] == "copyright") { // "copyright command"
    cout << "The swiss army knife for linear graphs.\n\n";
    cout << "Copyright (C) 2019  Avery King\n";
    cout << "This program is free software: you can redistribute it and/or modify\n";
    cout << "it under the terms of the GNU General Public License as published by\n";
    cout << "the Free Software Foundation, either version 3 of the License, or\n";
    cout << "(at your option) any later version.\n\n";
    cout << "This program is distributed in the hope that it will be useful,\n";
    cout << "but WITHOUT ANY WARRANTY; without even the implied warranty of\n";
    cout << "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n";
    cout << "GNU General Public License for more details.\n\n";
    cout << "You should have received a copy of the GNU General Public License\n";
    cout << "along with this program.  If not, see <https://www.gnu.org/licenses/>.\n";

    // Return to the prompt
    vector<string> commands = prompt();
    options(commands);
  }

  else if (option[0] == "exit") { // "exit" command
    cout << "Bye!\n";
    exit(0);
  }

  else if (option[0] == "") { // If nothing was entered
    // Return to the prompt
    vector<string> commands = prompt();
    options(commands);
  }

  else { // Unknown commands
    cout << "'" << option[0] << "'" << " is not a command" << endl;

    // Return to the prompt
    vector<string> commands = prompt();
    options(commands);
  }
}

