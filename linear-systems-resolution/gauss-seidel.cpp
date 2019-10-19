 #include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define LINE_CRITERIA_SATISFIED 10
#define COLS_CRITERIA_SATISFIED 15
#define NONE_CRITERIA_SATISFIED 5
#define SASSENFELD_CRITERIA_SATISFIED 20

int sassenfeld_criteria(double coeficientes[][MAX], int m){
    double beta[m] = {};
    for (int i = 0; i < m; i++){
        double somatorio = 0;
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


int criteria(double coeficientes[][MAX], int m){
    double lines[m] = {};
    double cols[m] = {};
    int indice = 0;
    for(int i = 0; i < m; i++){
        double somatorio_line = 0;
        double somatorio_cols = 0;
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
    return sassenfeld_criteria(coeficientes, m);
}


vector<double> gauss_seidel_method(double coeficientes[][MAX],
                                  double termos_independentes[MAX],
                                  int m, double epsilon){
    vector<double> x_barra(m, 0);
    vector<double> x_atual(m, 0);
    double erro_relativo = 20000000000000;
    while(erro_relativo > epsilon){
        for (int x = 0; x < m; x++){
            double algo = termos_independentes[x];
            
            for(int y = 0; y < m; y++){
                if (x != y)
                    algo += -coeficientes[x][y] * x_atual[y];
            }
            algo = algo/coeficientes[x][x];
            x_atual[x] = algo;
        }
        double diff[m] = {};
        double bigger = 0.0;
        double big = 0.0;
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
     return x_atual;
}

int main(){
    int m;
    double epsilon;
    cin >> m;
    cin >> epsilon;
    double coeficientes[MAX][MAX];
    double termos_independentes[m];
    for (int x = 0; x < m; x++){
        for(int y = 0; y < m; y++){
            cin >> coeficientes[x][y];
        }
    }
    for (int x = 0; x < m; x++)
        cin >> termos_independentes[x];
    switch(criteria(coeficientes, m)){
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
   
    vector<double> x_atual = gauss_seidel_method(coeficientes, termos_independentes, m, epsilon);
    cout << "resposta do sistema com erro de " << epsilon << endl;
    for (int i = 0; i < m; i++)
        cout << x_atual[i] << " ";
    cout << endl;
}
