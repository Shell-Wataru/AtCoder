#include<iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
using namespace std;

int main()
{
    // 整数の入力
    long long n,m,d;
    double base;
    cin >> n >> m >> d;
    if (d == 0){
        base = 1.0/n;
    }else if (2 * d < n){
        base =(2.0 * d/n) * 1.0/n + ((n - 2.0* d)/n) * 2.0/n;
    }else{
        base = (2.0* n - 2.0 * d)/n * 1.0/n;
    }
    cout << fixed << setprecision(10) << base * (m-1) << endl;
    return 0;
}