 #include <bits/stdc++.h>

using namespace std;

int main(){
    int m;
    float epsilon;
    cin >> m;
    cin >> epsilon;
    float coeficientes[m][m];
    int termos_independentes[m];
    for (int x = 0; x < m; x++){
        for(int y = 0; y < m; y++){
            cin >> coeficientes[x][y];
        }
    }
    for (int x = 0; x < m; x++)
        cin >> termos_independentes[x];
    
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
