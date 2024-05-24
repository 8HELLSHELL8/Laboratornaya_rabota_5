//#include <iostream>
//#include <vector>
//#include <map>
//using namespace std;
//
//void CHANGE(map<string,string>& regions, string regionName, string regionCenter) {
//	//Создание нового региона, если такого региона нет
//	if (regions.count(regionName) == 0) { 
//		cout << "New region " << regionName << " with administrative center " << regionCenter << endl;
//		regions.insert({ regionName, regionCenter });
//	}
//	else if (regions.count(regionName) != 0 && regions[regionName] == regionCenter) {
//		cout << "Incorrect - this region with adm center is already created"<< endl;
//	}
//	else {
//		//Переименование центра региона, если такой регион уже существовал
//		cout << "Region " << regionName << " has changed its administrative center from " << regions[regionName] 
//			<< " to " << regionCenter << endl;
//		regions.insert({ regionName, regionCenter });
//	}
//}
//
////Переименование региона
//void RENAME(map<string, string>& regions, string oldRegionName,string newRegionName) {
//	pair<string, string> boofer;
//
//	//Если введенного региона не существует или новое имя соответствует старому, то ошибка
//	if (regions.count(newRegionName) != 0 || oldRegionName == newRegionName) {
//		cout << "Incorrect " << endl;
//	}
//	else {
//		boofer = { oldRegionName , regions[oldRegionName] };
//		cout << oldRegionName << " has been renamed to " << newRegionName << endl;
//		regions.erase(oldRegionName);
//		regions.insert({ newRegionName, boofer.second });
//	}
//}
//
//
////Вывод центра данного региона, если такой существует
//void ABOUT(map<string, string>& const regions, string regionName) {
//	if (regions.count(regionName) == 0) {
//		cout << "Incorrect" << endl;
//	}
//	else {
//		cout << regionName << " has administrative center " << regions[regionName] << endl;
//	}
//}
//
////Вывод всех регионов и их центров, в формате Регион - Город
//void ALL(map<string, string>& const regions) {
//	if(regions.size() != 0){ //проверка на пустоту, если не пустой вывод всех регионов и их центров
//		for (auto& element : regions) {
//			cout << element.first << " - " << element.second << endl;
//		}
//	}
//	else {
//		cout << "No regions added yet!"<< endl;
//	}
//}
//
//
//int main() {
//	map<string, string> regions = {};
//	int amountOfOperations;
//	string operation, regionName, regionCenter, oldRegionName;
//
//
//	cin >> amountOfOperations; //ввод
//	for (size_t i = 1; i <= amountOfOperations; i++) { //Обработка ввода
//		cin >> operation;
//		if (operation == "CHANGE") {
//			cin >> regionName;
//			cin >> regionCenter;
//			CHANGE(regions, regionName, regionCenter);
//		}
//		else if (operation == "RENAME") {
//			cin >> oldRegionName;
//			cin >> regionName;
//			RENAME(regions, oldRegionName, regionName);
//		}
//		else if (operation == "ABOUT") {
//			cin >> regionName;
//			ABOUT(regions, regionName);
//		}
//		else if (operation == "ALL") {
//			ALL(regions);
//		}
//		else {
//			cout << "Wrong input! ";
//		}
//	}
//
//	return 0;
//}