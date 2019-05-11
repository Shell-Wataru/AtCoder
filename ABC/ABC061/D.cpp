#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

int main()
{
    // 整数の入力
    long long N,M,i,j,a,b,c;
    queue<int> nextVerticals;
    cin >> N >> M;
    long long* maxPoints = new long long[N+1];
    long long infinity = 9223372036854775807;
    for (i=0;i < N+1;i++){
        maxPoints[i] = 0;
    }

    deque<int>* edgeTo = new deque<int>[N+1];
    deque<int>* edgePoints = new deque<int>[N+1];
    for (i=0;i < M;i++){
        cin >> a >> b >> c;
        edgeTo[a].push_back(b);
        edgePoints[a].push_back(c);
    }

nextVerticals.push(1);
    while (!nextVerticals.empty()){
        int v = nextVerticals.front();
        for (i=0;i<edgeTo[v].size();i++){
            if (maxPoints[v] == infinity){
                maxPoints[edgeTo[v][i]] = infinity;
                nextVerticals.push(edgeTo[v][i]);
            }else{
                if (edgePoints[v][i] + maxPoints[v] > maxPoints[edgeTo[v][i]]){
                    maxPoints[edgeTo[v][i]] = edgePoints[v][i] + maxPoints[v];
                    nextVerticals.push(edgeTo[v][i]);
                }
            }
        }
        nextVerticals.pop();
    }
    if (maxPoints[N] == infinity){
        cout << "inf" << endl;
    }else{
        cout << maxPoints[N] << endl;        
    }

    return 0;
}