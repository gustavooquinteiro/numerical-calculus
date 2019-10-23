#include <bits/stdc++.h>
using namespace std;

float matriz[4][2];

void preencher(){
	for(int i = 0; i < 4; i++){
		for (int j =0; j < 2; j++){
			cin >> matriz[i][j];
		}
	}
}

float calculo(float x){
	float prod[4] = {1,1,1,1};
	float sum =0;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			if (i != j){
				prod[i] *= ((x - matriz[j][0])/(matriz[i][0] - matriz[j][0]));
			}
		}
	}
	for (int i = 0; i < 4; i++){
		sum += matriz[i][1] * prod[i];
	}
	return sum;
}

int main(){
	preencher();
	float x;
	cin >> x;
	cout << calculo(x) << endl;;
}
