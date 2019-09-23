#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <queue>
using namespace std;
using ll =long long;

class v{
    public:
    set<ll> s;
    ll index = -1;
    ll c = -1;
};
int main()
{
    // 整数の入力
    ll N,A,B,C;
    vector<v> T;
    vector<pair<ll,ll>> es;
    priority_queue<ll,vector<ll>, greater<ll> > cs;
    queue<ll> waiting_vs;

    cin >> N;
    for(int i = 0;i <N;i++){
        v new_v;
        new_v.index = i;
        T.push_back(new_v);
    }

    for(int i = 0;i < N-1; i++){
        ll a,b;
        cin >> a >> b;
        es.push_back(make_pair(a-1,b-1));
        T[a-1].s.insert(b-1);
        T[b-1].s.insert(a-1);

    }

    for(int i = 0;i < N; i++){
        ll c;
        cin >> c;
        cs.push(c);
    }

    for(int i = 0;i< N;i++){
        if (T[i].s.size() == 1){
            T[i].c = cs.top();
            cs.pop();
            for(auto j:T[i].s){
                waiting_vs.push(j);
            }
        }
    };

    while(!waiting_vs.empty()){
        v& current_v = T[waiting_vs.front()];
        // cout << "w "<< waiting_vs.front() << endl;
        waiting_vs.pop();

        ll edges = 0;
        for(auto j:current_v.s){
            if (T[j].c == -1){
                edges++;
            }
        }

        if (edges != 1 && edges != 0){
            continue;
        }
        current_v.c = cs.top();
        cs.pop();

        for(auto j:current_v.s){
            if (T[j].c == -1){
                waiting_vs.push(j);
            }
        }
    }

    ll M =0;

    for(auto e :es){
        M+= min(T[e.first].c,T[e.second].c);
    }

    cout << M << endl;
    for(int i = 0;i<N;i++){
        if (i == 0){
            cout << T[i].c;
        }else{
            cout << " " <<T[i].c;
        }
    }
    cout << endl;


    return 0;
}