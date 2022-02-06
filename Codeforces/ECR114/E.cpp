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

int solve()
{

    ll n,k;
    scanf("%lld",&n);
    scanf("%lld",&k);
    string s;
    cin >> s;
    vector<pair<char,ll>> runlength;
    char last_char = '* ';
    ll last_char_length = 0;
    for(int i = 0;i < n;i++){
      if (last_char != s[i]){
        if (last_char_length > 0){
          runlength.push_back({last_char,last_char_length});
        }
        last_char = s[i];
        last_char_length = 1;
      }else{
        last_char++;
      }
    }
    runlength.push_back({last_char,last_char_length});
    return 0;
}
int main()
{
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    return 0;
}