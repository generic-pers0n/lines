/* Copyright (C) 2019 Avery King <avery98@pm.me>
 *
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
#include <lines/liblines.h>
#include <lines/util.h>

namespace Util {
  ///////////////////// Get failsafe prompt option /////////////////////
  void get_failsafe_option(vector<string> option) {
    if (option[0] == "continue") {
      cout << "Attempting to continue...\n";
    }

    else if (option[0] == "exit") {
      cout << "Exiting...";
    }

    else {
      cerr << "Unknown command\n";

      // Return to the prompt
      vector<string> input = prompt();
      get_failsafe_option(input);
    }
  }

  void get_failsafe_option_single(string option) {

  }
  //////////////////////////////////////////////////////////////////////

  void get_single_option(string option) {
    if (option == "slope") {
      double xcoor1, ycoor1, xcoor2, ycoor2;

      // Get the coordinate points from the user
      cout << "Enter coordinate point 1: ";
      cin >> xcoor1 >> ycoor1;

      cout << "Enter coordinate point 2: ";
      cin >> xcoor2 >> ycoor2;

      // Calculate the equation and so with two coordinate points
      coordinate(xcoor1, ycoor1, xcoor2, ycoor2);

      // Return to the prompt (for single prompt)
      string option = single_prompt();
      get_single_option(option);
    }

    else if (option == "about") {
      cout << "====================================\n";
      cout << "Lines v3.0 dev\n";
      cout << "====================================\n";
      cout << "(C) 2019 Avery King\n";
      cout << "Lines, the Swiss Army knife for Linear Graphs\n";
      cout << "Partially made during a Xoads live stream\n";
      cout << "We miss you, Xoads!\n\n";

      cout << "Lines  Copyright (C) 2019  Avery King\n";
      cout << "This program comes with ABSOLUTELY NO WARRANTY; for details type `copyright'.\n";
      cout << "This is free software, and you are welcome to redistribute it\n";
      cout << "under certain conditions; type `copyright' for details.\n\n";

      // Return to the prompt (for single prompt)
      string option = single_prompt();
      get_single_option(option);
    }

    else {
      cerr << option << " is not a command.\n";
    }
  }

  void get_option(vector<string> option) {

  }
}
