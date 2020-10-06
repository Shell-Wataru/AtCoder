#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
ll BASE_NUM = 998244353;

int main()
{
  ll n;
  cin >> n;
  ll whites = 0;
  ll blacks = 0;
  for(int i = 0;i< n;i++){
    int a;
    scanf("%d", &a);
    if (i % 2 == 0){
      whites += a / 2 + a % 2;
      blacks += a / 2;
    }else{
      whites += a / 2;
      blacks += a / 2 + a % 2;
    }
  }
  cout << min(whites,blacks) << endl;
  return 0;
}