#include <bits/stdc++.h>
using namespace std;

double tabela[1000][2];
vector<long double> x, y;
 
long double f(long double x){
	return pow(x, 3) + pow(x, 2) + x + 1;
}

// h/3 (y0 + 4y1 + 2y2 + 4y3 + 2y4 + y5)
// h/3 (y0 + 4y1 + 2y2 + y3)

double intervalo(int n){
	x.clear();
	y.clear();
	double a = tabela[0][1];
	double b = tabela[1][1];
	double h = (b-a)/n;
	for (long double i = a; i <= b; i += h){
		x.push_back(i);
		y.push_back(f(i));
	}
	cout << endl;
	return h;
}


long double regra_simpson_composta(int n, double h){
	long double integral = h/3;
	long double somatorio = 0;
	for(int i = 1; i < n; i++){
		if (i%2 ==0)
			somatorio += 2*y[i];
		else
			somatorio += 4*y[i];
		//somatorio += 2*y[i] + 4*y[2*i-1];
	}
	somatorio += y[0] + y[n];
	return  integral *somatorio;
}

long double extrapolacao(long double i1, long double i2, double n1, double n2){
	long double integral = (i2 - i1) * pow(n1, 2);
	integral /= (pow(n2,2) - pow(n1, 2));
	return integral + i2;
}
int main(){
	int n1 , n2;
	double a, b;
	cin >> a >> b;
	tabela[0][1] = a;
	tabela[1][1] = b;
	cin >> n1 >> n2;
	double h = intervalo(n1);
	long double i1 = regra_simpson_composta(n1, h);
	cout << i1 << endl;
	h = intervalo(n2);
	long double i2 = regra_simpson_composta(n2, h);
	cout << i2 << endl;
	cout << extrapolacao(i1, i2, n1, n2) << endl;
}
