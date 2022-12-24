#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <unordered_set>
#include <numeric>

using namespace std;
using ll = long long;

int solve()
{
  ll N,M;
  cin >> N >> M;
  vector<string> S(N);
  ll total_length = 0;
  for(int i = 0;i < N;i++){
    cin >> S[i];
    total_length += S[i].size();
  }
  unordered_set<string> T;
  for(int i = 0;i < M;i++){
    string t;
    cin >> t;
    T.insert(t);
  }
  if (N == 1){
    if (S[0].size() >= 3 && !T.count(S[0])){
        cout << S[0] << "\n";
    }else{
        cout << -1 << "\n";
    }
    return 0;
  }
  vector<ll>  order(N);
  iota(order.begin(),order.end(),0);
  do{
    // cout << "!" << endl;
    for(int i = 0;i + total_length+ N-1 <= 16;i++){
        vector<ll> under_bars(N-2+i,0);
        for(int j = 0;j < i;j++){
            under_bars[j] = 1;
        }
        reverse(under_bars.begin(),under_bars.end());
        do{
            ll under_index = 0;
            string ans = S[order[0]];
            for(int j = 1;j < N;j++){
                ll under_count = 1;
                while(under_index < under_bars.size() && under_bars[under_index] == 1){
                    under_count++;
                    under_index++;
                }
                // cout << "?"  << endl;
                ans += string(under_count,'_');
                ans += S[order[j]];
                under_index++;
            }
            // cout << ans << endl;
            if (ans.size() >= 3 && !T.count(ans)){
                cout << ans  << "\n";
                return 0;
            }
        }while(next_permutation(under_bars.begin(),under_bars.end()));
    }
  }while(next_permutation(order.begin(),order.end()));
  cout << -1 << "\n";
  return 0;
}
int main()
{
//   ios_base::sync_with_stdio(0); cin.tie(0);
//   int t;
//   cin >> t;
//   for (size_t i = 0; i < t; i++)
//   {
  solve();
//   }
  cout << flush;
  return 0;
}