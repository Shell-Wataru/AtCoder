#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>

using namespace std;

// 整数の入力
long long N,i,k,minValue,total,a,b;


long long minPath(long long now,long long before,set<long long>* path ,long long value ){
    int i,j;
    if (now == N){
        return value;
    }else{
        int minValue = N + 1;
        int removePath = -1;
        for (auto it = path[now].begin(); it != path[now].end(); ++it) {
            if (*it != before){
                int temp = minPath(*it,now,path,value + 1);
                if (temp < minValue) {
                    minValue = temp;
                    if (minValue/2 == value){
                        removePath = *it;
                    }
                }
            }
        }
        if (removePath != -1){
            path[now].erase(removePath);
            path[removePath].erase(now);
        }
        return minValue;
    }
}

long long FennecTileCount(long long now,long long before,set<long long>* path){
    int j;
    long long count = 1;
    for (auto it = path[now].begin(); it != path[now].end(); ++it) {
        if (*it != before){
            count += FennecTileCount(*it,now,path);
        }
    }
    return count;
}

int main()
{
    string s;
    cin >> N;
    set<long long>* path = new set<long long>[N+1];
    for (i=0;i< N - 1;i++){
        cin >> a >> b;
        path[a].insert(b);
        path[b].insert(a);
    }
    minPath(1,-1,path,0);
    if (FennecTileCount(1,-1,path) > N/2){
        cout << "Fennec" << endl;
    }else{
        cout << "Snuke" << endl;
    }
    return 0;
}