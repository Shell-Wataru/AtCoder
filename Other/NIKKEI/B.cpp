#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>

using namespace std;

int main()
{
    // 整数の入力
    long long  N,value;
    value = 0;
    string A,B,C;
    cin >> N;
    cin >> A >> B >> C;

    for (int i = 0;i< N;i++){
        if (A[i]== B[i] && B[i] == C[i]){
            value += 0;
        }else if(A[i]== B[i] || B[i]== C[i] || C[i]== A[i]){
            value += 1;
        }else{
            value += 2;
        }
    }
    cout << value << endl;

    return 0;
}