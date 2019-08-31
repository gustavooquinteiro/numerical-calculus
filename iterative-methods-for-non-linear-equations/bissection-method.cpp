#include <bits/stdc++.h>
using namespace std;

string funct;

float apply_func(float x){
    string func = funct;
    size_t index_1 = func.find_first_of('(');
    size_t index_2 = func.find_first_of(')');
    size_t last = index_2 != string::npos? index_2: 0;
    float result = 0;
    while (index_1 != string::npos && index_2 != string::npos){
        func[index_1] = ' ';
        func[index_2] = ' ';
        string in_between = func.substr(index_1+1, index_2-1);
        for (int i = 0; i < in_between.size(); i++){
            if(isdigit(in_between[i]) && in_between[i+2] == 'x'){
                int number = in_between[i] - '0';
                
                switch(in_between[i+1]){
                    case '+':
                        result = number + x;
                        break;
                    case '-':
                        result = number - x;
                        break;
                    case '*':
                        result = number * x;
                        break;
                    case '/':
                        result = number / x;
                        break;
                    case '^':
                        result = pow(number, x);
                        break;
                }
            }else if (in_between[i] == 'x' && in_between[i+2] == 'x'){
                switch(in_between[i+1]){
                    case '+':
                        result = x + x;
                        break;
                    case '-':
                        result = x - x;
                        break;
                    case '*':
                        result = x * x;
                        break;
                    case '/':
                        result = x / x;
                        break;
                    case '^':
                        result = pow(x, x);
                        break;
                }
            }if(isdigit(in_between[i+2]) && in_between[i] == 'x'){
                int number = in_between[i+2] - '0';
                
                switch(in_between[i+1]){
                    case '+':
                        result = x + number;
                        break;
                    case '-':
                        result = x - number ;
                        break;
                    case '*':
                        result = x * number;
                        break;
                    case '/':
                        result = x / number;
                        break;
                    case '^':
                        result = pow(x, number);
                        break;
                }
            }
            cout << result << endl;
        }
        index_1 = func.find_first_of('(');
        index_2 = func.find_first_of(')');
        last = index_2 != string::npos? index_2: last;
    }
    float result1 = 0;
    size_t y = func.find_first_of('x');
    if (y != string::npos && isdigit(func[y+2])){
        int number = stoi(func[y+2]);
        switch(func[y+1]){
            case '+':
                result = x + number;
                break;
            case '-':
                result = x - number ;
                break;
            case '*':
                result = x * number;
                break;
            case '/':
                result = x / number;
                break;
            case '^':
                result = pow(x, number);
                break;
        }
    }
    
        

        
    
    
    return result;
}

pair<float, float> bissection_method(pair<float, float> interval, float precision){
    int max_iteration = (log2(interval.second - interval.first) - log2(precision));
    int n = 1;
    while(n < max_iteration){
        if (abs(interval.second - interval.first) < precision)
            return interval;
        float middle = (interval.first + interval.second) / 2;
        if (apply_func(interval.first) * apply_func(middle) > 0)
            interval.first = middle;
        else
            interval.second = middle;
        n++;
    }
    return interval;
}


int main(){
    cin >> funct;
    float lower_bound, upper_bound;
    cin >> lower_bound >> upper_bound;
    float precision;
    cin >> precision;
    pair<float, float> interval = make_pair(lower_bound, upper_bound);
    
    interval = bissection_method(interval, precision);
    
    float root = (interval.first + interval.second) / 2;
    cout << "Root for "<< funct << " in ("<<lower_bound<<", " << upper_bound << ") with precision of " << precision << " is: " << root << endl; 
    
}
