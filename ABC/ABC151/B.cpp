#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N,K,M;
    cin >> N>> K >> M;
    ll target = N * M;
    for(int i  = 0;i< N - 1;i++){
        ll a;
        cin >> a;
        target -= a;
    }

    if (target <= K){
        cout << max(target,0LL) << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}