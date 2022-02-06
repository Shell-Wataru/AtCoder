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
    ll remain = n - (k - 3);
    if (remain % 4 == 0){
        cout << remain/4 << " " << remain/4 << " " <<  remain/2;
    }else if (remain % 4 == 1){
        cout << 1 << " " << (remain-1)/2 << " " << (remain -1)/2;
    }else if (remain % 4 == 2){
        cout << (remain-2)/2 << " " << (remain-2)/2 << " " <<  2;
    }else{
        cout << 1 << " " << (remain-1)/2 << " " << (remain -1)/2;
    }
    for(int i = 0;i < k -3;i++){
        cout << " " << 1;
    }
    cout << "\n";
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
