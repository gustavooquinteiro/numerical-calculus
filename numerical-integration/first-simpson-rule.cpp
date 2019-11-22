#include <bits/stdc++.h>
using namespace std;

double f(double x){
    return pow(x,3) + pow(x, 2) + x + 1;
}

double first_simpson_rule(double a, double b, int n){
    double h = (b-a)/n;
    vector<double> x;
    double result = 0;
    for (int i = 0; i <= n; i++)        
        x.push_back(a + i*h);
    double somatorio = 0;
    for (int i =1; i <= n/2; i++){
        somatorio += f(x[2*i-1]);
    }
    result += 4*somatorio;
    somatorio = 0;
    for (int i =1; i< n/2; i++){
        somatorio += f(x[2*i]);    
    }
    result += 2*somatorio;
    return (h/3)*(result + f(x[0]) + f(x[n]));
}

int main(){
    double a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    cout << first_simpson_rule(a, b, n) << endl;
}
