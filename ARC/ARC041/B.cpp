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

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
  ll N,M;
  cin >> N >> M;
  vector<vector<ll>> B(N,vector<ll>(M,0));
  vector<vector<ll>> A(N,vector<ll>(M,0));
  for (size_t i = 0; i < N; i++)
  {
    string S;
    cin >> S;
    for (size_t j = 0; j < M; j++)
    {
      B[i][j] = S[j] - '0';
    }

  }
  for(int i = 1;i < N-1 ;i++){
    for (size_t j = 1; j < M-1; j++)
    {
      A[i][j] = B[i-1][j];
      B[i][j-1] -= A[i][j];
      B[i][j+1] -= A[i][j];
      B[i+1][j] -= A[i][j];
    }
  }

  for(int i = 0;i < N ;i++){
    for (size_t j = 0; j < M; j++)
    {
      cout << A[i][j];
    }
    cout << endl;
  }
  return 0;
}