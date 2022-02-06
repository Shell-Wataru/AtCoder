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

string concat(vector<string> &S,ll K){
  string ans;
  for(int i = 0;i < K;i++){
    ans+= S[i];
  }
  return ans;
}

void insert(vector<string> &S, ll x,ll y){
  if (x < y){
    for(int i = x;i < y;i++){
      swap(S[i],S[i+1]);
    }
  }else{
    for(int i = x;i > y;i--){
      swap(S[i],S[i-1]);
    }
  }
}
int main()
{
  ll N,K;
  cin >> N >> K;
  vector<string> S(N);
  for(int i = 0; i < N;i++){
    cin >> S[i];
  }
  sort(S.begin(),S.end());
  string current = concat(S,K);
  bool is_changed = true;
  while(is_changed){
    is_changed = false;
    for(int i = 0;i < N;i++){
      for(int j = 0;j < N;j++){
        insert(S,i,j);
        string new_current = concat(S,K);
        if (new_current < current){
          is_changed = true;
          current = new_current;
          break;
        }else{
          insert(S,j,i);
        }
      }
      if (is_changed){
        break;
      }
    }
  }
  cout << concat(S,K) << endl;
  return 0;
}


