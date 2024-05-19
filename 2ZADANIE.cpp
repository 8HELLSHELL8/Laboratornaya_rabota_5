#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
ostream& operator<< (ostream& os, vector<T>& vec) {
	
	for (auto element : vec) {
		os << element << " ";
	}

	return os;
}

struct person {
	int time;
	string talon;
};

auto ENQUEUE(int mins, int counter, vector<person>& queue) {
	string talon = "T" + to_string(counter+1);
	queue.push_back({ mins,talon });
	cout << ">>> " << queue[counter].talon << endl;
}

auto DISTRIBUTE(int windows, vector<person>& queue) {
	vector<pair<int, vector<string>>> windowslist;
	for (size_t i = 0; i < windows; i++) {
		windowslist.push_back({ 0, {""}}); // Generaciya okon
	}

	
	
	while (queue.size() != 0) {
		int minTime = 1000000;
		int minTindex = -1;
		for (size_t i = 0; i < windowslist.size(); i++) {
			if (windowslist[i].first <= minTime) {
				minTime = windowslist[i].first;
				minTindex = i;
			}
		}

		windowslist[minTindex].first += queue[queue.size() - 1].time;
		windowslist[minTindex].second.push_back(queue[queue.size()-1].talon);
		queue.erase(queue.begin() + queue.size() - 1);
	}
	
	int counter = 1;
	for (pair<int, vector<string>> okno : windowslist) {
		cout << ">>> Window number " << counter << " ("<<okno.first<<" mins): ";
		cout << okno.second << endl;
		counter += 1;
	}

}


int main() {
	vector<person> queue;
	int openWins;
	cout << ">>> Input windows amount "<< endl;
	cout << "<<< ";
	cin >> openWins;
	int counter = 0;
	while (true) {
		cout << "<<< ";
		string input;
		cin >> input;
		if (input == "ENQUEUE") {
			int time;
			cin >> time;
			ENQUEUE(time, counter, queue);
		}
		else if (input == "DISTRIBUTE") {
			DISTRIBUTE(openWins, queue);
			break;
		}
		else {
			cout << "Error appeared try again!" << endl;
		}
		counter++;

	}

	return 0;
}