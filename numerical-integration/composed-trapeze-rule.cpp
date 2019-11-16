#include <bits/stdc++.h>
using namespace std;


double f(double x){
    return 1/pow(x, 2);
}

double composed_trapeze_rule(double a, double b, double n){
    double h = (b - a) / n;
    double result = 0;
    for (double i = a; i < b - h; i += h)
        result += 2*f(i);
    return (h/2)*(result + f(a) + f(b));
}


int main(){
    double a, b, n;
    cin >> a >> b;
    cin >> n;
    cout << composed_trapeze_rule(a, b, n) << endl;
}
 
