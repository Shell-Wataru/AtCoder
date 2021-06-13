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
    string S;
    cin >> S;
    if (S.size() <= 2){
        cout << "YES" << endl;
    }else{
        ll a = S[0] - 'A';
        ll b = S[1] - 'A';
        for(int i = 2;i < S.size();i++){
            ll c = S[i] - 'A';
            if ( (a + b) % 26 != c){
                cout << "NO" << endl;
                return 0;
            }
            a = b;
            b = c;
        }
        cout << "YES" << endl;
    }
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
    return 0;
}
