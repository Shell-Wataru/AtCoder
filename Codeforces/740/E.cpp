#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
  ll n;
  scanf("%lld",&n);
  vector<ll> a(n);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
    a[i]--;
  }
  for(int i = 0;i < n;i++){
    if (i % 2 != a[i] % 2){
      cout << -1 << endl;
      return 0;
    }
  }
  ll size = n;
  vector<ll> answers;
  while(size > 1){
    ll greatest_index;
    ll next_greatest_index;
    for(int i = 0;i < size;i++){
      if (a[i] == size-1){
        greatest_index = i;
      }else if(a[i] == size - 2){
        next_greatest_index = i;
      }
    }
    //1
    answers.push_back(greatest_index);
    reverse(a.begin(),a.begin()+greatest_index+1);
    if (greatest_index > next_greatest_index){
      next_greatest_index = greatest_index - next_greatest_index;
    }
    greatest_index = 0;
    //2
    answers.push_back(next_greatest_index-1);
    reverse(a.begin(),a.begin()+next_greatest_index);
    greatest_index = next_greatest_index -1;

    //3
    answers.push_back(next_greatest_index+1);
    reverse(a.begin(),a.begin()+next_greatest_index+2);
    next_greatest_index = 1;
    greatest_index = 2;
    //4
    answers.push_back(2);
    reverse(a.begin(),a.begin()+3);
    next_greatest_index = 1;
    greatest_index = 0;
    //5
    answers.push_back(size-1);
    reverse(a.begin(),a.begin()+size);
    next_greatest_index = 1;
    greatest_index = 0;
    size -= 2;
  }
  // for(auto aa:a){
  //   cout << aa << ",";
  // }
  // cout << endl;
  cout << answers.size() << "\n";
  for(int i = 0;i < answers.size();i++){
    if (i != 0){
      cout << " ";
    }
    cout << answers[i] + 1;
  }
  cout << "\n";
  return 0;
}

int main()
{
  // // 整数の入力
  ll t;
  cin >> t;
  for (size_t i = 0; i < t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}
