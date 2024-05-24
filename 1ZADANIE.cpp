#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
using namespace std;
using storageT = map<string, map<string, map<string, vector<pair<string, int>>>>>;
using shelfT = map<string, map<string, vector<pair<string, int>>>>;
using sectionT = map<string, vector<pair<string, int>>>;
using rowT = vector<pair<string, int>>;


storageT initStorage(int numZones, int numShelves, int numSections, int numRows) {
	rowT row;
	for (size_t i = 1; i <= 10; i++) {
		row.push_back({ "Empty", 0 });
	}


	sectionT sections;
	for (size_t i = 1; i <= numSections; i++) {
		sections.insert({ to_string(i),row });

	}

	shelfT shelves;
	for (size_t i = 1; i <= numShelves; i++) {
		shelves.insert({ to_string(i), sections });
	}

	storageT zones;
	while (numZones != 0) {
		for (size_t i = 1; i <= 3; i++) {
			zones.insert({ "A" + to_string(i), shelves });
			numZones -= 1;
		}
		for (size_t i = 1; i <= 3; i++) {
			zones.insert({ "B" + to_string(i), shelves });
			numZones -= 1;
		}
		for (size_t i = 1; i <= 4; i++) {
			zones.insert({ "C" + to_string(i), shelves });
			numZones -= 1;
		}

	}
	
	return zones;
}

void ADD(string productName, int productAmount, string address, map<string, map<string, map<string, vector<pair<string, int>>>>>& storage) {
	map<int, int> realNumber = {{49, 0}, { 50, 1 }, { 51, 2 }, { 52, 3 }, { 53, 4}};
	string adresses = address; 
	string zoneID = adresses.substr(0, 2);
	string shelfID = adresses.substr(2, 1);
	string sectionID = adresses.substr(3, 1);
	
	
	int rowNum = realNumber[adresses[4]];
	pair<string, int> &cell = storage[zoneID][shelfID][sectionID][rowNum];
	if (cell.first != productName && cell.first != "Empty") {
		cout << "Wrong cell - another product stored inthere!" << endl << endl;
		cout << "-------------------- Choose command again --------------------" << endl;
	}
	else {
		if (cell.second + productAmount <= 10 && cell.second + productAmount > 0) {
			cell.first = productName;
			cell.second = productAmount;
			cout << "Added successfully" << endl;
			cout << "-------------------- Changes saved --------------------" << endl << endl;
		}
		else {
			cout << "-------------------- INCORRECT DATA INPUT --------------------" << endl << endl;
		}
	}
}

void REMOVE(string productName, int productAmount, string address, map<string, map<string, map<string, vector<pair<string, int>>>>>& storage) {
	map<int, int> realNumber = { {49, 0}, { 50, 1 }, { 51, 2 }, { 52, 3 }, { 53, 4} };
	string adresses = address; // convert vector to string

	string zoneID = adresses.substr(0, 2);
	string shelfID = adresses.substr(2, 1);
	string sectionID = adresses.substr(3, 1);
	int rowID = realNumber[adresses[4]];

	pair<string, int> &cell = storage[zoneID][shelfID][sectionID][rowID];
	if (cell.first != productName && cell.first != "Empty") {
		cout << "Wrong cell - another product stored inthere!" << endl << endl;
		cout << "-------------------- Choose command again --------------------" << endl;
	}else {
		if (cell.second - productAmount > 0) {
			cell.first = productName;
			cell.second -= productAmount;
			cout << "Removed succussfully ";
		}
		else if (cell.second - productAmount == 0) {
			cell.first = "Empty";
			cell.second = 0;
			cout << "-------------------- Changes saved --------------------" << endl << endl;
		}
		else {
			cout << "NOT ENOUGH OF PRODUCT TO REMOVE!!! " << endl;
		}
	}
}


void INFO(storageT& storage) {
	cout << endl << endl << "-------------------- Current info about storage --------------------" << endl << endl;
	vector<string> emptyCelladdress;
	vector<string> loadedCelladdress;


	double totalSum = 0.0;
	for (auto zone : storage) {
		double zoneSum = 0.0;
		for (auto shelf : zone.second) {
			for (auto section : shelf.second) {
				int i = 1;
				for (auto row : section.second) {
					string currentAddress = zone.first + shelf.first + section.first + to_string(i);
					if (row.first == "Empty" && row.second == 0) {
						emptyCelladdress.push_back(currentAddress);
					}
					else {
						loadedCelladdress.push_back(currentAddress);
					}
					i++;
					totalSum += row.second;
					zoneSum += row.second;
				}
			}
		}
		cout << zone.first << " is loaded for " << fixed << setprecision(2) << zoneSum/1500.0 << "% " << endl;
	}

	double result = (totalSum / 1500.0);
	cout << "storage space used (from max volume) - " << fixed << setprecision(2) <<  result << "%" << endl << endl;

	cout << "LOADED CELLS ADDRESSES: " << loadedCelladdress.size() << endl;
	for (string str : loadedCelladdress) {
		cout << str << " ";
	}

	cout << endl << endl <<"EMPTY CELLS ADDRESSES: " << emptyCelladdress.size() << endl;
	for (string str : emptyCelladdress) {
		cout << str << " ";
	}
	cout << endl << endl;
	cout << "-------------------- End of info --------------------" << endl << endl << endl;

	
}

bool AdressCorrect(string address, storageT& storage) {
	int counter = 0;
	if (address.substr(0, 1) == "A" || address.substr(0, 1) == "B" || address.substr(0, 1) == "C") {
		counter += 1;
	}
	if (stoi(address.substr(1, 1)) <= 3) {
		counter += 1;
	}
	if (stoi(address.substr(2, 1)) <= 3) {
		counter += 1;
	}
	if (stoi(address.substr(3, 1)) <= 1) {
		counter += 1;
	}
	 
	if (counter == 4) {
		return true;
	}
	else {
		return false;
	}
}


int main() {

	int numZones = 10;
	int numShelves = 3;
	int numSections = 1;
	int numRows = 5;
	storageT zones = initStorage(numZones, numShelves, numSections, numRows);

	map<string, int> commands = { {"INFO", 1 },{"ADD", 2},{"REMOVE", 3}};
	string input, productName, address;
	int productAmount;
	cout << "Available commands are: " << endl << endl << "[ INFO ] - to check out the storage " << endl << "[ ADD ] - to add product into storage by format" 
		<< " ||| PRODUCT NAME - AMOUNT - CELL ADDRESS |||" << endl;
	cout<< "[ REMOVE ] - to remove product from storage by format ||| PRODUCT NAME - AMOUNT - CELL ADDRESS |||" << endl << "[ END ] - to close the control programm " << endl << endl;
	
	while (true) {
		cin >> input;
		if (input == "END") {
			break;

		}
		else {
			switch (commands[input]) {
			case 1:
				INFO(zones);
				break;
			case 2:
				cout << "--------------------" << endl;
				
				cin >> productName >> productAmount >> address;
				if (AdressCorrect(address, zones) ){
					ADD(productName, productAmount, address, zones);
					break;
				}
				else {
					cout << "Wrong adress input! "<< endl;
				}
				
			case 3:
				cout << "--------------------" << endl;
				
				cin >> productName >> productAmount >> address;
				if (AdressCorrect(address, zones) ){
					REMOVE(productName, productAmount, address, zones);
					break;
				}
				else {
					cout << "Wrong adress input! " << endl;
					break;
				}
			}

		}

	}
	
	return 0;
}