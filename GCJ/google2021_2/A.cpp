#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;
using ll = long long;

ll min_index(ll l,ll r){
    cout << "M " << l << " " << r  << endl;
    ll index;
    cin >> index;
    return index;
}

ll solve(ll N){
    for(int i = 1;i < N;i++){
        ll index = min_index(i,N);
        // cerr << index << endl;
        if (index != i){
            cout << "S " << i << " " << index << endl;
            ll swapped;
            cin >> swapped;
        }
    }
    cout << "D" << endl;
    ll result;
    cin >> result;
    // cerr << result << endl;
    return 0;
}
int main()
{
    // 整数の入力
    ll T,N;
    cin >> T >> N;
    // cerr << T << endl;
    for (int i = 1; i <= T; i++)
    {
        solve(N);
    }
    return 0;
}