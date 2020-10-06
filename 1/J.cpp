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
#include <set>
using namespace std;
using ll = long long;

ll BASE_NUM = 1000000007;


int main()
{
    // 整数の入力
    ll N,M;
    cin >> N >> M;
    vector<ll> children(N,-1);
    for(int i = 0;i < M;i++){
        ll a;
        cin >> a;
        auto iter = upper_bound(children.begin(),children.end(),a,greater<ll>());
        (*iter) = a;

        if (iter == children.end()){
            cout << -1 << endl;
        }else{
            cout << iter - children.begin() + 1 << endl;
        }
    }
    // for(int i = 0;i < N;i++){
    //     cout << children[i] << endl;
    // }
    return 0;
}