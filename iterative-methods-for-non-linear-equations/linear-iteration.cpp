#include <bits/stdc++.h>
using namespace std;

double apply_function(double x){
    return pow(x, 3) - 9*x + 3;
}


double apply_phi(double x){
    return pow(x, 3)/ 9.0 + 1.0/3.0;
}

bool verifica(double x){
    return fabs(pow(x, 2) / 3.0) <= 1;
}

double linear_iteration(pair<double, double> interval, double point, double precision){
    if (fabs(apply_function(point)) < precision){
        return point;
    }
    while(true){
        double x = apply_phi(interval.first);
        if (fabs (x - interval.first) < precision)
            return x;
        interval.first = x;
    }
    return 0;
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
    
    double root = linear_iteration(interval, point, precision);
    
    cout << "A raiz para x^3 - 9x + 3 no intervalo ("<<lower_bound<<", " << upper_bound << ") com precisão de " << precision << " é: " << root << endl; 
}
