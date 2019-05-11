#include<iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <math.h>
using namespace std;

int A[300][300] = {0};
set<int> removedSet;

int main()
{
    // 整数の入力
    long long R,G,B,N;
    long long counter = 0;
    cin >> R >> G >> B >> N;
    for (int i = 0;N - R * i >=0;i++){
        // cout << i << endl;
        for (int j = 0;N - R * i - G * j >= 0;j++){
            // cout << j << endl;
            if((N - R * i - G * j) % B == 0 ){
                counter++;
            }
        }
    }
    cout << counter << endl;
    return 0;
}