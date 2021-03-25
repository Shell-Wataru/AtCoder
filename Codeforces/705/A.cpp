#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <cmath>
#include <iterator>

using namespace std;
using ll = long long;

int solve()
{
  ll n,k;
  scanf("%lld",&n);
  scanf("%lld",&k);
  vector<ll> answers;
  for(int i = n;i>= 1;i--){
    if (i == k){
      continue;
    }else{
      if (answers.empty()){
        answers.push_back(i);
      }else if(i + answers.back() > k){
        answers.push_back(i);
      }else{
        break;
      }
    }
  }
  cout << answers.size() << "\n";
  for (size_t i = 0; i < answers.size(); i++)
  {
    if(i!= 0){
      cout << " ";
    }
    cout << answers[i];
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