#include <bits/stdc++.h>
using namespace std;

double f(double x){
    return pow(x, 3)+pow(x,2)+x+1;
}

double second_simpson_rule(double a, double b, int n){
    double h = (b-a)/n;
    double x[n] = {};
    int cont=0;
    for (double i = a; i < b; i+= h)
        x[cont++] = i;
    double somatorio = 0;
    for (int i = 1; i < n - 1; i++){
        if (i % 3 == 0)
            somatorio += 2* f(x[i]);
        else
            somatorio += 3*f(x[i]);
    }
    return (((3*h)/8)*(somatorio+f(x[0]) + f(x[n])));
}

int main(){
    double a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    cout << second_simpson_rule(a, b, n) << endl;
}
