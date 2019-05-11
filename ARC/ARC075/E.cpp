#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
using namespace std;

void addBIT(long long* BIT,int N,int index, long long v){
    int i;
    for(i = index;i < N;i+= i&-i) BIT[i] += v;
}

long long sumBIT(long long* BIT,int index){
    long long retValue = 0;
    int i;
    for(i = index;i > 0;i-= i& -i) retValue += BIT[i];
    return retValue;
}

int main()
{
    // 整数の入力
    long long i,j,N,K,temp,count,total;
    count = 0;
    total = 0;
    vector<long long> b;
    map<long long,long long> dic;
    cin >> N >> K;
    long long* c = new long long[N+2];
    for (i=0;i<N+2;i++){
        c[i] = 0;
    }
    b.push_back(0);
    for (i=1;i<N+1;i++){
        cin >> temp;
        total += temp;
        b.push_back(total - K * i);
    }

    vector<long long> sorted_b(b);
    sort(sorted_b.begin(),sorted_b.end());

    temp = sorted_b[0] - 1;
    j = 0;
    for (i=0;i<=N;i++){
        if (temp != sorted_b[i]){
            temp = sorted_b[i];
            dic.insert(make_pair(sorted_b[i],j));
            j++;
        }
    }

    count = 0;
    for (i=0;i<=N;i++){
        count += sumBIT(c,dic.at(b[i])+1);
        addBIT(c,N+2,dic.at(b[i])+1, 1);
    }
    cout << count << endl;

    return 0;
}