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

struct node
{
  ll x, y, d;
};
int main()
{
  // 整数の入力
  ll N, M;
  cin >> N >> M;
  vector<ll> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  map<ll, ll> counts;
  for (int i = 0; i < M; i++)
  {
    counts[A[i]]++;
  }
  ll mex = M;
  for (int i = 0; i < N; i++)
  {
    if (counts.find(i) == counts.end())
    {
      mex = i;
      break;
    }
  }

  ll min_mex = mex;
  for (int i = 1; i + M - 1 < N; i++)
  {
    counts[A[i - 1]]--;
    counts[A[i + M - 1]]++;
    if (counts[A[i - 1]] == 0)
    {
      counts.erase(A[i - 1]);
    }
    if (counts.find(A[i - 1]) == counts.end() && A[i - 1] < mex)
    {
      mex = A[i - 1];
    }
    else if (counts.find(mex) != counts.end())
    {
      auto iter = counts.find(mex);
      iter++;
      if (iter == counts.end())
      {
        mex = mex + 1;
      }
      else
      {
        mex = iter->first;
      }
    }
    min_mex = min(mex, min_mex);
  }
  cout << min_mex << endl;
  return 0;
}
