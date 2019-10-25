#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
float tabela[MAX][2];
float diferenca[MAX][MAX];

void preenche_tabela(int n){
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < 2; j++){
            cin >> tabela[i][j];
        }
    }
    
     for (int i = 0; i < n; i ++){
        for (int j = 0; j < 2; j++){
            cout << tabela[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-----------\n";
    
    
    int ordem = 1;
    for (int i = 0; i < n - 1; i ++){
        diferenca[i][ordem] = (tabela[i + 1][1] - tabela[i][1]) / (tabela[i+ordem][0] - tabela[i][0]); 
    }
    ordem++;
    for (int j = ordem; j < n-1; j++){
        for (int i = 0; i < n; i++){
            cout << i << " e "<< j << endl;
            cout <<  (diferenca[i+1][1] - diferenca[i][1]) << endl;
            cout << (tabela[i+j][0] - tabela[i][0]) << endl;
            diferenca[i][j] = (diferenca[i+1][j-1] - diferenca[i][j-1]) / (tabela[i+j][0] - tabela[i][0]);
        }
    }
    
    
    for (int i = 0; i < n-1; i ++){
        for (int j = 0; j < n-1; j++){
            cout << diferenca[i][j] << " ";
        }
        cout << endl;
    }
    
}


void newton_interpolation_formula(float x, int n){
    int termo = tabela[0][1];
    float somatoria = 0;
    for (int i = 1; i < n; i++){
        float produtoria = 1;
        for (int j = 0; j < i-1; j++){
            produtoria *= (x - tabela[j][0]);
        }
        cout << produtoria << endl;
        somatoria += diferenca[0][i] * produtoria;
    }
    somatoria += termo;
    cout << somatoria << endl;
}

int main(){
    int n;
    cin >> n;
    preenche_tabela(n);
    float x;
    cin >> x;
    newton_interpolation_formula(x, n);
}
