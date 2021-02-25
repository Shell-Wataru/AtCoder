#define _USE_MATH_DEFINES
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

    return 0;
}
int main()
{
    // 整数の入力
    vector<ll> answers;
    for(ll i = 3;i <= 200000;i+=2){
        ll c = (i*i+1)/2;
        answers.push_back(c);
    }
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        ll n;
        scanf("%lld",&n);
        // cout << *upper_bound(answers.begin(),answers.end(),n) << endl;
        ll ans = upper_bound(answers.begin(),answers.end(),n) - answers.begin();
        cout << ans << "\n";
    }
    cout << flush;
    return 0;
}
