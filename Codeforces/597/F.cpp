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


map<ll,ll> compress(vector<ll> &data){
    set<ll> unique_data;
    map<ll, ll> zipped_data;

    for (auto a: data){
        unique_data.insert(a);
    }

   ll counter = 0;
    for (auto a: unique_data){
        zipped_data[a] = counter;
        counter++;
    }
    return zipped_data;
}

void print(vector<ll> &data){
    for (auto a: data){
        cout << "," << a;
    }
    cout << endl;
}

int main()
{
    ll N;
    vector<pair<ll,ll>> points;
    vector<ll> xs,ys;
    map<ll,ll> x_compressed,y_compressed;

    cin >> N;
    for(int i = 0;i<N;i++){
        ll x,y;
        cin >> x >> y;
        points.push_back(make_pair(y,x));
        xs.push_back(x);
        ys.push_back(y);
    }
    x_compressed = compress(xs);
    y_compressed = compress(ys);
    ll y_size = y_compressed.size();
    vector<ll> y_bit(y_compressed.size(),0);
    sort(points.begin(),points.end());

    ll counter = 0;
    set<ll> roots,current_roots;
    ll current_y = -1;
    for(auto p:points){
        cout << p.second << "," << p.first << endl;
        ll y_index = y_compressed[p.first];
        ll x_index = x_compressed[p.second];
        if(current_y != y_index){
            current_y = y_index;
            current_roots.clear();
        }

        current_roots.insert(x_index);
        if(roots.find(x_index) != roots.end() || y_index == 0){
            roots.insert(x_index);
            counter+= current_roots.size();
        }else{
            roots.insert(x_index);
            counter+= roots.size() + current_roots.size() - 1;
        }
        cout << "now" << counter << endl;
    }

    cout << counter << endl;
    return 0;
}