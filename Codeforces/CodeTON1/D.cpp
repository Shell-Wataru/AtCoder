#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;


int solve()
{
    ll n;
    scanf("%lld", &n);
    ll original = n;
    for(int i = 0;i <= 60;i++){
      if (n == 1ll<<i){
        cout << original << ":" << -1 << "\n";
        return 0;
      }
    }
    ll base = 2;
    while(n % base == 0){
      base *= 2;
    }
    base /=2;
    cout << base << endl;
    ll k = 2;
    n -= 3;
    while(n % k  != 0){
      k++;
      n -= k;
      if (n < 0){
        cout << original << ":" << -1 << "\n";
        return 0;
      }
    }

    cout << original << ":" << k << "\n";

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
