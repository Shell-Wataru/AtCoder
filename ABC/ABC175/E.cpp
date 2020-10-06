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
using namespace std;
using ll = long long;

const long long BASE_NUM = 1000000007;

int main()
{
  // 整数の入力
  ll H,W,M;
  cin >> H >> W >> M;
  vector<ll> row_bomb_counts(H,0);
  vector<ll> column_bomb_counts(W,0);
  set<pair<ll,ll>> bombs;
  for(int i = 0;i < M;i++){
    ll h,w;
    cin >> h >> w;
    h--;
    w--;
    row_bomb_counts[h]++;
    column_bomb_counts[w]++;
    bombs.insert({h,w});
  }
  vector<pair<ll,ll>> row_bomb_count_pairs;
  vector<pair<ll,ll>> column_bomb_count_pairs;
  for(int i = 0;i < H;i++){
    row_bomb_count_pairs.push_back({row_bomb_counts[i],i});
  }
  for(int i = 0;i < W;i++){
    column_bomb_count_pairs.push_back({column_bomb_counts[i],i});
  }
  sort(row_bomb_count_pairs.begin(),row_bomb_count_pairs.end(),greater<pair<ll,ll>>());
  sort(column_bomb_count_pairs.begin(),column_bomb_count_pairs.end(),greater<pair<ll,ll>>());
  while(row_bomb_count_pairs.front().first != row_bomb_count_pairs.back().first){
    row_bomb_count_pairs.pop_back();
  }
  while(column_bomb_count_pairs.front().first != column_bomb_count_pairs.back().first){
    column_bomb_count_pairs.pop_back();
  }
  bool has_no_set = false;
  for(auto rp:row_bomb_count_pairs){
    for(auto cp:column_bomb_count_pairs){
      // cout << rp.second << "," << cp.second << endl;
      if (bombs.find({rp.second,cp.second}) == bombs.end()){
        has_no_set = true;
        break;
      }
    }
  }
  if (has_no_set){
    cout << row_bomb_count_pairs.front().first + column_bomb_count_pairs.front().first << endl;
  }else{
    cout << row_bomb_count_pairs.front().first + column_bomb_count_pairs.front().first - 1<< endl;
  }
  return 0;
}
