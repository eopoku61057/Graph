#include <fstream>  // Include to open files
#include <cstddef>  // Include to use NULL, otherwise use nullptr
#include <iostream> // Include to print to the screen
#include <iomanip>
#include <vector>
#include "bst.hpp"     // The header file for our custom linked list class
using namespace std;

int main(int argc, char** argv)
{
	ifstream input;
	int cmd, argument, ret, i;
    vector<int> vec;

    // open stations file
    ifstream file;

    if(argc < 2)
    {
        cout << "useage: ./a1.out <cmd file>\n";
        return 0;
    }

	input.open(argv[1]);

    // while there is something to read from the file, read
	while (input >> cmd)
	{
        // switch on the command we read from the file
		switch (cmd)
		{
        // if the cmd requires a parameter, read it from the file and call the 
        // associated function
		case 1:
			input >> argument;
			file.open("stations.dat");
            if (!file)
            {
                cout << "There was a problem opening stations.dat." << endl;
            }
            while (file >> argument)
            vec.push_back(argument);

            cout << "count = " << vec.size() << endl;
            cout << "first = " << vec[0] << endl;
            cout << "last  = " << vec[vec.size() -1] << endl;

			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
        case 7
            break;
        }
	}
	input.close();

	return 0;
}
