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
ll BASE_NUM = 1000000007;


int solve()
{
    // cout << "==" << endl;
    ll A,B,C,D;
    cin >> A >> B >> C >> D;
    vector<ll> AB(1000001,0);
    for(int i = A;i <= B;i++){
        AB[i+B]++;
        AB[i+C+1]--;
    }

    for(int i = 1;i <= 1000000;i++){
        AB[i] +=  AB[i-1];
    }
    for(int i = 1000000 -1;i >= 0;i--){
        AB[i] +=  AB[i+1];
    }
    ll total = 0;
    // for(int i = 0;i < 10;i++){
    //     cout << i << ":" <<AB[i] << endl;
    // }
    for(int i = C;i<=D;i++){
        total += AB[i+1];
    }
    cout << total << endl;
    return 0;
}
int main()
{
    // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
    // }
    // cout << flush;
    return 0;
}
