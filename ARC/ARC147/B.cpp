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
#include <climits>

using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    vector<ll> P(N);
    for(int i = 0;i < N;i++){
      cin >> P[i];
      P[i]--;
    }
    vector<pair<ll,ll>> answers;
    vector<ll> odd_bads;
    vector<ll> even_bads;
    for(int i = 0;i < N;i++){
      if (i % 2 != P[i] % 2){
        if (P[i] % 2 == 1){
          odd_bads.push_back(i);
        }else{
          even_bads.push_back(i);
        }
      }
    }
    while(!odd_bads.empty()){
      ll i = odd_bads.back();
      ll j = even_bads.back();
      if (i > j){
        swap(i,j);
      }
      while(i+1 < j){
        answers.push_back({i,i+2});
        swap(P[i],P[i+2]);
        i += 2;
      }
      answers.push_back({i,j});
      swap(P[i],P[j]);
      odd_bads.pop_back();
      even_bads.pop_back();
    }
    for(int j = 0;j < N;j++){
      for(int i = 0;i < N-2;i++){

        if (P[i] > P[i+2]){
          answers.push_back({i,i+2});
          swap(P[i],P[i+2]);
        }
      }
    }
    cout << answers.size() << "\n";
    for(auto p:answers){
      if (p.first + 1 == p.second){
        cout << "A " << p.first + 1 << "\n";
      }else{
        cout << "B " << p.first + 1 << "\n";
      }
    }
    cout << flush;
    // for(int i = 0;i < N;i++){
    //   cout << P[i] << ",";
    // }
    // cout << endl;

    return 0;
}