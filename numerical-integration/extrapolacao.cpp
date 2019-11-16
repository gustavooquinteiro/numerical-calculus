#include <bits/stdc++.h>
using namespace std;

double tabela [10][2] = {{}};
double i1, i2, n1, n2;

double f(double x){
	return sin(x);
}

double regra_trapezios(int subdiv, double a, double b){
	double x_inicial = tabela[0][0];
	double h = ((b - a)/ subdiv);
	double somatorio = 0;
	for (int i = 1; i <= subdiv; i++){
		x_inicial += h;
		tabela[i][0] = x_inicial;
		tabela[i][1] = f(x_inicial);
		somatorio += tabela[i][1];
	}
	cout << "x 	|	y" << endl;
	for (int i =0; i < 10; i++)
		cout << tabela[i][0] << " |  " <<tabela[i][1] << endl;

	return h* (((f(a) + f(b)) / 2) + somatorio);
}


double extrapolacao(double i1, double i2, double n1, double n2){
	double upper = pow(n1, 2)*(i2 - i1);
	double lower = (pow(n2, 2) - pow(n1, 2));
	return i2 + upper/lower;
}

int main(){
	double a, b;
	cin >> a >> b;
	cin >> n1;
	i1 = regra_trapezios(n1, a, b);
cout <<"i1 == " << i1 << endl;
	cin >> n2;
	i2 = regra_trapezios(n2, a, b);
cout <<"i2 == " << i2 << endl;
	cout << extrapolacao(i1, i2, n1, n2) << endl;

}
