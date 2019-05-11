#include<iostream>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
    // 整数の入力
    int N,D,Q,Query,i,j;
    cin >> N >> D;

    int* moves = new int[N+1];
    int* distances = new int[N+1];
    int* canNotReach = new int[N+1];
    // スペース区切りの整数の入力
    moves[0] = 0;
    distances[0] = D;
    for (i=1;i<=N;i++){
        cin >> moves[i];
        if (abs(moves[i] - distances[i-1]) < distances[i-1]){
            distances[i] = abs(moves[i] - distances[i-1]);
        }else{
            distances[i] = distances[i-1];
        }
    }

    canNotReach[N+1] = 1;
    for (i=N;i>=1;i--){
        if (canNotReach[i+1] <= moves[i]/2){
            canNotReach[i] = canNotReach[i+1];
        }else{
            canNotReach[i] = canNotReach[i+1] + moves[i];
        }
    }

    cin >> Q;
    for (i=0;i<Q;i++){
        cin >> Query;
        if (canNotReach[Query+1] <= distances[Query -1]){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}