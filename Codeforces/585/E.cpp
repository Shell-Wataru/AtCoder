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

class BIT
{
public:
    vector<ll> data;
    BIT(long long n) : data(n) {}
    void add(int index, long long v)
    {
        int N = data.size();
        for (int i = index; i < N; i |= i + 1)
        {
            data[i] += v;
        }
    }

    long long sum(int index)
    {
        long long retValue = 0;
        int i;
        for (i = index; i >= 0; i = (i & (i + 1)) - 1)
        {
            retValue += data[i];
        }
        return retValue;
    }

    void show(){
        for (auto v:data){
            cout << v << endl;
        }
    }
};

struct color_data{
    ll color;
    vector<ll> indexes;
    ll score = 0;
    void push(ll index){
        score += index - indexes.size();
        indexes.push_back(index);
    };

    ll change_cost(color_data other){
        ll total = 0;
        for(auto i:indexes){
            auto lower_bound_index = lower_bound(other.indexes.begin(),other.indexes.end(),i);
            ll lowers = lower_bound_index - other.indexes.begin();
            ll highers = other.indexes.size() - lowers;
            total += lowers - highers;
        }
        return total;
    }
};

int main()
{
    ll N;
    vector<ll> colors;
    map<ll,color_data> color_data_map;
    map<pair<ll,ll>,ll> color_change_costs;
    vector<color_data> color_data_array;
    map<ll,ll> asshuku;

    cin >> N ;
    BIT bit(N);
    for (int i = 0; i < N; i++)
    {
        ll c;
        cin >> c;
        colors.push_back(c);
    }
    // if (N == 284){
    //     for (auto c: colors){
    //         cout << c;
    //     }
    //     cout << endl;
    //     return 0;
    // }
    for(ll i = 0;i < N;i++){
        if (color_data_map.find(colors[i]) == color_data_map.end()){
            color_data d;
            d.color = colors[i];
            color_data_map[colors[i]] = d;
        }
        color_data_map[colors[i]].push(i);
    }

    for (auto p:color_data_map){
        color_data_array.push_back(p.second);
    }

    for(int i = 0;i<color_data_array.size();i++){
        for(int j = i+1;j<color_data_array.size();j++){
            color_data &current = color_data_array[i];
            color_data &other = color_data_array[j];
            color_change_costs[make_pair(current.color,other.color)] = current.change_cost(other);
            color_change_costs[make_pair(other.color,current.color)] = - color_change_costs[make_pair(current.color,other.color)];
        }
    }

    for (int i = 0;i< color_data_array.size();i++){
        for(int j = 0;j < color_data_array.size();j++){
            ll min_cost = 0;
            ll min_index = j;
            ll cost = 0;
            color_data &current = color_data_array[j];
            for(int k = j+1;k <color_data_array.size();k++){
                color_data &other = color_data_array[k];
                cost += color_change_costs[make_pair(current.color,other.color)];
                if (min_index < min)
            }
            swap(color_data_array[i],color_data_array[min_index]);
        }
    }

    for(int i = 0;i<color_data_array.size();i++){
        for(int j = i+1;j<color_data_array.size();j++){
            color_data &current = color_data_array[i];
            color_data &other = color_data_array[j];
            cout << current.color << " " << other.color << ":" << current.change_cost(other) << endl;
        }
    }
    // cout << "---" << endl;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        // cout << i << ":" << i - bit.sum(asshuku[colors[i]]) << endl;
        ans += i - bit.sum(asshuku[colors[i]]);
        bit.add(asshuku[colors[i]], 1);
    }
    cout << ans << endl;

    return 0;
}