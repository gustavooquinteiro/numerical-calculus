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


double string_method(pair<double, double>points, double precision){
    if (fabs(apply_function(points.first)) < precision)
        return points.first;
    if (fabs(apply_function(points.second)) < precision || fabs(points.second - points.first) < precision)
        return points.second;
    double a = points.first;
    points.first = points.second;
    points.second = a;
    double xk = apply_function(points.first);
    points.second = points.first - (xk/(xk - apply_function(points.second))) * (points.first - points.second);
    cout << points.first << " " << points.second << endl;
    while(fabs(apply_function(points.second)) >= precision || fabs(points.second - points.first) >= precision){
        double a = points.first;
        points.first = points.second;
        points.second = a;
        double xk = apply_function(points.first);
        points.second = points.first - (xk/(xk - apply_function(points.second))) * (points.first - points.second);
    }
    return points.second;
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
    double root = string_method(interval, precision);
    cout << "A raiz para x^3 - 9x + 3 no intervalo ("<<lower_bound<<", " << upper_bound << ") com precisão de " << precision << " é: " << root << endl; 
}
