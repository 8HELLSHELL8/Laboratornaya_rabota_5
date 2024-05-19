#include <iostream>
#include "functions.h"



int main() {
    map<string, vector<string>> Stops;
    string input;
    while (true) {
        cin >> input;
        if (input == "CREATE_TRAM") {
            choise(Stops, FunctionsType::CREATE_TRAM);
        }
        else if (input == "TRAMS_IN_STOP") {
            choise(Stops, FunctionsType::TRAMS_IN_STOP);
        }
        else if (input == "STOPS_IN_TRAM") {
            choise(Stops, FunctionsType::STOPS_IN_TRAM);
        }
        else if (input == "TRAMS") {
            choise(Stops, FunctionsType::TRAMS);
        }
        else if (input == "END") {
            break;
        }
        else {
            cout << "WRONG INPUT!";
        }
    }
    return 0;
}

