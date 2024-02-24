/*Write a program in C++ to use map associative container. The keys will be the names of states and the values will be the populations of the states.
 When the program runs, the user is prompted to type the name of a state. 
The program then looks in the map, using the state name as an index and returns the population of the state.*/


#include <iostream>
#include <map>

using namespace std;

int main() {
    // Create a map to store state names and their corresponding populations
    map<string, long long> population;

    // Initialize the map with data for five Indian states
    population["Maharashtra"] = 7026357;
    population["Rajasthan"] = 6578936;
    population["Karnataka"] = 6678993;
    population["Punjab"] = 5789032;
    population["West Bengal"] = 6676291;

    // Main menu loop
    int choice;
    string state;
    auto it = population.begin();

    do {
        // Display the menu
        cout << "*********** Menu ***********" << endl;
        cout << "1. Get population of a state" << endl;
        cout << "2. Add population of a state" << endl;
        cout << "3. Display Population" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle user's choice
        switch (choice) {
            case 1: // Get population
                cout << "Enter name of State: ";
                cin >> state;
                it = population.find(state); // Search for the state in the map
                if (it != population.end()) { // If found, display the population
                    cout << "Population of " << it->first << " is " << it->second << endl;
                } else { // If not found, inform the user
                    cout << "Key not Found." << endl;
                }
                break;

            case 2: // Add population
                cout << "Enter name of State: ";
                cin >> state;
                cout << "Enter population of the State: ";
                cin >> population[state]; // Add the new state-population pair to the map
                break;
            case 3: // Display the map
                for (auto i : population) { // Iterate through the map and print each state-population pair
                    cout << i.first << ": " << i.second << endl;
                }
                break;
            case 4: // Exit
                exit(0); // Terminate the program

            default: // Invalid choice
                cout << "Invalid Choice" << endl;
        }

        cout << "\n\n"; // Add a line break for better readability
    } while (choice != 4); // Continue the loop until the user selects 'Exit'

    return 0;
}

