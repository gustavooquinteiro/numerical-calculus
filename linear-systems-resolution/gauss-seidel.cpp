 #include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define LINE_CRITERIA_SATISFIED 10
#define COLS_CRITERIA_SATISFIED 15
#define NONE_CRITERIA_SATISFIED 5
#define SASSENFELD_CRITERIA_SATISFIED 20
float coeficientes[MAX][MAX];


int sassenfeld_criteria(int m){
    float beta[m] = {};
    for (int i = 0; i < m; i++){
        float somatorio = 0;
        for (int j = 0; j < i; j++){
            somatorio += coeficientes[i][j] * beta[j];
        }
        for (int j = i+1; j < m; j++){
            somatorio += coeficientes[i][j];
        }
        beta[i] = somatorio / coeficientes[i][i];
    }
    sort(beta, beta+m);
    if (beta[m-1] < 1)
        return SASSENFELD_CRITERIA_SATISFIED;
    return NONE_CRITERIA_SATISFIED;
}


int criteria(int m){
    float lines[m] = {};
    float cols[m] = {};
    int indice = 0;
    for(int i = 0; i < m; i++){
        float somatorio_line = 0;
        float somatorio_cols = 0;
        for(int j = 0; j < m; j++){
            if (i != j){
                somatorio_line += coeficientes[i][j];
                somatorio_cols += coeficientes[j][i];
            }
        }
        lines[i] = somatorio_line / coeficientes[i][i];
        cols[i] = somatorio_cols / coeficientes[i][i];
    }
    sort(lines, lines+m);
    sort(cols, cols+m);
    if (lines[m-1] < 1)
        return LINE_CRITERIA_SATISFIED;
    if (cols[m-1] < 1)
        return COLS_CRITERIA_SATISFIED;
    return sassenfeld_criteria(m);
}


int main(){
    int m;
    float epsilon;
    cin >> m;
    cin >> epsilon;
    int termos_independentes[m];
    for (int x = 0; x < m; x++){
        for(int y = 0; y < m; y++){
            cin >> coeficientes[x][y];
        }
    }
    for (int x = 0; x < m; x++)
        cin >> termos_independentes[x];
    switch(criteria(m)){
        case LINE_CRITERIA_SATISFIED:
            cout << "Criterio das linhas satisfeito\n";
            break;
        case COLS_CRITERIA_SATISFIED:
            cout << "Criterio das colunas satisfeito\n";
            break;
        case SASSENFELD_CRITERIA_SATISFIED:
            cout << "Criterio de Sassenfeld satisfeito\n";
            break;
        default:
            cout << "Nenhum criterio satisfeito\n";
            break;
    }
    float x_barra[m] = {};
    float x_atual[m] = {};
    float erro_relativo = 20000000000000;
     while(erro_relativo > epsilon){
        for (int x = 0; x < m; x++){
            float algo = termos_independentes[x];
            
            for(int y = 0; y < m; y++){
                if (x != y)
                    algo += -coeficientes[x][y] * x_atual[y];
            }
            algo = algo/coeficientes[x][x];
            x_atual[x] = algo;
        }
        float diff[m] = {};
        float bigger = 0.0;
        float big = 0.0;
        for (int a = 0; a < m; a++){
            diff[a] = abs(x_atual[a] - x_barra[a]);
            if (diff[a] > bigger)
                bigger = diff[a];
            if (x_barra[a] > big)
                big = x_barra[a];
            x_barra[a] = x_atual[a];
        }   
            
        erro_relativo = bigger/big;
     }
cout << "resposta do sistema com erro de " << epsilon << endl;
     for (int i = 0; i < m; i++)
         cout << x_atual[i] << " ";
     cout << endl;
}
