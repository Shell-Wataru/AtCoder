#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;


int main()
{
    // 整数の入力
    int a,b;
    cin >> a >> b;
    if (a + b == 15){
        cout << "+" << endl;
    }else if (a * b == 15){
        cout << "*" << endl;
    }else{
        cout << "x" << endl;
    }

    return 0;
}