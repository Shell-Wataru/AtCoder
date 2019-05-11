#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;


int main()
{
    // 整数の入力
    long long N,p_i,i,j;
    vector<long long> P;
    vector<long long> Q;
    set<long long> Used;
    map<long long,long long> shrink;
    priority_queue<int> que;

    cin >> N;

    for (i= 0; i< N ; i++) {
        cin >> p_i;
        P.push_back(p_i);
        shrink[P_i] = i;
        que.push_back(P_i)
    }

    while (Used.size() != N){
        long long minTop = N+1;
        long long minTopIndex = -1;
        long long usedCount = 0;
        for (i= 0;i<N; i++){
            if (Used.count(P[i]) != 0){
                usedCount++;
            }else if ((i - usedCount)%2 == 0 &&  P[i] < minTop && Used.count(P[i]) == 0){
                minTop = P[i];
                minTopIndex = i;
            }
        }

        long long minAfterMinTop = N+ 1;
        long long minAfterMinTopIndex = - 1;
        usedCount = (minTopIndex + 1)%2;
        for (i= minTopIndex + 1; i< N; i++){
            if (Used.count(P[i]) != 0){
                break;
            }else if ((i - usedCount)%2 == 0 && P[i] < minAfterMinTop && Used.count(P[i]) == 0){
                minAfterMinTop = P[i];
                minAfterMinTopIndex = i;
            }
        }

        Q.push_back(minTop);
        Q.push_back(minAfterMinTop);
        Used.insert(minTop);
        Used.insert(minAfterMinTop);
    }

    cout << Q[0];
    for (i = 1;i< N;i++){
        cout << " " << Q[i];
    }
    cout << endl;
    return 0;
}