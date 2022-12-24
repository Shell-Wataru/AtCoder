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

int main()
{
  ll Q;
  cin >> Q;
  vector<ll> A;
  vector<ll> B;
  for(int i = 0;i < Q;i++){
      ll t,x;
      cin >> t >> x;
      if (t == 1){
          A.push_back(x);
      }else if(t == 2){
          B.push_back(x);
      }else{
          x--;
          if (x < A.size()){
              cout << A[A.size()-1 - x] << endl;
          }else{
              cout << B[(x- A.size())] << endl;
          }
      }
  }
  return 0;
}
