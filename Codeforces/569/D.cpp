#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    long long N,M;
    vector<pair<ll,ll>> idou;
    cin >> N >> M;
    for (int i =0 ;i<N/2;i++){
        if (i % 2 == 0){
            for(int j = 0;j<M;j++){
                cout << i+1  << " " << j+1 << '\n';
                cout << N-i  << " " << M - j << '\n';
            }
        }else{
            for(int j = M - 1;j>=0;j--){
                cout << i+1  << " " << j+1 << '\n';
                cout << N-i  << " " << M - j << '\n';
            }
        }
    }


    if (N % 2 == 1){
        for(int j = 0;j<M/2;j++){
            cout <<  N/2 + 1  << " " << j+1 << '\n';
            cout << N/2 + 1 << " " << M - j << '\n';
        }

        if (M % 2 == 1){
            cout << N/2 + 1 << " " << M/2 + 1 << '\n';
        }
    }
    return 0;
}