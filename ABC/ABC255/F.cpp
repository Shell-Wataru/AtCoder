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

int solve()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> B(N);
    vector<ll> revB(N);
    for(int i = 0;i < N;i++){
      cin >> A[i];
      A[i]--;
    }
    for(int i = 0;i < N;i++){
      cin >> B[i];
      B[i]--;
      revB[B[i]] = i;
    }
    if (A[0] != 0){
      cout << -1 << endl;
      return 0;
    }
    vector<pair<ll,ll>> answers(N,{-1,-1});
    set<ll> indices;
    indices.insert(revB[0]);
    vector<pair<ll,ll>> q;
    q.push_back({revB[0],0});
    for(int i = 1;i < N;i++){
      // cout << i << endl;
      if (revB[A[i]] < q.back().first){
        auto iter = indices.lower_bound(q.back().first);
        if (iter == indices.begin()){
          answers[q.back().second].first = A[i];
          q.push_back({revB[A[i]],A[i]});
          indices.insert(revB[A[i]]);
        }else{
          iter--;
          if (revB[A[i]] > *iter){
            answers[q.back().second].first = A[i];
            q.push_back({revB[A[i]],A[i]});
            indices.insert(revB[A[i]]);
          }else{
            cout << -1 << endl;
            return 0;
          }
        }
      }else{
        while(!q.empty()){
          auto iter1 = indices.lower_bound(q.back().first);
          auto iter2 = indices.lower_bound(q.back().first);
          iter2++;
          if (*iter1 < revB[A[i]] && (iter2 == indices.end() || revB[A[i]] < *iter2)){
            answers[q.back().second].second = A[i];
            q.pop_back();
            q.push_back({revB[A[i]],A[i]});
            indices.insert(revB[A[i]]);
            break;
          }else{
            indices.erase(q.back().first);
            q.pop_back();
          }
        }
        if (q.empty()){
          cout << -1 << endl;
          return 0;
        }
      }
    }
    for(int i = 0;i < N;i++){
      cout << answers[i].first + 1 << " " << answers[i].second + 1 << "\n";
    }
    return 0;
}

int main()
{
    // ll T;
    // cin >> T;
    // for (int i = 0; i < T; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}
