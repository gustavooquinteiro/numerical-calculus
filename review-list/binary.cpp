#include <iostream>  //cin e cout
#include <vector>    //vector
#include <algorithm> //reverse
#include <stdio.h>   //printf
#include <bits/stdc++.h>

using namespace std;

int main ()
{
    float numero;
	vector<int> binario;
    vector<int>frac;
    cout << "Digite um numero inteiro" << endl; //printf("Digite um numero inteiro: "); 
    cin >> numero;								//scanf("%d", &numero);
	
	if (numero == 0)
		binario.push_back(0);
		
	else
	{
        float decimal_part = floor(numero);
        int n = decimal_part;
        cout <<"decimal == "<< decimal_part << endl;
		while (n != 1)
		{
			binario.push_back(n%2);
			n = n / 2;
		}
		binario.push_back(1);
		reverse(binario.begin(), binario.end());
        
        float fracional = modf(numero, &decimal_part);
        cout << "fracional é =="<< fracional << endl;
        float f = fracional;
        while(f != 0.0){
            fracional *= 2;
            float p = floor(fracional);
            int k = p;
            frac.push_back(k%2);
            f = modf(fracional, &p);
        }
	}
	
	for (int i = 0; i < binario.size(); i++)
	{
		cout << binario[i];
	}
	cout << ".";
    for (int i =0; i< frac.size(); i++)
        cout << frac[i];
    cout << endl;
	
	return 0;
} 
