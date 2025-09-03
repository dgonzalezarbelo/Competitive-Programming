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
#pragma warning (disable : 4996)
using namespace std;

string contrario(string animal) {
    char letra;
    animal[animal.size() - 1] == 'a' ? letra = 'o' : letra = 'a';
    return animal.substr(0, animal.size() - 1) + letra;
}

bool resuelveCaso() {
    int n;
    cin >> n;
    if (!n) return false;
    int parejas = 0, sueltos = 0, sobran = 0;
    unordered_map<string, int> animales;
    string animal;
    while (n--) {
        cin >> animal;
        if (animales.count(animal)) sobran++;
        else {
            animales[animal]++;
            if (animales.count(contrario(animal))) {
                parejas++;
                sueltos--;
            }
            else {
                sueltos++;
            }
        }
    }
    printf("%d %d %d\n", parejas, sueltos, sobran);
    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}