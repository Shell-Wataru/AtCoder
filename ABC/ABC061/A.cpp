#include<iostream>
#include <algorithm>
#include <vector>
#include <deque> 
using namespace std;

int main()
{
    // 整数の入力
    int A,B,C;
    cin >> A >> B >>C;
    if (A <= C && C<=B){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}