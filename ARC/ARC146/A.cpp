#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int solve()
{
  ll N;
  cin >> N;
  vector<vector<string>> S(7);
  for(int i = 0;i < N;i++){
    string s;
    cin >> s;
    S[s.size()].push_back(s);
  }
  for(int i = 0;i < 7;i++){
    sort(S[i].begin(),S[i].end());
  }
  vector<string> use;
  while(use.size() < 3){
    while(S.back().empty()){
      S.pop_back();
    }
    use.push_back(S.back().back());
    S.back().pop_back();
  }
  ll ans = 0;
  sort(use.begin(),use.end());
  do{
    ans = max(ans,stoll(use[0]+use[1]+use[2]));
  }while(next_permutation(use.begin(),use.end()));
  cout << ans << endl;
  return 0;
}
int main()
{
  // ll T;
  // cin >> T;
  // for(int i = 0;i < T;i++){
  solve();
  // }
  cout << flush;
  return 0;
}