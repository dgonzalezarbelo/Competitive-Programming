#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>

using namespace std;

// Función para convertir un número romano a decimal
int romanToDecimal(const string& roman) {
    map<char, int> roman_numerals = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
    int decimal = 0;
    int prev_value = 0;
    for (auto it = roman.rbegin(); it != roman.rend(); ++it) {
        int value = roman_numerals[*it];
        if (value < prev_value) {
            decimal -= value;
        } else {
            decimal += value;
        }
        prev_value = value;
    }
    return decimal;
}

// Función para convertir un número decimal a romano
string decimalToRoman(int decimal) {
    vector<pair<int, string>> values = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    string roman = "";
    for (const auto& p : values) {
        while (decimal >= p.first) {
            roman += p.second;
            decimal -= p.first;
        }
    }
    return roman;
}

bool resuelveCaso() {
    string input; cin >> input;
    if(!cin) return false;
    cout << decimalToRoman(romanToDecimal(input) + 1) << endl;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while(resuelveCaso());
    return 0;
}
