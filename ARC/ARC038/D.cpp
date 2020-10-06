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
namespace mp = boost::multiprecision;

ll alpha_beta(ll current, ll depth,vector<vector<ll>> &G,  vector<ll> &X,set<ll> &parents, ll alpha, ll beta){
  if (parents.find(current) != parents.end()){
    if (depth % 2 == 0){
      return X[current];
    }else{
      return numeric_limits<ll>::min();
    }
  }else if (depth == 0){
    return X[current];
  }

  if (depth % 2 == 0){
    alpha = max(alpha,X[current]);
    if (alpha >= beta){
      return alpha;
    }
    parents.insert(current);

    for(int i = G[current].size() - 1; i >= 0;i--){
      ll to = G[current][i];
      alpha = max(alpha,alpha_beta(to, depth-1,G,X,parents,alpha,beta));
      if (alpha >= beta){
        break;
      }
    }
    parents.erase(current);
    return alpha;
  }else{
    beta = min(beta,X[current]);
    if (alpha >= beta){
      return beta;
    }
    parents.insert(current);
    for(int i = 0;i < G[current].size();i++){
      ll to = G[current][i];
      beta = min(beta,alpha_beta(to, depth-1,G,X,parents,alpha,beta));
      if (alpha >= beta){
        break;
      }
    }
    parents.erase(current);
    return beta;
  }
}

int main()
{
  // 整数の入力
  ll N,M;
  cin >> N >> M;
  vector<vector<ll>> G(N);
  vector<ll> X0(N);
  vector<ll> X2(N);
  vector<bool> visited(N,false);
  for(int i = 0;i < N;i++){
    cin >> X0[i];
  }
  for(int i = 0;i < M;i++){
    ll a,b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
  }
  set<ll> parents;
  for(int i = 0;i< N;i++){
    X1[i] = alpha_beta(0,1,G,X0,parents,numeric_limits<ll>::min(),numeric_limits<ll>::max())
  }
  cout << alpha_beta(0,1000000000,G,X,parents,numeric_limits<ll>::min(),numeric_limits<ll>::max()) << endl;
  return 0;
}