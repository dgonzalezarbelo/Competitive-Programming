#include <iostream>
#include <vector>
#include <string>

int resolver(std::vector <char> const& v, int & index) {
	if (v[index] != '+' && v[index] != '-' && v[index] != '*' && v[index] != '/') {
		index++;
		return int(v[index - 1]) -'0';
	}
	else {
		if (v[index] == '+') {
			index++;
			return int(resolver(v, index)) + int(resolver(v, index));
		}
		else if (v[index] == '-') {
			index++;
			return int(resolver(v, index)) - int(resolver(v, index));
		}
		else if (v[index] == '*') {
			index++;
			return int(resolver(v, index)) * int(resolver(v, index));
		}
		else if (v[index] == '/') {
			index++;
			return int(resolver(v, index)) / int(resolver(v, index));
		}
	}

}

void resuelveCaso() {
	std::vector <char> v;
	std::string linea;
	std::getline(std::cin, linea);
	for (int i = 0; i < linea.size(); i++) {
		if (linea.at(i) != ' ' && linea.at(i) != '\n') v.push_back(linea.at(i));
	}
	int index = 0;
	std::cout << resolver(v, index) << '\n';
}

int main() {
	int numCasos;
	std::cin >> numCasos;
	std::cin.ignore(3, '\n');
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}