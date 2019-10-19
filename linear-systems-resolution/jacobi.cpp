 #include <bits/stdc++.h>
using namespace std;
#define MAX 1001
#define LINE_CRITERIA_SATISFIED 10
#define COLS_CRITERIA_SATISFIED 15
#define NONE_CRITERIA_SATISFIED 5
double coeficientes[MAX][MAX];

int criteria(int m){
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
    return NONE_CRITERIA_SATISFIED;
}

vector<double> jacobi_method_n_times(double coeficientes[][MAX],
                            double termos_independentes[MAX],
                            int m, int n){
    vector<double> x_barra(m, 0);
    vector<double> resposta(m, 0);
    for (int i = 0; i < n + 1; i++){
        for (int x = 0; x < m; x++){
            double algo = termos_independentes[x];
            
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
     return resposta;
}

vector<double> jacobi_method_relative_error(double coeficientes[][MAX],
                            double termos_independentes[MAX],
                            int m, double epsilon){
    vector<double> x_barra(m, 0);
    vector<double> resposta(m, 0);
    double erro_relativo = 2000000;
    while(erro_relativo > epsilon){
        for (int x = 0; x < m; x++){
            double algo = termos_independentes[x];
            
            for(int y = 0; y < m; y++){
                if (x != y)
                    algo += -coeficientes[x][y] * x_barra[y];
            }
            algo = algo/coeficientes[x][x];
            resposta[x] = algo;
        }
     
        double diff[m] = {};
        double bigger = 0.0;
        double big = 0.0;
        for (int a = 0; a < m; a++){
            diff[a] = abs(resposta[a] - x_barra[a]);
            if (diff[a] > bigger)
                bigger = diff[a];
            if (abs(x_barra[a]) > big)
                big = abs(x_barra[a]);
            x_barra[a] = resposta[a];
        }
        erro_relativo = bigger/big;
    }
   
    return x_barra;
}

int main(){
    int m ;
    double n;
    int a;
    cin >> a;        
    cin >> m;
    cin >> n;
    double termos_independentes[m];
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
    
    vector<double> x_barra = (a == 1)? jacobi_method_relative_error(coeficientes, termos_independentes, m, n): jacobi_method_n_times(coeficientes, termos_independentes, m, n);
    cout << "resposta do sistema após " << n << " iterações" << endl;
     for (int i = 0; i < m; i++)
         cout << x_barra[i] << " ";
     cout << endl;
}
