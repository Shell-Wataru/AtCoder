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

int main()
{
    // 整数の入力
    long long N,M;
    vector<pair<ll,ll>> ordered;
    vector<pair<ll,ll>> unordered;
    cin >> N >> M;
    ll *order_data =  new ll[N];
    fill(order_data,order_data+N,0);
    for(int i = 0;i< M;i++){
        ll t,r,l;
        cin >> t >> l >> r;
        if (t == 1){
            ordered.push_back(make_pair(l,r));
        }else{
            unordered.push_back(make_pair(l,r));
        }
    }

    sort(ordered.begin(),ordered.end());
    sort(unordered.begin(),unordered.end());

    ll last_order_data = -1;
    for(auto p: ordered){
        for(int i = max(last_order_data,p.first-1);i < p.second - 1;i++){
            order_data[i] = 1;
        }
        last_order_data = max(last_order_data,p.second - 2);
    }
    // for (int i = 0;i < N -1;i++){
    //     if(i == 0){
    //         cout << order_data[i];
    //     }else{
    //         cout << " " <<order_data[i];
    //     }
    // }
    // cout << endl;


    set<ll> unorderable;
    for (int i = 0;i < N -1;i++){
        if(order_data[i] == 0){
            unorderable.insert(i);
        }
    }

    bool creatable = true;
    for(auto p: unordered){
        bool p_creatable = false;
        for(auto u:unorderable){
            if (p.first - 1 <= u && u < p.second - 1){
                p_creatable = true;
            }
        }
        if (!p_creatable){
            creatable = false;
        }
    }

    if (!creatable){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        vector<ll> outputs;
        ll min_val = 1;
        for (int i = 0;i < N;i++){
            if (i == 0){
                outputs.push_back(1);
            }else{
                if(order_data[i-1] == 1){
                    outputs.push_back(outputs[i-1] + 1);
                }else{
                    outputs.push_back(outputs[i-1] - 1);
                    min_val = min(min_val,outputs[i]);
                }
            }
        }

        for (int i = 0;i < N;i++){
            if(i == 0){
                cout << outputs[i] -  min_val + 1;
            }else{
                cout << " " <<outputs[i]  -  min_val + 1;
            }
        }
        cout << endl;

    }
    return 0;
}