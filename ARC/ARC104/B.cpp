#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>
#include <numeric>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

const long long BASE_NUM = 1000000007;

int main()
{
  ll N;
  string S;
  cin >> N;
  cin >> S;
  vector<ll> a_count(N+1,0);
  vector<ll> t_count(N+1,0);
  vector<ll> c_count(N+1,0);
  vector<ll> g_count(N+1,0);
  for(int i = 0;i < N;i++){
    if(S[i] == 'A'){
      a_count[i+1] = a_count[i] + 1;
      g_count[i+1] = g_count[i];
      c_count[i+1] = c_count[i];
      t_count[i+1] = t_count[i];
    }else if (S[i] == 'G'){
      a_count[i+1] = a_count[i];
      g_count[i+1] = g_count[i] + 1;
      c_count[i+1] = c_count[i];
      t_count[i+1] = t_count[i];
    }else if (S[i] == 'C'){
      a_count[i+1] = a_count[i];
      g_count[i+1] = g_count[i];
      c_count[i+1] = c_count[i] + 1;
      t_count[i+1] = t_count[i];
    }else if (S[i] == 'T'){
      a_count[i+1] = a_count[i];
      g_count[i+1] = g_count[i];
      c_count[i+1] = c_count[i];
      t_count[i+1] = t_count[i] + 1;

    }
  }
  ll ans = 0;
  for(int i = 0;i < N;i++){
    for(int j = i + 1;j <= N;j++){
      ll a = a_count[j] - a_count[i];
      ll g = g_count[j] - g_count[i];
      ll c = c_count[j] - c_count[i];
      ll t = t_count[j] - t_count[i];
      // cout << "i" << i << "j" << j << endl;
      // cout << a << " " << t << endl;
      // cout << c << " " << g << endl;
      if (a == t && c == g){
        // cout << "!" << endl;
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}