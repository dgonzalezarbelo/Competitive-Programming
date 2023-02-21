#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
#pragma warning (disable:4996)

bool solve(){
    int a, b;
    scanf("%d.%d", &a, &b);
    if(a == -1) return false;
    int suma = a * 100 + b;
    int max = suma, min = suma, domingo;
    string diamax, diamin;
    diamax = diamin = "MARTES";
    for(int i = 3; i <= 7; i++){
        scanf("%d.%d", &a, &b);
        if(a * 100 + b > max){
            if(i == 2) diamax = "MARTES";
            else if (i == 3) diamax = "MIERCOLES";
            else if (i == 4) diamax = "JUEVES";
            else if (i == 5) diamax = "VIERNES";
            else if (i == 6) diamax = "SABADO";
            else diamax = "DOMINGO";
            max = a * 100 + b;
        }
        if(a * 100 + b < min){
            if(i == 2) diamin = "MARTES";
            else if (i == 3) diamin = "MIERCOLES";
            else if (i == 4) diamin = "JUEVES";
            else if (i == 5) diamin = "VIERNES";
            else if (i == 6) diamin = "SABADO";
            else diamin = "DOMINGO";
            min = a * 100 + b;
        }
        suma += a * 100 + b;
        if(i == 7) domingo = a * 100 + b;
    }
    cout << diamax << ' ' << diamin << ' ';
    if(double(domingo) > (double)suma / 6.0) cout << "SI\n";
    else cout << "NO\n";
    return true;
}

int main(){
    while(solve());
    return 0;
}