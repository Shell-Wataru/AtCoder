#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>
#include <bitset>
#include <numeric>

using namespace std;
using ll = long long;
const long long BASE_NUM = 1000000007;

int solve()
{
  ll Awin,Bwin;
  scanf("%lld", &Awin);
  scanf("%lld", &Bwin);
  set<ll> answers;
  if ( (Awin+Bwin) %2 ==0 ){
    ll serves = (Awin+Bwin)/2;
    for(int a_x = 0;a_x <= Awin+Bwin;a_x++){
      ll a_y = Awin - a_x;
      ll b_x = serves - a_y;
      ll b_y = serves - a_x;
      if (a_x >= 0 && a_y >= 0 && b_x >= 0 && b_y >= 0 && b_x + b_y == Bwin ){
        answers.insert(a_y+ b_y);
      }
    }
  }else{
    ll Aserves = (Awin+Bwin)/2;
    ll Bserves = (Awin+Bwin)/2 + 1;
    for(int a_x = 0;a_x <= Awin+Bwin;a_x++){
      ll a_y = Awin - a_x;
      ll b_x = Bserves - a_y;
      ll b_y = Aserves - a_x;
      if (a_x >= 0 && a_y >= 0 && b_x >= 0 && b_y >= 0 && b_x + b_y == Bwin ){
        answers.insert(a_y+ b_y);
      }
    }
    Aserves = (Awin+Bwin)/2 + 1;
    Bserves = (Awin+Bwin)/2;
    for(int a_x = 0;a_x <= Awin+Bwin;a_x++){
      ll a_y = Awin - a_x;
      ll b_x = Bserves - a_y;
      ll b_y = Aserves - a_x;
      if (a_x >= 0 && a_y >= 0 && b_x >= 0 && b_y >= 0 && b_x + b_y == Bwin ){
        answers.insert(a_y+ b_y);
      }
    }
  }
  vector<ll> answer_array(answers.begin(),answers.end());
  cout << answer_array.size() << "\n";
  for(int i = 0;i < answer_array.size();i++){
    if (i != 0){
      cout << " ";
    }
    cout << answer_array[i];
  }
  cout << "\n";
  return 0;
}

int main()
{
  ll t;
  cin >> t;

  for (int i = 1; i <= t; i++)
  {
    solve();
  }
  cout << flush;
  return 0;
}