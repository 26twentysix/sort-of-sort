#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void coutLine(vector<double> line, size_t size, size_t i) {
	if (size == 0 || size == i) {
		return;
	}
	if (line[i] > 0) {
		cout << line[i] << " ";
	}
	coutLine(line, size, i + 1);
	if (line[i] < 0) {
		cout << line[i] << " ";
	}
}

int main() {
	setlocale(0, "");
	string line, path, tmp = "";
	vector<double> line1;
	int choice = 0;
	while (choice != 1 && choice != 2) {
		cout << "Выберите вариант ввода последовательности\n1 - Считывание заранее заданного файла\n2 - Ввод строки с клавиатуры\n";
		cin >> choice;
	}
	if (choice == 1) {
		cout << "Введите полный путь до файла: \n";
		cin >> path;
		ifstream in(path);
		if (in.is_open()) {
			getline(in, line);
		}
		in.close();
	}
	cin.ignore(32767, '\n');
	if (choice == 2) {
		cout << "Введите строку: \n";
		getline(cin, line);
	}
	line.push_back(' ');
	cout << "Изначальная строка: \n" << line << endl;
	size_t strSize = line.length();
	for (size_t i = 0; i < strSize; i++) {
		if (line[i] == ' ') {
			setlocale(LC_ALL, "ENGLISH");
			double push = stod(tmp);
			line1.push_back(push);
			tmp = "";
		}
		if (line[i] != ' ') {
			tmp.push_back(line[i]);
		}
		setlocale(0, "");
	}
	size_t size = line1.size();
	cout << "Строка после сортировки: \n";
	coutLine(line1, size, 0);
}
