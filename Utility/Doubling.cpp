// https://ei1333.github.io/luzhiled/snippets/graph/lowlink.html
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
using ll = long long;

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
      if (k == -1){
        return -1;
      }
    }
    return k;
  }
};

int main(){
    Doubling d(5,5);
    d.set_next(0,1);
    d.set_next(1,2);
    d.set_next(2,3);
    d.set_next(3,4);
    d.build();
    cout << d.query(0,0) << endl;
    cout << d.query(0,1) << endl;
    cout << d.query(0,2) << endl;
    cout << d.query(0,3) << endl;
    cout << d.query(0,4) << endl;
    cout << d.query(0,5) << endl;
    return 0;
}