#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <queue>

using namespace std;
long long N,M,from,to,root;
map<long long ,vector<long long> > G;
map<long long ,vector<long long> > reverseG;

long long* parents;
long long* depths;

struct node{
    long long depth;
    long long index;
    long long parent;
};

auto c = [](node p1,node p2) {
        return p1.depth < p2.depth;
        };

priority_queue<node,vector<node>,decltype(c)> q1(c);

void wfs(long long start){
    q1.push({0,start,0});
    while(!q1.empty()){
        node n = q1.top();
        q1.pop();
        if (depths[n.index] < n.depth){
            depths[n.index] = n.depth;
            parents[n.index] = n.parent;

            for (int i = 0; i< G[n.index].size();i++){
                long long next = G[n.index][i];
                bool real_edge = true;
                for(int j = 0;j < reverseG[next].size();j++){
                    long long reverse_node = reverseG[next][j];
                    if (reverse_node != i && depths[reverse_node] == -1){
                        real_edge = false;
                    }
                }
                if (real_edge){
                    q1.push({n.depth+1,next,n.index});
                }
            }
        }
    }
}


int main()
{
    // 整数の入力
    cin >> N >> M;
    parents = new long long[N+1];
    depths = new long long[N+1];
    for (int i = 1; i<= N ; i++){
        parents[i] = 0;
        depths[i] = -1;
    }
    parents = new long long[N+1];
    for (int i= 1;i<= N - 1 + M;i++){
        cin >> from >> to;
        G[from].push_back(to);
        reverseG[to].push_back(from);
        parents[to] = -1;
    }

    for (int i = 1; i<= N ; i++){
        if (parents[i] == 0){
            root = i;
        }
    }

    wfs(root);
    for (int i = 1; i<= N ; i++){
        // cout << depths[i] << " ";
        cout << parents[i] << endl;
    }

    return 0;
}