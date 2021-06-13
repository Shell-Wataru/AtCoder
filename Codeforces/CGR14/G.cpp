 v#include <iostream>
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

int solve()
{

    ll N, M, a , b;
    cin >> N >> M >> a >> b;
    Dinic<ll> dinic(N+M+2);
    for(int i  = 1;i <= N;i++){
        dinic.add_edge(0,i,a);
    }
    for(int i  = 1;i <= M;i++){
        dinic.add_edge(N + i, N + M + 1,b);
    }
    for(int i = 1; i <= N;i++){
        for(int j = 1;j <= M;j++){
            dinic.add_edge(i,N+j,1);
        }
    }
    ll max_flow = dinic.max_flow(0,N+M+1);
    if (max_flow == N * a && N * a == M * b){
        cout << "YES" << endl;
        for(int i = 1; i <= N;i++){
            vector<char> row(M);
            // cout << dinic.graph[i].size() << endl;
            for(auto e:dinic.graph[i]){
                if (!e.isrev){
                    ll j = e.to - N - 1;
                    // cout << "j"<<j << endl;
                    if(e.cap == 0){
                        row[j] = '1';
                    }else{
                        row[j] = '0';
                    }
                }
            }
            for(auto c:row){
                cout << c;
            }
            cout << endl;
        }
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
int main()
{
    int t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}