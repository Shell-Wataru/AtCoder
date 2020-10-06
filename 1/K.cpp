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

ll BASE_NUM = 1000000007;

struct list_item {
    ll number,after,before;
};

struct list {
    ll front= -1;
    ll back = -1;;
};
int main()
{
    // 整数の入力
    ll N,Q;
    cin >> N >> Q;
    vector<list> list(N);
    vector<list_item> list_items(N);
    for(int i = 0;i< N;i++){
        list_items[i] = {i,-1,-1};
        list[i].front = i;
        list[i].back = i;
        // cout << list[i].back << endl;
    }
    for(int i = 0;i< Q;i++){
        ll f;
        ll x;
        ll t;
        cin >> f >> t >> x;
        f--;
        t--;
        x--;
        ll current_list_t_back = list[t].back;
        ll current_list_f_back = list[f].back;
        ll current_list_item_x_before = list_items[x].before;

        if (list[t].back != -1){
            list_items[list[t].back].after = x;
        }

        if (list_items[x].before != -1){
            list_items[list_items[x].before].after = -1;
        }
        list_items[x].before = current_list_t_back;
        list[f].back = current_list_item_x_before;
        list[t].back = current_list_f_back;
    }
    // for(int i = 0;i < N;i++){
    //     cout << list_items[i].number << ":" << list_items[i].before << endl;
    // }
    // for(int i = 0;i < N;i++){
    //     cout << i << ":" << list[i].back << endl;
    // }
    vector<ll> ans(N);
    for(int i = 0;i < N;i++){
        ll index = list[i].back;
        // cout << index << endl;
        while(index != -1){
            // cout << index << endl;
            ans[index] = i;
            index = list_items[index].before;
        }
    }
    for(int i = 0;i < N;i++){
        cout << ans[i] + 1 << endl;
    }
   return 0;
}