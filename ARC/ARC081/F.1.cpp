#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <queue>
using namespace std;

// dinic
class max_flow {
    struct edge { int to, cap, rev; };
    static const int INT_MAX = 2147483647;
    int V;
    vector<vector<edge>> G;
    vector<int> level;

public:
    max_flow(int V) : V(V) { G.assign(V,vector<edge>()); }

    void add_edge(int from, int to, int cap) {
        G[from].push_back((edge) {to, cap, (int) G[to].size()});
        G[to].push_back((edge) {from, 0, (int) G[from].size()-1});
    }

    void bfs(int s) {
        level.assign(V,-1);
        queue<int> q;
        level[s] = 0; q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for(auto &e: G[v]){
                if (e.cap > 0 and level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    int dfs(int v, int t, int f) {
        if (v == t) return f;
        for (int i = 0; i < (int) G[v].size();i++) {
            edge& e = G[v][i];
            if (e.cap > 0 and level[v] < level[e.to]) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int run(int s, int t) {
        int ret = 0, f;
        while (bfs(s), level[t] >= 0) {
            while ((f = dfs(s, t, INT_MAX)) > 0) ret += f;
        }
        return ret;
    }
};


int main()
{
    // 整数の入力
    long long N,a_i,a_i_1,i;
    a_i_1 = -1;
    vector<long long>B;
    vector<long long> odds;
    vector<long long> evens;
    set<long long>primes;
    cin >> N;
    cin >> a_i;
    B.push_back(a_i);
    a_i_1 = a_i;

    for (i= 1; i< N ; i++) {
        cin >> a_i;
        if (a_i != a_i_1 + 1){
            B.push_back(a_i_1 + 1);
            B.push_back(a_i);
        }
        a_i_1 = a_i;
    }

    B.push_back(a_i_1 + 1);

    for(i=2;i<3163;i++){
        if(all_of(primes.begin(),primes.end(),[i](long long p) {return i % p != 0;})){
            primes.insert(i);
        }
    }

    for (i=0;i<B.size();i++){
        if (B[i] %2 == 0){
            evens.push_back(B[i]);
        }else{
            odds.push_back(B[i]);
        }
    }

    max_flow flow(B.size()+2);
    for(int i=0;i<odds.size();i++){
        flow.add_edge(0,i+1,1);
    }
    for(int i=0;i<evens.size();i++){
        flow.add_edge(odds.size()+i+1,B.size()+1,1);
    }

    for(int i=0;i<odds.size();i++){
        for(int j = 0;j<evens.size();j++){
            if(abs(odds[i] - evens[j]) > 2 &&
                all_of(primes.begin(),primes.end(), [&](long long p){return (abs(odds[i] - evens[j])) == p || (abs(odds[i] - evens[j])) % p != 0;})){
                flow.add_edge(i+1,odds.size()+j+1,1);
            }
        }
    }
    int K = flow.run(0,B.size()+1);
    cout << K + ((odds.size() - K)/2 + (evens.size() - K)/2) * 2 + ((odds.size() - K)%2)* 3 << endl;
    return 0;
}