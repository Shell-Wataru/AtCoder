#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
double MAX_VALUE = 1000001;

//arc027 dで使用
// ここを参考にした　https://ei1333.github.io/luzhiled/snippets/structure/sqrt-decomposition.html
// updateは未実装
struct SqrtDecomposition
{
  int N, B, K;
  vector<int> data;
  vector<int> block;

  SqrtDecomposition(int N) : N(N)
  {
    B = (int)sqrt(N);
    K = (N + B - 1) / B;

    block.assign(K, 0);
    data.assign(N, 0);
  }

  void set(int k, int &x)
  {
    data[k] = x;
  }

  void build()
  {
    for (int k = 0; k < K; k++)
    {
      int min_val = numeric_limits<int>::max();
      for (int i = k * B; i < min((k + 1) * B, N); i++)
      {
        min_val = min(min_val,data[i]);
      }
      // cout << m << endl;
      block[k] = min_val;
    }
  }

  int query(int a, int b) {
    int min_val = numeric_limits<int>::max();

    for(int k = K - 1; k >=0; k--) {
      int l = k * B;
      int r = min(l + B, N);

      if(r <= a || b <= l) {

      } else if(a <= l && r <= b) {
        min_val = min(min_val,block[k]);
      } else {
        for(int i = min(b, r) - 1; i >= max(a, l); i--) {
            min_val = min(min_val,data[i]);
        }
      }
    }
    return min_val;
  }

};

int main() {
  vector<int> a{1,2,3,4,5,6,7,8};
  SqrtDecomposition sqrt_dec(a.size());
  for(int i = 0;i < a.size();i++){
      sqrt_dec.set(i, a[i]);
  }
  sqrt_dec.build();
  cout << sqrt_dec.query(0,a.size()) << endl;
  cout << sqrt_dec.query(5,a.size()) << endl;
}