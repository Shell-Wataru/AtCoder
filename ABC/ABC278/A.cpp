#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N,K;
    cin >> N >> K;
    deque<ll> A(N);
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }
    for(int i = 0;i < N;i++){
        if ( i != 0){
            cout << " ";
        }
        if (i+K >= N) {
        cout << 0;
        }else{
        cout << A[(i+K) % N];
        }
    }
    cout << endl;
    return 0;
}