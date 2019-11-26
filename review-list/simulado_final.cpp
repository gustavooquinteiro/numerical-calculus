#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

double coeficientes[MAX][MAX];
double termos_independentes[MAX];
vector<double> x_barra(MAX, 0);
vector<double> x_atual = {0.7, -1.6, 0.6};


int sassenfeld_criteria(int m){
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


bool criteria(int m){
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
        return true;
	return false;
}


double calculo_erro(){
	double diff[x_barra.size()] = {};
    double bigger = 0.0;
    double big = 0.0;
    for (int a = 0; a < x_barra.size(); a++){
        diff[a] = abs(x_atual[a] - x_barra[a]);
        if (diff[a] > bigger)
            bigger = diff[a];
        if (x_barra[a] > big)
            big = x_barra[a];
        x_barra[a] = x_atual[a];
    }   
        
    double erro_relativo = bigger/big;
	return erro_relativo;
}

vector<double> gauss_seidel_method(int m, double epsilon){
   do{
        for (int x = 0; x < m; x++){
            double algo = termos_independentes[x];
            
            for(int y = 0; y < m; y++){
                if (x != y)
                    algo += -coeficientes[x][y] * x_atual[y];
            }
            algo = algo/coeficientes[x][x];
            x_atual[x] = algo;
        }
		cout << "Vetor atual == ";
        for(int i = 0; i < m; i++){
			cout << x_atual[i] << " ";
		}
		cout << endl;
     }while(calculo_erro() > epsilon); 
     return x_atual;
}

void preencher(int m){
for (int x = 0; x < m; x++){
        for(int y = 0; y < m; y++){
            cin >> coeficientes[x][y];
        }
    }
    for (int x = 0; x < m; x++)
        cin >> termos_independentes[x];
}

int main(){
    int m;
    double epsilon;
    cin >> m;
    cin >> epsilon;
    
    preencher(m);

    if(criteria(m)){
        cout << "Convergência satisfeita através do critério de linhas\n";
    }
	if (sassenfeld_criteria(m)){
   	 cout << "Convergência satisfeita através do critério de Sassefeld\n";
	}
   
    vector<double> x_atual = gauss_seidel_method(m, epsilon);
    cout << "resposta do sistema com erro de " << epsilon << endl;
    for (int i = 0; i < m; i++)
        cout << x_atual[i] << " ";
    cout << endl;
}
