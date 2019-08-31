#include <bits/stdc++.h>
using namespace std;

void binary_to_decimal(){
    string binary = "";
    cin >> binary;
    int decimal = 0; 
    for (register int i = 0; i < binary.size(); i++){
        if (binary[i] == '1'){
            int expoent = binary.size() - 1 - i;
            decimal += (1 << expoent);
        }
    }
    cout << "Binary is: " << binary << endl;
    cout << "Decimal is: " << decimal << endl;
}

void decimal_to_binary(){
    int decimal;
    cin >> decimal;
    string binary = "";
    cout << "Decimal is: " << decimal << endl;
    while(decimal != 1){
        char bit = (decimal % 2) + '0';
        binary += bit;
        decimal = decimal >> 1;
    }
    binary += decimal == 0? '0': '1';
    reverse(binary.begin(), binary.end());
    cout << "Binary is: " << binary << endl;
}

void float_to_binary(){
    float number;
    cin >> number;
    int integer = number;
    float fractional = number - integer;
    string binary = "";
    while(integer != 1){
        char bit = (integer % 2) + '0';
        binary += bit;
        integer = integer >> 1;
    }
    binary += integer == 0? '0': '1';
    reverse(binary.begin(), binary.end());
    binary += '.';
    while(fractional != 0){
        fractional *= 2;
        int integer_part = fractional;
        char bit = integer_part + '0';
        binary += bit;
        fractional = fractional - integer_part;
    }
    cout << "Float is: " << number << endl;
    cout << "Binary is: " << binary << endl;   
}

void binary_to_float(){
    string binary;
    cin >> binary;
    float number = 0;
    int index = binary.find_first_of('.');
    for (register int i = 0; i < index; i++){
        if (binary[i] == '1'){
            int expoent = index - 1 - i;
            number += (1 << expoent);
        }
    }
    int expoent = -1;
    for (register int i = index + 1; i < binary.size(); i++){
        if (binary[i] == '1')
            number += pow(2, expoent);
        expoent--;
    }
    cout << "Binary is: " << binary << endl;  
    cout << "Float is: " << number << endl;
}

int main(){
    int n;
    while(cin >> n){
        switch(n){
            case 1:
                decimal_to_binary();
                break;
            case 2:
                binary_to_decimal();
                break;
            case 3:
                float_to_binary();
                break;
            case 4:
                binary_to_float();
                break;
            case 5:
                return 0;
                
        }
    }
    
}
