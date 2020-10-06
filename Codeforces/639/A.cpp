#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <iterator> // std::rbegin, std::rend
#include <functional>

using namespace std;
using ll = long long;

int solve()
{
  ll n;
  cin >> n;
  set<ll> using_rooms;
  bool can_move = true;
  for (int i = 0; i < n; i++)
  {
    ll a;
    cin >> a;
    ll new_room = (a + i + n * 10000000000) % n;
    if(using_rooms.find(new_room) != using_rooms.end()){
      can_move = false;
    }else{
      using_rooms.insert(new_room);
    }
  }

  if(can_move){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
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
  return 0;
}