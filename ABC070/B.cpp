#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;

int main()
{
    // 整数の入力
    long long A,B,C,D;
    cin >> A;
    cin >> B;
    cin >> C;
    cin >> D;

    if (B<=C || D<= A){
        cout << 0 << endl;
    }else if(A<=C){
        if (B<=D){
            cout << B - C << endl;
        }else{
            cout << D - C << endl;
        }
    }else{
        if (B<=D){
            cout << B - A << endl;
        }else{
            cout <<  D - A << endl;
        }
    }

    return 0;
}