#include <bits/stdc++.h>
using namespace std;

void q01(){
    int x, y;
    cin >> x >> y;
    cout << "Soma: "<< x + y << endl;
    cout << "Subtração: " << x - y << endl;
    cout << "Multiplicação: " << x * y << endl;
    cout << "Divisão: "<< x / y << endl;
}

void q02(){
    float base_maior, base_menor, altura;
    cin >> base_maior >> base_menor >> altura;
    float resultado = ((base_maior + base_menor) * altura) / 2;
    cout << resultado << endl;
}

void q03(){
    float media = 0;
    for (int i = 0; i < 3; i++){
        int nota = 0;
        cin >> nota;
        while (nota < 0 || nota > 10)
            cin >> nota;
        media += nota;
    }
    media = media / 3;
    if (media < 5)
        cout << "reprovado" << endl;
    else
        cout << "aprovado" << endl;
    
}
void q04(){
    vector<int> array(10);
    for (int i =0; i < 10; i++){
        cin >> array[i];
    }
    sort(array.begin(), array.end());
    cout <<"O maior elemento no array é >" << array[9] << endl;
}

void q05(){
    int matrix[4][4];
    int largest = 0;
    for (int i =0; i < 4; i++){
        for (int j =0; j < 4; j++){
            matrix[i][j] = rand() % 1000;
            if (largest < matrix[i][j]){
                largest = matrix[i][j];
            }
        }
        cout << endl;
    }
    cout << "O maior elemento na matriz é >" << largest << endl;
    
}

void q06(){
    int matrix1 [3][3];
    int matrix2 [3][1];
    int result [3][1] = {0,0,0};
     for (int i =0; i < 3; i++){
        for (int j =0; j < 3; j++){
            matrix1[i][j] = rand() % 10;
            cout << matrix1[i][j] << " ";
        }
        cout << endl; 
    }
    for (int i =0; i < 3; i++){
        matrix2[i][0] = rand() % 10;
        cout << matrix2[i][0] << endl;
    }
    int j = 0;
    for (int i =0; i < 3; i++){        
        for (int k=0; k < 3; k++){
            result[i][j] += matrix1[i][k] * matrix2[k][j];
        }
    }
    for (int i=0; i < 3; i++){
        cout << result[i][0] << endl;
    }
}

void q07(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        if (i%2 != 0){
            cout << i << " ";
        }
    }
}

void q08(){
    for (int i =0; i < 5; i++){
        string palavra;
        cin >> palavra;
        map<int, char> local;
        int cont = 0;
        for (int j =0; j < palavra.size(); j++){
            char caracter = palavra[j];
            if (caracter == 'a' || caracter == 'A' || caracter == 'e' || caracter == 'E' || caracter == 'i' || caracter == 'I' || caracter == 'o' || caracter == 'O' || caracter == 'u' || caracter == 'U'){
                cont++;
                local[j+1] = caracter;
            }
        }
        cout << palavra << ": "  << cont << " vogais";
        map<int, char>::iterator it;
        for (it = local.begin(); it != local.end(); it++)
            cout << " | " << it->second << " - " << it->first;
    }
}

int main(){
    q03();
    return 0;
}
