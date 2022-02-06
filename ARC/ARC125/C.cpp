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

int main()
{
  ll N,K;
  cin >> N >> K;
  vector<ll> A(K);
  set<ll> can_use;
  for(int i = 1;i <=N; i++){
    can_use.insert(i);
  }
  for(int i =0 ;i < K;i++){
    cin >> A[i];
    can_use.erase(A[i]);
  }
  vector<ll> answer;
  ll current_length = 0;
  vector<ll> temp;
  ll a_head = 0;
  ll itaration = 0;
  while(true){
    itaration++;
    if (itaration == 10){
      break;
    }
    // cout << can_use.size() << " " << a_head << endl;
    auto iter = can_use.end();
    if (iter == can_use.begin()){
      break;
    }
    iter--;
    ll current = *iter;
    ll a_greater_count = A.end() - lower_bound(A.begin()+a_head,A.end(),current);
    ll new_length = max(current_length+1,a_greater_count+1);
    // cout << "new_length"<< new_length << endl;
    if (new_length <= K){
      current_length = new_length;
      temp.push_back(current);
      can_use.erase(current);
    }else if (a_head < K && current < A[a_head]){
      temp.push_back(A[a_head]);
      a_head++;
    }else if (temp.size() == 0){
      temp.push_back(A[a_head]);
      a_head++;
      current_length = K;
    }else{
      current_length = K;
    }
    if (current_length == K){
      reverse(temp.begin(),temp.end());
      for(auto t:temp){
        answer.push_back(t);
      }
      temp.clear();
      current_length = 0;
    }
  }
  reverse(temp.begin(),temp.end());
  for(auto t:temp){
    answer.push_back(t);
  }

  for(int i = a_head;i < K;i++){
    answer.push_back(A[i]);
  }
  for(int i = 0;i < answer.size();i++){
    if (i!= 0){
      cout << " ";
    }
    cout << answer[i];
  }
  cout << endl;
  return 0;
}
