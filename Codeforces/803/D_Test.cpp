#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <numeric>

using namespace std;
using ll = long long;

struct UnionFind {
  vector< int > data;

  UnionFind(int sz) {
    data.assign(sz, -1);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  bool same(int x, int y) {
    x = find(x), y = find(y);
    return x == y;
  }
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k) {
    return (-data[find(k)]);
  }
};

int main()
{
    vector<ll> a= {4,2,5,1,3};
    ll n = a.size();
    cout << 1 << endl;
    cout << n << endl;
    while(true){
        char type;
        cin >> type;
        if (type == '!'){
            ll l;
            cin >> l;
            cerr << l << endl;
            break;
        }else{
            ll l,r;
            cin >> l >> r;
            l--;
            // cerr << l << "~" << r << endl;
            vector<ll> b(a.begin()+l,a.begin()+r);
            sort(b.begin(),b.end());
            for(int i = 0;i < b.size();i++){
                if (i!= 0){
                    cout << " ";
                }
                cout << b[i];
            }
            cout << endl;
        }
    }
    return 0;
}
