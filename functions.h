#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

enum class FunctionsType {
    CREATE_TRAM,
    TRAMS_IN_STOP,
    STOPS_IN_TRAM,
    TRAMS
};

void CREATE_TRAM(map<string, vector<string>>& Stops);
void TRAMS_IN_STOP(map<string, vector<string>>& Stops, string stopName);
void STOPS_IN_TRAM(map<string, vector<string>>& Stops);
void TRAMS(map<string, vector<string>>& Stops);
void choise(map<string, vector<string>>& Stops, FunctionsType func);

