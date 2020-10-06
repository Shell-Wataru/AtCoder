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
    ll X,Y,A,B,C;
    cin >> X >> Y >> A >> B >> C;
    vector<ll> P(A);
    vector<ll> Q(B);
    vector<ll> R(C);
    for(int i = 0; i < A;i++){
      cin >> P[i];
    }

    for(int i = 0; i < B;i++){
      cin >> Q[i];
    }

    for(int i = 0; i < C;i++){
      cin >> R[i];
    }

    sort(P.begin(),P.end(),greater<ll>());
    sort(Q.begin(),Q.end(),greater<ll>());
    sort(R.begin(),R.end(),greater<ll>());
    priority_queue<ll,vector<ll>,greater<ll>> pp;
    priority_queue<ll,vector<ll>,greater<ll>> qq;
    for(int i = 0;i < X;i++){
      pp.push(P[i]);
    }

    for(int i = 0;i < Y;i++){
      qq.push(Q[i]);
    }
    ll index = 0;
    while(index < C && (R[index] > pp.top() || R[index] > qq.top()) ){
      if (pp.top() < qq.top()){
        pp.pop();
        pp.push(R[index]);
      }else{
        qq.pop();
        qq.push(R[index]);
      }
      index++;
    }

    ll total = 0;
    while(!pp.empty()){
      total += pp.top();
      // cout << pp.top() << " ";
      pp.pop();
    }

    while(!qq.empty()){
      total += qq.top();
      // cout << qq.top() << " ";
      qq.pop();
    }
    // cout << endl;
    cout << total << endl;
    return 0;
}
