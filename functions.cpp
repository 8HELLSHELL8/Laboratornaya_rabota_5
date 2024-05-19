#include "functions.h"

template<typename T>
ostream& operator<<(ostream& os, vector<T> vec) {
    for (T elem : vec) {
        os << elem << " ";
    }
    return os;
}

void CREATE_TRAM(map<string, vector<string>>& Stops) {
    vector<string> tempVector;
    int tramName, stopsAmount;

    cin >> tramName;
    cin >> stopsAmount;

    for (size_t i = 1; i <= stopsAmount; i++) {
        string stopName;
        cin >> stopName;
        tempVector.push_back(stopName);
    }
    pair<string, vector<string>> preparedStop = { to_string(tramName), tempVector };
    Stops.insert(preparedStop);
}

void TRAMS_IN_STOP(map<string, vector<string>>& Stops, string stopName) {
    bool isCreated = 0;
    for (auto& pair : Stops) {
        for (auto& stop : pair.second) {
            if (stop == stopName) {
                isCreated = 1;
                break;
            }
        }
    }
    if (Stops.empty()) {
        cout << "Stops are absent" << endl;
        for (auto& stop : Stops) {
            cout << stop.first << " " << stop.second << endl;

        }
    }
    else {
        vector<string> tempVector;
        for (auto& stop : Stops) {
            for (auto i = 0; i < stop.second.size(); i++) {
                if (stop.second[i] == stopName) {
                    cout << stop.first << " ";
                    tempVector.push_back(stop.first);
                }
            }
        }
        cout << endl;
    }
}

void STOPS_IN_TRAM(map<string, vector<string>>& Stops) {
    string input;
    cin >> input;
    if (Stops.count(input) != 0) {
        for (auto& stopName : Stops[input]) {
            cout << "Stop " << stopName << ": ";
            bool foundRoute = false; // Переменная для отслеживания наличия других маршрутов
            for (const auto& pairS : Stops) {
                if (pairS.first != input) { // Проверка, чтобы не сравнивать с самим собой
                    for (const auto& route : pairS.second) {
                        if (route == stopName) {
                            cout << pairS.first << " "; // Вывод номера маршрута
                            foundRoute = true;
                            break; // Прерывание цикла после нахождения совпадения
                        }
                    }
                }
            }
            if (!foundRoute) {
                cout << "0"; // Если маршрут не найден, выводим "0"
            }
            cout << endl;
        }
    }
    else {
        cout << "Trams are absent" << endl;
    }
}

void TRAMS(map<string, vector<string>>& Stops) {
    if (Stops.size() == 0) {
        cout << "Trams are absent" << endl;
    }
    else {
        for (auto& stop : Stops) {
            cout << "TRAM " << stop.first << ": " << stop.second << endl;
        }
    }
}

void choise(map<string, vector<string>>& Stops, FunctionsType func) {
    string input;
    switch (func)
    {
    case FunctionsType::CREATE_TRAM:
        CREATE_TRAM(Stops);
        break;
    case FunctionsType::TRAMS_IN_STOP:

        cin >> input;
        TRAMS_IN_STOP(Stops, input);
        break;
    case FunctionsType::STOPS_IN_TRAM:
        STOPS_IN_TRAM(Stops);
        break;
    case FunctionsType::TRAMS:
        TRAMS(Stops);
        break;
    }
}
