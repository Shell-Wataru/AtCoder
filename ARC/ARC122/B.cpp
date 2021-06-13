#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

double value(vector<double> &A,double x){
  double total = 0;
  for(auto a:A){
    total += x + a - min(a,2*x);
  }
  return total/A.size();
}

double three_search(double l,double r,vector<double> &A)
{
  // cout << l << "~" << r << endl;
  if (r-l <= 1e-9 || (r-l)/l <= 1e-9)
  {
    // cout << (l+r)/2 << endl;
    return value(A,(l+r)/2);
  }
  else
  {
    double t1 = (2 * l + r) / 3;
    double t2 = (l + 2 * r) / 3;
    double t1_value = value(A,t1);
    double t2_value = value(A,t2);
    if (t1_value <= t2_value)
    {
      return three_search(l, t2, A);
    }
    else
    {
      return three_search(t1, r, A);
    }
  }
}
int main()
{
  ll N;
  cin >> N;
  vector<double> A(N);
  for(int i = 0;i < N;i++){
    cin >> A[i];
  }
  cout <<fixed << setprecision(12) << three_search(0,1e12,A) << endl;

  return 0;
}