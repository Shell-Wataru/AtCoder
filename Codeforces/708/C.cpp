#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>

using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

int solve()
{
    ll n, k;
    scanf("%lld", &n);
    scanf("%lld", &k);
    if (n % 4 == 0){
        cout << n/4 << " " << n/4 << " " <<  n/2 << "\n";
    }else if (n % 4 == 1){
        cout << 1 << " " << (n-1)/2 << " " << (n -1)/2 << "\n";
    }else if (n % 4 == 2){
        cout << (n-2)/2 << " " << (n-2)/2 << " " <<  2 << "\n";
    }else{
        cout << 1 << " " << (n-1)/2 << " " << (n -1)/2 << "\n";
    }
    return 0;
}

int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    cout << flush;
    return 0;
}
