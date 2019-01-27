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
    long long  N,M,A,B,i,Li,Ri,S;
    cin >> N >> M >> A >> B;
    int* data = new int[N];
    for (i = 0;i< N;i++){
        data[i] = B;
    }

    for (i = 0;i< M;i++){
        cin >> Li >> Ri;
        for (int j = Li - 1; j<Ri;j++ ){
            data[j] = A;
        }
    }

    S = 0;
    for (i = 0;i< N;i++){
        S += data[i];
    }

    cout << S << endl;
    return 0;
}