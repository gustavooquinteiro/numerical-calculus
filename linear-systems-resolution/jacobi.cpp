 #include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define LINE_CRITERIA_SATISFIED 10
#define COLS_CRITERIA_SATISFIED 15
#define NONE_CRITERIA_SATISFIED 5
float coeficientes[MAX][MAX];

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
    return NONE_CRITERIA_SATISFIED;
}


int main(){
    int m ;
    int n;
    cin >> m;
    cin >> n;
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
        default:
            cout << "Nenhum criterio satisfeito\n";
            break;
    }
    float x_barra[m] = {};
    float resposta[m] = {};
     for (int i = 0; i < n + 1; i++){
        for (int x = 0; x < m; x++){
            float algo = termos_independentes[x];
            
            for(int y = 0; y < m; y++){
                if (x != y)
                    algo += -coeficientes[x][y] * x_barra[y];
            }
            algo = algo/coeficientes[x][x];
            resposta[x] = algo;
        }
        for (int a = 0; a < m; a++)
            x_barra[a] = resposta[a];
     }
    cout << "resposta do sistema após " << n << " iterações" << endl;
     for (int i = 0; i < m; i++)
         cout << x_barra[i] << " ";
     cout << endl;
}
