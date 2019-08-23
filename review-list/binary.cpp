#include <iostream>  //cin e cout
#include <vector>    //vector
#include <algorithm> //reverse
#include <stdio.h>   //printf
#include <bits/stdc++.h>

using namespace std;

int main (){
    float numero;
    vector<int> binario;
    vector<int>frac;
    cout << "Digite um numero inteiro" << endl; //printf("Digite um numero inteiro: "); 
    cin >> numero;								//scanf("%d", &numero);
    float decimal_part = floor(numero);
    if (decimal_part == 0)
        binario.push_back(0);
    else{
        int n = decimal_part;
        while (n != 1){
            binario.push_back(n%2);
            n = n / 2;
        }
        binario.push_back(1);
        reverse(binario.begin(), binario.end());
    }
    float fracional = modf(numero, &decimal_part);
    int contador = 0;
    while(fracional != 0 && contador < 5){
        fracional *= 2;
        float p = floor(fracional);
        frac.push_back((int) p);
        fracional = modf(fracional, &p);
        contador++;
    }
    for (int i = 0; i < binario.size(); i++){
        cout << binario[i];
    }
    if (frac.size() > 0){
        cout << ".";
        for (int i =0; i< frac.size(); i++)
            cout << frac[i];
        cout << endl;
    }
    return 0;
} 
