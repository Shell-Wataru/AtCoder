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

int solve()
{

    ll s,n,k;
    scanf("%lld",&s);
    scanf("%lld",&n);
    scanf("%lld",&k);
    if (n > s){
      cout << "No\n";
    }else if (n < k){
      cout << "No\n";
    }else if(n == k){
      cout << "Yes\n";
    }else{
      for(int i = 1;i * n <= s;i++){
        if (n % i == 0){
          if (i * (n-1) < k && k < s - (n-1)*i ){
            cout << "No\n";
            return 0;
          }else if (k % i != 0){
            cout << "No\n";
            return 0;
          }
        }
      }
      cout << "Yes\n";
    }
    return 0;
}
int main()
{
    int t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}