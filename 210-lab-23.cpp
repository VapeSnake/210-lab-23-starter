#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"

using namespace std;

const int SZ_NAMES = 200,
    SZ_COLORS = 25,
    MAX_AGE = 20;

int select_goat(list <Goat> trip);
void delete_goat(list <Goat> &trip);
void add_goat(list <Goat> &trip, string[], string[]);
void display_trip(list <Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    list <Goat> trip; // Creat list of goats in group of goats (A trip!)

    return 0;
}

int main_menu() {
    cout << "*** GOAT MANAGER 3001 ***" << endl;
    cout << "[1] Add a goat" << endl;
    cout << "[2] Delete a goat" << endl;
    cout << "[3] List goats" << endl;
    cout << "[4] Exit" << endl;
    int choice;
    do { // Do while for input validation.
        cin >> choice;
        if (choice < 1 || choice > 4) {
            cout << "Invalid choice. Please try again: ";
        }
    } while (choice < 1 || choice > 4);
    return choice;
}
// create a goat with random name, age, and color and add to the list
void add_goat(list <Goat> &trip, string names[], string colors[]) {
    string name = names[rand() % SZ_NAMES];
    int age = rand() % MAX_AGE + 1;
    string color = colors[rand() % SZ_COLORS];
    trip.push_back(Goat(name, age, color));
}

// Let user select goat from list. Will be used for delete goat function.
int select_goat(list <Goat> trip) {
    int index = 1;
    for (const auto &goat : trip) { // Shows organized list of goats to choose.
        cout << "[" << index << "] " << goat.get_name() << endl;
        index++;
    }
    int choice;
    do {
        cout << "Select a goat: ";
        cin >> choice;
        if (choice < 1 || choice > index - 1) {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice < 1 || choice > index - 1);
    return choice;
}