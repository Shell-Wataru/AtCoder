#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>

using namespace std;

void setMinPathLength(map<long long ,long long>* T,long long K ,long long length ,long long* minPaths){
    minPaths[K] = length;
    for(auto itr = T[K].begin(); itr != T[K].end(); ++itr) {
        if (minPaths[itr->first] == -1){
            setMinPathLength(T,itr->first ,length + itr->second , minPaths);
        }
    }
}

int main()
{
    // 整数の入力
    long long N,a,b,c,i,Q,K,x,y;
    map<long long ,long long> *T;
    long long * minPaths;
    cin >> N;
    T = new map<long long,long long>[N+1];
    minPaths = new long long[N+1];
    for (i= 1;i<N;i++){
        cin >> a;
        cin >> b;
        cin >> c;
        T[a][b] = c;
        T[b][a] = c;
    }

    for (i=1;i<=N;i++){
            minPaths[i] = -1;
    }

    cin >> Q;
    cin >> K;
    setMinPathLength(T,K,0,minPaths);

    for (i=0;i<Q;i++){
        cin >> x;
        cin >> y;
        cout << minPaths[x] + minPaths[y] << endl;
    }
    return 0;
}