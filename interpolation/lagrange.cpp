#include <bits/stdc++.h>
using namespace std;

#define n 3
float matriz[n][2];

void preencher(){
	for(int i = 0; i < n; i++){
		for (int j =0; j < 2; j++){
			cin >> matriz[i][j];
		}
	}
}

float calculo(float x){
	float sum =0;
	for (int i = 0; i < n; i++){
        float prod = 1;
		for (int j = 0; j < n; j++){
			if (i != j){
				prod *= ((x - matriz[j][0])/(matriz[i][0] - matriz[j][0]));
			}
		}
		sum += matriz[i][1] * prod;
	}
	return sum;
}

int main(){
	preencher();
	float x;
	cin >> x;
	cout << calculo(x) << endl;;
}
