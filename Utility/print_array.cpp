#include <map>
#include <set>
#include <vector>
#include <iostream>

using ll = long long;
using namespace std;

void print(vector<ll> &data){
    for (auto a: data){
        cout << "," << a;
    }
    cout << endl;
}

int main(){
    vector<ll> data {1LL,5LL,7LL,10LL};
    print(data);
    return 0;
}

