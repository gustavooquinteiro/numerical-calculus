#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
double tabela[MAX][2];
double diferenca[MAX][MAX];

void preenche_tabela(int n){
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < 2; j++){
            cin >> tabela[i][j];
        }
    }
    
    int ordem = 1;
    for (int i = 0; i < n - 1; i ++){
        double denominador = tabela[i+ordem][0] - tabela[i][0];
        double numerador = tabela[i+1][1] - tabela[i][1];
        diferenca[i][ordem] = numerador / denominador;
    }
    ordem++;
    int diff = 2;
    for (int j = ordem; j < n; j++){
        for (int i = 0; i < n - diff; i++){
            double denominador = tabela[i+j][0] - tabela[i][0];
            double numerador = diferenca[i+1][j-1] - diferenca[i][j-1];
            diferenca[i][j] = numerador/denominador;
        }
        diff++;
    }    
}


void newton_interpolation_formula(double x, int n){
    double termo = tabela[0][1];
    double somatoria = 0;
    for (int i = 1; i < n; i++){
        double produtoria = 1;
        for (int j = 0; j < i; j++){
            produtoria *= (x - tabela[j][0]);
        }
        somatoria += diferenca[0][i] * produtoria;
        
    }
    somatoria += termo;
    cout << somatoria << endl;
}

int main(){
    int n;
    cin >> n;
    preenche_tabela(n);
    double x;
    cin >> x;
    newton_interpolation_formula(x, n);
}
