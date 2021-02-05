#include<iostream>

using namespace std;
int fib(int n) {
    if (n <=2){
        return 1;
    }
    int first = 1,second = 1, tmp;
    for(int i = 2; i < n ; i ++) {
        tmp = second;
        second = first + second;
        first = tmp;
    }
    return second;
}
int main() {
    cout << fib(200) << endl;
}