#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <list>
using namespace std;
using ll = long long;
const ll BASE_NUM = 1000000007;

ll share_count(string &a,string &b){
  ll i = 0;
  for(auto c:a){
    if (c == b[i]){
      i++;
    }
  }
  return i;
}

string merged_string(string &a, string &b){
  string ans = "";
  ll i = 0;
  for(auto c:a){
    ans += c;
    if (c == b[i]){
      i++;
    }
  }
  for(;i < b.size();i++){
    ans += b[i];
  }
  return ans;
}
int solve()
{
    ll n;
    scanf("%lld", &n);
    string a,b,c;
    cin >> a >> b >> c;
    cout << share_count(a,b) << endl;
    cout << share_count(b,c) << endl;
    cout << share_count(c,a) << endl;
    cout << share_count(a,c) << endl;
    cout << share_count(c,b) << endl;
    cout << share_count(b,a) << endl;
    if (share_count(a,b) >= n){
      cout << merged_string(a,b) << "\n";
    }else if (share_count(b,c) >= n){
      cout << merged_string(b,c) << "\n";
    }else if (share_count(c,a) >= n){
      cout << merged_string(c,a) << "\n";
    }else if (share_count(a,c) >= n){
      cout << merged_string(a,c) << "\n";
    }else if (share_count(c,b) >= n){
      cout << merged_string(c,b) << "\n";
    }else if (share_count(b,a) >= n){
      cout << merged_string(b,a) << "\n";
    }else{
      cout << a << "," << b << "," << c << "\n";
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
