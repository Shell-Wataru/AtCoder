#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <ctime>

using namespace std;

int main()
{

    long long N,M;
    string S;
    set<int> contains;
    fill(contains,contains+10,0);

    cin >> N >> M;
    for (int i = 0;i< N;i++){
        cin >> S;
        for (int j = 0; j< M;j++){
            contains[S[j] - '0'] = S[j] - '0';
        }
    }

    if (max(contains) == 0){

    }


    return 0;
}