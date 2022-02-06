#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <list>
#include <stack>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 2;

struct Doubling
{
  const int LOG;
  vector< vector< int > > table;

  Doubling(int sz, int64_t lim_t) : LOG(64 - __builtin_clzll(lim_t))
  {
    table.assign(LOG, vector< int >(sz, -1));
  }

  void set_next(int k, int x)
  {
    table[0][k] = x;
  }

  void build()
  {
    for(int k = 0; k + 1 < LOG; k++) {
      for(int i = 0; i < table[k].size(); i++) {
        if(table[k][i] == -1) table[k + 1][i] = -1;
        else table[k + 1][i] = table[k][table[k][i]];
      }
    }
  }

  int query(int k, int64_t t)
  {
    for(int i = LOG - 1; i >= 0; i--) {
      if((t >> i) & 1) k = table[i][k];
    }
    return k;
  }
};


int main()
{
    // 整数の入力
    ll N,a;
    mp::cpp_int k;
    cin >> N >> a >> k;
    a--;
    Doubling doubling(N,numeric_limits<ll>::max());
    for(int i = 0;i < N;i++){
        ll b;
        cin >> b;
        b--;
        doubling.set_next(i,b);
    }
    doubling.build();
    vector<ll> visit_turn(N,-1);
    visit_turn[a] = 0;
    ll turn = 0;
    while(visit_turn[doubling.query(a,1)] == -1 && k > 0){
        turn++;
        k--;
        a = doubling.query(a,1);
        visit_turn[a] = turn;
    }
    if (k == 0){
        cout << a+1 << endl;
    }else{
        ll period = turn + 1 - visit_turn[doubling.query(a,1)];
        k = k % period;
        cout << doubling.query(a,(ll)k) +1<< endl;
    }
    return 0;
}