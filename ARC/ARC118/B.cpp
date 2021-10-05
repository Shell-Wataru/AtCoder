#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>
#include <map>
#include <boost/multiprecision/cpp_int.hpp>
#include <string>
#include <numeric>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
  ll K,N,M;
  cin >> K >> N >> M;
  vector<ll> A(K);
  for(int i = 0;i < K;i++){
    cin >> A[i];
  }
  vector<ll> B(K);

  ll b_total = 0;
  priority_queue<pair<ll,ll>> q;
  for(int i = 0;i < K;i++){
    B[i] = A[i] * M/N;
    q.push({A[i] * M - B[i] * N,i});
    b_total += B[i];
  }

  for(int i = 0;i < M - b_total;i++){
    auto p = q.top();
    q.pop();
    // cout << p.second << endl;
    B[p.second] += 1;
  }
  for (size_t i = 0; i < K; i++){

    if (i != 0){
      cout << " ";
    }
    cout << B[i];
  }
  cout << endl;
  return 0;
}