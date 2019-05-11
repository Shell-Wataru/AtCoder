#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
using namespace std;
using ll = long long;

struct person {
    ll x,y;
    char d;
};

pair<ll,ll> find_point(ll P,ll Q, vector<person> people){
    ll *w_count = new ll[Q];
    ll *e_count = new ll[Q];
    ll *n_count = new ll[Q];
    ll *s_count = new ll[Q];
    ll *x_sum = new ll[Q];
    ll *y_sum = new ll[Q];

    fill(w_count,w_count+Q,0);
    fill(e_count,e_count+Q,0);
    fill(n_count,n_count+Q,0);
    fill(s_count,s_count+Q,0);
    fill(x_sum,x_sum+Q,0);
    fill(y_sum,y_sum+Q,0);


    for(int i = 0;i < P; i++){
        person p = people[i];
        if (p.d == 'W'){
            w_count[p.x-1] += 1;
        }else if (p.d == 'E'){
            e_count[p.x+1] += 1;
        }else if (p.d == 'N'){
            n_count[p.y+1] += 1;
        }else if (p.d == 'S'){
            s_count[p.y-1] += 1;
        }
    }

    ll e_total = 0;
    for (int i = 0;i < Q;i++){
        e_total += e_count[i];
        x_sum[i] += e_total;
    }

    ll w_total = 0;
    for (int i = Q - 1;i >= 0;i--){
        w_total += w_count[i];
        x_sum[i] += w_total;
    }

    ll n_total = 0;
    for (int i = 0;i < Q;i++){
        n_total += n_count[i];
        y_sum[i] += n_total;
    }

    ll s_total = 0;
    for (int i = Q - 1;i >= 0;i--){
        s_total += s_count[i];
        y_sum[i] += s_total;
    }

    // for (int i = 0;i < Q;i++){
    //     cout << x_sum[i];
    // }
    // cout << endl;

    // for (int i = 0;i < Q;i++){
    //     cout << y_sum[i];
    // }
    // cout << endl;

    ll max_x = -1;
    ll max_y= -1;
    ll max_x_index = -1;
    ll max_y_index = -1;

    for (int i = 0;i < Q;i++){
        if (x_sum[i] > max_x ){
            max_x_index = i;
            max_x = x_sum[i];
        }
    }

    for (int i = 0;i < Q;i++){
        if (y_sum[i] > max_y ){
            max_y_index = i;
            max_y = y_sum[i];
        }
    }

    return make_pair(max_x_index,max_y_index);
}

int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        ll P,Q;
        cin >> P >> Q;
        vector<person> people;
        for (int j = 0; j < P; j++)
        {
            person p;
            cin >> p.x >> p.y >> p.d;
            people.push_back(p);
        };

        pair<ll,ll> point = find_point(P,Q+1,people);
        cout << "Case #" << i << ": " << point.first << " " << point.second << endl;
    }

    return 0;
}