#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <deque>
#include <numeric>
#include <algorithm>
#include <climits>
#pragma warning (disable : 4996)
using namespace std;

using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<pair<int, int>>;
using ll = long long;
using vll = vector<long long int>;

int getNumVocales(string str) {
    int cont = 0;
    for (int i = 0; i < str.length(); i++) {
        char c = tolower(str[i]);
        if (isalpha(c)) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                cont++;
            }
        }
    }
    return cont;
}

string descodificar(string codificada, int desplazamiento) {

    string decodificada = "";
    int letterValue;
    char c, newLetter;

    for (int i = 1; i < codificada.length(); i++) {

        c = tolower(codificada[i]);

        if (isalpha(c)) {

            letterValue = c + desplazamiento;
            if (letterValue < 97) {
                letterValue = 123 - (97 - letterValue);
            }
            else if (letterValue > 122) {
                letterValue = 96 + (letterValue - 122);
            }

            newLetter = (char)letterValue;
            if (isupper(codificada[i])) {
                newLetter = toupper(newLetter);
            }

            decodificada += newLetter;
        }
        else {
            decodificada += c;
        }

    }

    return decodificada;
}

int calcularDesplazamiento(char codigo) {

    codigo = tolower(codigo);

    int left = (codigo < 'p')
        ? -((codigo - 'a') + (123 - 'p'))
        : -(codigo - 'p');
    int right = (codigo > 'p')
        ? (('z' - codigo) + ('p' - 96))
        : ('p' - codigo);

    return (abs(left) <= right) ? left : right;
}

int main() {
    
    bool keep = true;
    string codificada, decodificada;
    int desplazamiento, vocales;

    while (keep) {
        getline(cin, codificada);
        desplazamiento = calcularDesplazamiento(codificada[0]);

        decodificada = descodificar(codificada, desplazamiento);

        if (decodificada == "FIN") {
            keep = false;
        }
        else {
            vocales = getNumVocales(decodificada);
            cout << vocales << '\n';
        }

    }
    return 0;
}