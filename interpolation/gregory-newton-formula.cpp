#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
double matriz[MAX][2];
double diferenca[MAX][MAX];
double h = 0;
void preencher(int n){
	for(int i = 0; i < n; i++){
		for (int j = 0; j < 2; j++){
			cin >> matriz[i][j];               
            if (i >= 1)
                h = matriz[i][0] - matriz[i-1][0];
		}
	}
	int diff = 1;
	int ordem = 1; 
    for (int i = 0; i < n - diff; i++){
        diferenca[i][ordem] = matriz[i+1][1] - matriz[i][1];
    }
    
    ordem++;
    diff++;

    for (int j = ordem; j < n; j++){
        for (int i = 0; i < n - diff; i++){
            diferenca[i][j] = diferenca[i+1][j - 1]  - diferenca[i][j-1];
        }
    }
    
//     for (int i = 0; i < n; i++){
//         for (int j =0; j < n; j++){
//             cout << diferenca[i][j] << " ";
//         }
//         cout << endl;
//     }
}

double gregory_newton_interpolation(int n, double x){
    double termo = matriz[0][1];
    double somatoria = 0;
    double fatorial = 1;
    double z = (x - matriz[0][0])/h;
    for (int i = 1; i < n; i++){
        fatorial *= i;
        double produtoria = 1;
        for (int j = 0; j < i; j++){
            produtoria *= (z - j);
        }
        somatoria += (diferenca[0][i] * produtoria)/fatorial;
    }
    somatoria += termo;
    return somatoria;
}

int main(){
    int n;
    cin >> n;
    preencher(n);
    double x;
    cin >> x;
    cout << gregory_newton_interpolation(n, x) << endl;
}
