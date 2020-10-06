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
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
  // 整数の入力
  ll N;
  string S;
  cin >> N;
  cin >> S;
  vector<ll> Rs(N,0);
  vector<ll> Gs(N,0);
  vector<ll> Bs(N,0);
  for(int i = 0;i< N;i++){
    if (S[i] == 'R'){
      Rs[i] = 1;
    }else if(S[i] == 'G'){
      Gs[i] = 1;
    }else
    {
      Bs[i] = 1;
    }
  }
  for(int i = 1;i< N;i++){
      Rs[i] += Rs[i-1];
      Gs[i] += Gs[i-1];
      Bs[i] += Bs[i-1];
  }

  ll total = 0;
  for(int i = 0;i< N;i++){
    for(int j = i + 1;j<N;j++){
      // cout << i << " " << j << ":" << total << endl;
      ll bad_index = j + (j - i);
      if ((S[i] == 'R' && S[j] == 'G') || (S[i] == 'G' && S[j] == 'R')){
        total += Bs[N-1] - Bs[j];
        if (bad_index < N && S[bad_index] == 'B'){
          total--;
        }
      }else if ((S[i] == 'G' && S[j] == 'B') || (S[i] == 'B' && S[j] == 'G')){
        total += Rs[N-1] - Rs[j];
        if (bad_index < N && S[bad_index] == 'R'){
          total--;
        }
      }else if ((S[i] == 'B' && S[j] == 'R') || (S[i] == 'R' && S[j] == 'B')){
        total += Gs[N-1] - Gs[j];
        if (bad_index < N && S[bad_index] == 'G'){
          total--;
        }
      }
    }
  }
  cout << total << endl;
  return 0;
}