#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>
using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int solve()
{
    string S;
    cin >> S;
    ll n = S.size();
    for(int i = n-2;i >= 0;i--){
        if ( (S[i] - '0') + (S[i+1] - '0') >= 10){
            cout << S.substr(0,i) << (S[i] - '0') + (S[i+1] - '0') << S.substr(i+2) << endl;
            return 0;
        }
    }
    cout << (S[0] - '0') + (S[1] - '0') << S.substr(2) << endl;
    return 0;
}
int main()
{
    ll t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    cout << flush;
    return 0;
}
