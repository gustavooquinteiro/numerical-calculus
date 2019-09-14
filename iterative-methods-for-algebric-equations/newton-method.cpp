#include <bits/stdc++.h>
using namespace std;

double apply_second_derivative(double x){
    return 6*x;
}

double apply_derivative(double x){
    return 3*pow(x, 2) - 9;
}

double apply_function(double x){
    return pow(x, 3) - 9*x + 3;
}

bool verifica(double x){
    return apply_function(x) * apply_second_derivative(x) > 0;
}


double newtons_method(pair<double, double>interval, double precision){
    double x = interval.first - (apply_function(interval.first) / apply_derivative(interval.first));
    while(fabs(x - interval.first) >= precision){
        interval.first = x;
        x = interval.first - (apply_function(interval.first) / apply_derivative(interval.first));
    }
    return x;
}

int main(){
    double lower_bound, upper_bound;
    cout << "Insira o inicio e o fim do intervalo (separados por um espaço): ";
    cin >> lower_bound >> upper_bound;
    double precision;
    cout << "Insira a precisão: ";
    cin >> precision;
    pair<double, double> interval = make_pair(lower_bound, upper_bound);
    double point = interval.first;
    for (double i = interval.first; i < interval.second; i += 0.1){
        if (verifica(i)){
            point = i;
            break;
        }       
    }
    interval.first = point;
    double root = newtons_method(interval, precision);
    cout << "A raiz para x^3 - 9x + 3 no intervalo ("<<lower_bound<<", " << upper_bound << ") com precisão de " << precision << " é: " << root << endl; 
}
