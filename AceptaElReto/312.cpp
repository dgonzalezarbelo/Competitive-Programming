#include <iostream>
#pragma warning (disable : 4996)

long long int MCD(long long int a, long long int b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a > b)
        return MCD(a - b, b);
    return MCD(a, b - a);
}

bool resuelveCaso() {
    long long int num;
    scanf("%lld", &num);
    if (!num) return false;
    long long int mcd = num, suma = 1, new_mcd;
    scanf("%lld", &num);
    while (num) {
        if (num % mcd != 0)  new_mcd = MCD(mcd, num);
        else new_mcd = mcd;
        suma = suma * (mcd / new_mcd) + num / new_mcd;
        mcd = new_mcd;
        scanf("%lld", &num);
    }
    printf("%lld\n", suma);
    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}