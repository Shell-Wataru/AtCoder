#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <set>
#include <atcoder/string>
#include <unordered_map>
using namespace std;
using ll = long long;
using namespace atcoder;

ll naive(ll n, string S, string T)
{
  ll ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
      // cout << S.substr(i, n - i) + S.substr(0,i) << " " << T.substr(j, n - j) + T.substr(0,j) << endl;
      if (S.substr(i, n - i) + S.substr(0,i) <= T.substr(j, n - j) + T.substr(0,j))
      {
        ans++;
      }
    }
  return ans;
}

ll solve(ll n, string S, string T)
{
  // cout << ('z' < '{')  << endl;
  string SSTT = T + T + "{"+ S + S;
  auto sa_ss = suffix_array(SSTT);
  ll remain_t_count = n;
  ll ans = 0;
  for (int i = 0; i < 4 * n; i++)
  {
    // cout << sa_ss[i] << ",";
    if (0 <= sa_ss[i] && sa_ss[i] < n)
    {
      // ans += remain_t_count;
      remain_t_count--;
    }
    else if (2 * n + 1<= sa_ss[i] && sa_ss[i] < 3 * n + 1)
    {
      ans += remain_t_count;
      // remain_t_count--;
    }
  }
  return ans;
}
int main()
{
  ll N;
  string S, T;
  // cout << (char)('z'+1) << endl;
  cin >> N >> S >> T;
  // cout << naive(N,S,T) << endl;
  cout << solve(N,S,T) << endl;
  // for(int i = 0;i< 10000;i++){
  //   string S;
  //   string T;
  //   std::random_device rnd;     // 非決定的な乱数生成器でシード生成機を生成
  //   std::mt19937 mt(rnd()); //  メルセンヌツイスターの32ビット版、引数は初期シード
  //   std::uniform_int_distribution<> rand100(0, 4);     // [0, 99] 範囲の一様乱数
  //   ll n = 4;
  //   for(int i = 0;i < n;i++){
  //     S += 'a' +rand100(mt);
  //     T += 'a' +rand100(mt);
  //   }
  //   // cout << S << T << endl;
  //   if (naive(n,S,T) != solve(n,S,T)){
  //     cout << S << endl;
  //     cout << T << endl;
  //   }
  // }
  return 0;
}
