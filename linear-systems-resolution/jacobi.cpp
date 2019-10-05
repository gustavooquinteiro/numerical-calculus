 #include <bits/stdc++.h>

using namespace std;



int main(){
    int m;
    int n;
    cin >> m;
    cin >> n;
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
