#include <bits/stdc++.h>
using namespace std;


double f(double x){
    return 1/pow(x, 2);
}

double simple_trapeze_rule(double a, double b){
    double h = b - a;
    return (h/2)*(f(a) + f(b));
}


int main(){
    double a, b, x;
    cin >> a >> b;
    cout << simple_trapeze_rule(a, b) << endl;
}
