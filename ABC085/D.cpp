#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <queue>

using namespace std;

int main()
{
        // 整数の入力
    long long N,H,i,maxNormalDamage,normalDamage,throwDamage,totalAttacks;
    cin >> N >> H;
    maxNormalDamage = -1;
    priority_queue<long long> ordredThrowDamages;
    for (i=0;i<N;i++){
        cin >> normalDamage >> throwDamage;
        if (normalDamage > maxNormalDamage){
            maxNormalDamage = normalDamage;
        }
        ordredThrowDamages.push(throwDamage);
    }

    totalAttacks = 0;
    while(H > 0 &&  !ordredThrowDamages.empty() && ordredThrowDamages.top() > maxNormalDamage){
        H -=  ordredThrowDamages.top();
        ordredThrowDamages.pop();
        totalAttacks++;
    }

    if (H > 0 ){
        totalAttacks += H/maxNormalDamage;
        if (H % maxNormalDamage != 0){
            totalAttacks++;
        }
    }
    cout << totalAttacks << endl;

    return 0;
}