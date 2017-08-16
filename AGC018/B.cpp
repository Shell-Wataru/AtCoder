#include<iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

int A[300][300] = {0};
set<int> removedSet;

int main()
{
    // 整数の入力
    long long N,M,i,j,temp,minmax;
    cin >> N >> M;
    for (i=0;i<N;i++){
        for (j = 0;j<M;j++){
            cin >> temp;
            A[i][j] = temp;
        }
    }

    map<int,int> counts;
    minmax = 301;
    for (j=0;j<M;j++){
        counts.clear();
        for (i=0;i<N;i++){
            int t = 0;
            while(removedSet.count(A[i][t]) != 0){
                t++;
            }
            counts[A[i][t]] += 1;
        }
        int max = 0;
        int key = 0;
        for(auto itr = counts.begin(); itr != counts.end(); ++itr) {
            if (itr->second > max){
                max = itr->second;
                key = itr->first;
            }
        }
        removedSet.insert(key);
        if (max < minmax){
            minmax = max;
        }
    }
    cout << minmax << endl;

    return 0;
}