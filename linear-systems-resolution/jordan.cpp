#include <bits/stdc++.h>

using namespace std;

int main(){
    int m;
    cout << "Insira o tamanho m para uma matriz quadrada mxm";
    cin >> m;
    float coeficientes[m][m];
    float termos_independentes[m];
    for (int x = 0; x < m; x++){
        for(int y = 0; y < m; y++){
            cin >> coeficientes[x][y];
        }
    }
    for (int x = 0; x < m; x++)
        cin >> termos_independentes[x];
        
    for (int x = 0; x < m; x++){
        for(int y = 0; y < m; y++){
            float n;
            if (x != y){
                n = coeficientes[y][x]/coeficientes[x][x];
                coeficientes[y][x] = 0;
                for (int k = 0; k < m; k++){
                    if(x != k)
                        coeficientes[y][k] = coeficientes[y][k] - n*coeficientes[x][k];
                }       
                termos_independentes[y] = termos_independentes[y] -     n*termos_independentes[x];        
            }
        }

    }
    float resposta[m] = {}; 
    for (int k = 0; k < m; k++){
        resposta[k] = termos_independentes[k]/coeficientes[k][k];
    }
    
    
    cout << "Resposta: ";
    
    for (int x = 0; x < m; x++){
        cout << resposta[x] << " ";
    }
    cout << endl;
}
