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

double patterns(ll A, ll B, ll a,ll b,vector<double> &factorials){
  double choose_a = factorials[A]/(factorials[a]*factorials[A-a]);
  double choose_b = factorials[B]/(factorials[b]*factorials[B-b]);
  return choose_a * choose_b * factorials[a+b];
}

double choose(ll n,ll m, vector<double> &factorials){
  return factorials[n]/(factorials[n-m] * factorials[m]);
}
int main()
{
  // 整数の入力
  ll A, B, C;
  cin >> A >> B >> C;
  vector<ll> As(A), Bs(B);
  vector<double>  means;
  means.push_back(0);
  vector<double> factorials;
  factorials.push_back(1);
  for(int i = 1;i <= 100;i++){
    factorials.push_back(factorials.back()*i);
  }
  double a_mean = 0;
  double b_mean = 1;
  for (int i = 0; i < A; i++)
  {
    cin >> As[i];
    a_mean += As[i];
  }

  for (int i = 0; i < B; i++)
  {
    cin >> Bs[i];
    b_mean *= Bs[i];
  }

// for(int j = 0;j < maginifications.size();j++){
//       cout << maginifications[j] << ",";
//     }
//     cout << endl;
  a_mean /= A;
  b_mean = pow(b_mean,1.0/B);
  ll N = A + B + C;
  for(int i = 1; i<= A;i++){
    means.push_back(a_mean * i);
  }
  for(int i = 0; i < B;i++){
    vector<double> new_means(means.size()+1);
    for(int j = 0;j < means.size();j++){
      for(int k = 0;k < means.size() + 1;k++){
        if (k <= j){
          new_means[k] += means[k];
        }else if(k == j + 1){
          new_means[k] += means[j] * Bs[i];
        }else{
          new_means[k] += means[k-1] +  means[j] * (Bs[i] - 1);
        }
      }
    }
    for(int j = 0;j < new_means.size();j++){
      new_means[j] /= means.size();
    }
    means = new_means;
    for(int j = 0;j < means.size();j++){
      cout << means[j]<< ",";
    }
    cout << endl;
  }

  // for(int i = 0;i <= A;i++){
  //   for(int j = 0;j <= B;j++){
  //     cout << fixed << setprecision(2) << DP[i][j] << ",";
  //   }
  //   cout << endl;
  // }
  double mean = 0;
  double rate = 1.0;
  for(int i = 0;i <= A+B;i++){
    double death_rate = rate*C/(N-i);
    rate = rate*(1.0 - 1.0* C/(N-i));
    mean += death_rate * means[i];
  }
  // cout << a_mean << endl;
  // cout << b_mean << endl;
  cout << mean << endl;
  return 0;
}