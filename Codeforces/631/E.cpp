#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;

ll BASE_NUM = 998224353;


int solve()
{
    ll h,g;
    cin >> h >> g;
    vector<ll> A(1<<h);
    for(int i = 0;i < 1<<h;i++){
        cin >> A[i];
    }

    sort(A.begin(),A.end(),greater<ll>());
    ll total = 0;
    for(int i = 1<<g;i < 1<<h;i++){
        total += A[i];
    }
    cout << total << endl;
    return 0;
}
int main()
{
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}