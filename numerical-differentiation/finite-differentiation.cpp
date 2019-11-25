#include <bits/stdc++.h>
using namespace std;

vector<double> x;
vector<double> y;

double f(double x){
    return log(x);
}

double preencher_vector(double a, double b, int n){
    double h = (b-a)/n;
    for (int i = 0; i < n; i++){
        x.push_back(a + h*i);
        y.push_back(f(a+h*i));
    }
    return h;
}

double progressive_differentiate(int indice, double h){
    double lower =  2 * h;
    return (1/lower)*(-3*f(x[indice]) + 4*f(x[indice]+h) - f(x[indice]+2*h));
}

double central_differentiate(int indice, double h){
    double lower = 2*h;
    return (1/lower)*(f(x[indice]+h) - f(x[indice]-h));
}

double regressive_differentiate(int indice, double h){
    double lower = 2*h;
    return (1/lower)*(f(x[indice]-2*h) -4*f(x[indice] - h) + 3*f(x[indice]));
}

int main(){
    double a, b;
    cin >> a >> b;
    int n;
    cin >> n;
    int indice = floor(n/2);
    double h = preencher_vector(a, b, n);
    cout << "Diferenciação progressiva = "<< progressive_differentiate(indice, h) << endl;
    cout << "Diferenciação central = " <<central_differentiate(indice, h) << endl;
    cout << "Diferenciação regressiva = "<< regressive_differentiate(indice, h) << endl;
}
