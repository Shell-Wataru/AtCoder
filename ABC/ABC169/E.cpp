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
ll BASE_NUM = 1000000007;

int main()
{
  // 整数の入力
  ll N;
  cin >> N;
  vector<pair<ll,ll>> AB;
  map<ll,ll> unzip_data;
  map<ll,ll> zip_data;
  for (int i = 0; i < N; i++)
  {
    ll a, b;
    scanf("%lld%lld", &a, &b);
    zip_data[a]= 1;
    zip_data[b] = 1;
    AB.push_back({a,b});
  }
  ll i = 0;
  for(auto &p:zip_data){
    p.second = i;
    unzip_data[p.second] = p.first;
    i++;
  }
  sort(AB.begin(),AB.end());
  vector<ll> before_numbers_min(zip_data.size(),0);
  vector<ll> before_numbers_max(zip_data.size(),0);
  for(auto p:AB){
    before_numbers_max[zip_data[p.first]]++;
    before_numbers_min[zip_data[p.second]]++;
  }
  for(int i =1;i < zip_data.size();i++){
    before_numbers_min[i] += before_numbers_min[i-1];
    before_numbers_max[i] += before_numbers_max[i-1];
  }
  // for(auto i: before_numbers_min){
  //   cout << i << ",";
  // }
  // cout << endl;
  // for(auto i: before_numbers_max){
  //   cout << i << ",";
  // }
  // cout << endl;
  ll start_index_min = -1;
  ll end_index_min = -1;
  ll start_index_max = -1;
  ll end_index_max = -1;
  ll start_count = (N+1)/2;
  ll end_count = (N+2)/2;
  for(int i = 0;i < zip_data.size();i++){
    if(start_index_min == -1){
      if(before_numbers_max[i] >= start_count){
        start_index_min = i;
      }
    }
    if(start_index_max == -1){
      if(before_numbers_min[i] >= start_count){
        start_index_max = i;
      }
    }
    if (end_index_max == -1){
      if(before_numbers_min[i] >= end_count){
        end_index_max = i;
      }
    }
    if (end_index_min == -1){
      if(before_numbers_max[i] >= end_count){
        end_index_min = i;
      }
    }
  }

  // cout << start_index_min << start_index_max << endl;
  // cout << end_index_min << end_index_max << endl;
  // cout << unzip_data[start_index] << unzip_data[end_index] << endl;
  if (N % 2 == 0){
    ll max_val = unzip_data[start_index_max] + unzip_data[end_index_max];
    ll min_val = unzip_data[start_index_min] + unzip_data[end_index_min];
    cout << max_val - min_val + 1 << endl;
  }else{
    ll max_val = unzip_data[start_index_max];
    ll min_val = unzip_data[start_index_min];
    cout << max_val - min_val + 1 << endl;
  }
  return 0;
}
