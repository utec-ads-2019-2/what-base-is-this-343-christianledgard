#include <iostream>

using namespace std;

int val(char c){
    if (isdigit(c))
        return int(c) - '0';
    else
        return int(c) - 'A' + 10;
}

long convertidorABase10(string str, int base){
    int len = str.size(), power = 1, num = 0, i;

    for (i = len-1; i >= 0; i--){
        if (val(str[i]) >= base){
            return EXIT_FAILURE;
        }
        num += val(str[i]) * power;
        power = power * base;
    }
    return num;
}


int encontrarBaseMinima(string x){
    int t1, aux = 1;

    for (int i = 0; i <= x.size()-1; ++i) {
        if(isalpha(x[i])){
            t1 = int(x[i]) - 54;
        } else {
            t1 = int(x[i]) - 48 + 1;
        }

        if(t1>aux)
            aux = t1;
    }
    if(aux <= 2)
        return 2;
    if(aux >= 36)
        return 36;
    return aux;
}

void encontrarNumerosIguales(string a, string b){

    for (int i = encontrarBaseMinima(a); i <= 36; ++i) {
        for (int j = encontrarBaseMinima(b); j <= 36; ++j) {
            if(convertidorABase10(a,i) == convertidorABase10(b,j)){
                cout << a << " (base " << i << ") = " << b << " (base " << j << ")" << endl;
                return;
            }
        }
    }

    cout << a << " is not equal to " << b << " in any base 2..36" << endl;


}


int main() {
    string a;
    string b;

    while(cin >> a >> b){
        encontrarNumerosIguales(a,b);
    }


    return 0;
}