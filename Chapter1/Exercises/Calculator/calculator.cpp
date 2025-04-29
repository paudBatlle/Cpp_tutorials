#include <iostream>


int add(int a, int b){
    return a+b;
}
int subtract(int a, int b){
    return a-b;
}
int multiply(int a, int b){
    return a*b;
}
int divide(int a, int b){
    return a/b;
}

int main(){
    int a;
    int b;
    char operation;

    std::cin >> a; 
    std::cin >> b; 
    std::cin >> operation; 

    int result;
    switch(operation){
        case '+':
            result = add(a,b);
        
        case '-':
            result = subtract(a,b);
        
        case '*':
            result = multiply(a,b);
        
        case '/':
            if (b==0) {
                std::cout << "Cannot divide by 0!" << std::endl;
                return -1;
            }else{
                result = multiply(a,b);
            }   
    }
    std::cout << result << std::endl;
    return 0;
}