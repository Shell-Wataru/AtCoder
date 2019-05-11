#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
using namespace std;

int main()
{
    // 整数の入力
    long long N,D,i;
    cin >> D >> N;
    if (N== 100){
        cout << 101;
    }else {
        cout << N;
    }

    if (D == 0){
    }else if (D == 1){
        cout << "00";
    }else {
        cout << "0000";
    }
    cout << endl;

    return 0;
}