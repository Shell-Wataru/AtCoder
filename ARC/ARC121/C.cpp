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

int solve(){
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (size_t i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  vector<ll> ans;
  for(int i = 0;i < N;i++){
    ll min_index = -1;
    ll min_a= numeric_limits<ll>::max();
    for(int j = i;j < N;j++){
      if (A[j] < min_a){
        min_a = A[j];
        min_index = j;
      }
    }
    if (min_index == i){
      continue;
    }
    if ( min_index % 2 ==  ans.size() % 2){
      if (min_index-2 >= i){
        ans.push_back(min_index-1);
        swap(A[min_index-2],A[min_index-1]);
      }else if(min_index + 3 < N){
        ans.push_back(min_index+3);
        swap(A[min_index+2],A[min_index+3]);
      }else if (min_index != N-1){
        ans.push_back(min_index+1);
        swap(A[min_index],A[min_index+1]);
        ans.push_back(min_index);
        swap(A[min_index-1],A[min_index]);
        min_index++;
      }else{
        ans.push_back(min_index-1);
        swap(A[min_index-2],A[min_index-1]);
        ans.push_back(min_index);
        swap(A[min_index-1],A[min_index]);
        ans.push_back(min_index-1);
        swap(A[min_index-2],A[min_index-1]);
        ans.push_back(min_index);
        swap(A[min_index-1],A[min_index]);
        ans.push_back(min_index-1);
        swap(A[min_index-2],A[min_index-1]);
        continue;
      }
    }
    for(int j = min_index - 1;j >= i;j--){
      ans.push_back(j+1);
      swap(A[j],A[j+1]);
    }
  }
  cout << ans.size() << endl;
  for(int i = 0;i < ans.size();i++){
    if (i != 0){
      cout << " ";
    }
    // if (i % 2 == ans[i] % 2){
    //   cout << "!!" << endl;
    // }
    cout << ans[i];
  }
  cout << endl;
  // for(auto a:A){
  //   cout << a << ",";
  // }
  // cout << endl;
  return 0;
}
int main()
{
  ll T;
  cin >> T;
  for (size_t i = 0; i < T; i++)
  {
    solve();
  }

  return 0;
}