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

using namespace std;
using ll = long long;

int main()
{
  ll N,X,Y;
  cin >> N >> X >> Y;
  vector<ll> A(N);
  for(int i = 0;i < N;i++){
    cin >> A[i];
  }
  bool all_smaller_y = true;
  bool changed = false;
  for(int i = 0;i < N;i++){
    if (A[i] >= X){
      if ( (A[i] - X) % (X+Y) < Y ){
        changed = true;
      }else if (A[i] % (X+Y) < Y){

      }else{
        all_smaller_y = false;
      }
    }else if (A[i]>= Y){
      all_smaller_y = false;
    }
  }
  if (changed && all_smaller_y){
    cout << "First" << endl;
  }else{
    cout << "Second" << endl;
  }

  return 0;
}
