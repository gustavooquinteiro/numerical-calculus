#include <bits/stdc++.h>
using namespace std;

float apply_func(float x){
    // Insira aqui a função desejada
    return pow(x, 2) + x - 2.4;
}

pair<float, float> bissection_method(pair<float, float> interval, float precision){
    int max_iteration = (log2(interval.second - interval.first) - log2(precision));
    int n = 1;
    while(n < max_iteration){
        if (abs(interval.second - interval.first) < precision)
            return interval;
        float middle = (interval.first + interval.second) / 2;
        if (apply_func(interval.first) * apply_func(middle) > 0)
            interval.first = middle;
        else
            interval.second = middle;
        n++;
    }
    return interval;
}


int main(){
    float lower_bound, upper_bound;
    cout << "Insira o inicio e o fim do intervalo (separados por um espaço): ";
    cin >> lower_bound >> upper_bound;
    float precision;
    cout << "Insira a precisão: ";
    cin >> precision;
    pair<float, float> interval = make_pair(lower_bound, upper_bound);
    
    interval = bissection_method(interval, precision);
    
    float root = (interval.first + interval.second) / 2;
    cout << "A raiz para x^2 + x - 2.4 no intervalo ("<<lower_bound<<", " << upper_bound << ") com precisão de " << precision << " é: " << root << endl; 
    
}
