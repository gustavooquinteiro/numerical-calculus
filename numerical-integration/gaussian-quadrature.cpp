#include <bits/stdc++.h>
using namespace std;


map<int, pair<vector<double>, vector<double>>> tabela_gauss;

void init(){
    tabela_gauss[1] = make_pair(vector<double>{0}, vector<double>{2});
    tabela_gauss[2] = make_pair(vector<double>{-0.5773, 0.5773}, vector<double>{1});
    tabela_gauss[3] = make_pair(vector<double>{-0.7745, 0.7745, 0}, vector<double>{0.5555, 0.5555, 0.8888});
    tabela_gauss[4] = make_pair(vector<double>{-0.8611, 0.8611, -0.3399, 0.3399}, vector<double>{0.3478, 0.3478, 0.6521, 0.6521});
}


double F(double x){
    return pow(x, 2) - 5;
}

double gaussian_quadrature(double a, double b, int pontos){

    vector<double> t = tabela_gauss[pontos].first;
    vector<double> A = tabela_gauss[pontos].second;
    double sum = 0;
    double h = (b-a)/pontos;
    for (int i = 0; i < pontos; i++)
        sum += A[i]*h*F(t[i]);
    return sum;
}

int main(){
    init();
    double a, b;
    cin >> a >> b;
    int pontos;
    cin >> pontos;
    cout << gaussian_quadrature(a, b, pontos) << endl;
}
