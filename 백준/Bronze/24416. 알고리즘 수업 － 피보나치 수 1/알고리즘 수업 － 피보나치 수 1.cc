#include <iostream>
#include <vector>

using namespace std;

int fib_count = 0;
int fibna_count = 0;

int fib(int n){
    if(n==1 || n==2){
        fib_count++;
        return 1;
    }
    return fib(n-1) + fib(n-2);
}

int fibonacci(int n){
    vector<int> arr(n+1, 0);

    if(n>=1) arr[1] = 1;
    if(n>=2) arr[2] = 1;

    for(int i=3; i<=n; i++){
        arr[i] = arr[i-1] + arr[i-2];
        fibna_count++;
    }
    return arr[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;

    cin >> n;
    fib(n);
    fibonacci(n);

    cout << fib_count << " " << fibna_count << endl;

}