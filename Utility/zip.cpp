#include <map>
#include <set>
#include <vector>
#include <iostream>

using ll = long long;
using namespace std;

map<ll,ll> compress(vector<ll> &data){
    set<ll> unique_data;
    map<ll, ll> zipped_data;

    for (auto a: data){
        unique_data.insert(a);
    }

   ll counter = 0;
    for (auto a: unique_data){
        zipped_data[a] = counter;
        counter++;
    }
    return zipped_data;
}

int main(){
    vector<ll> data {1LL,5LL,7LL,10LL};
    for(auto a: compress(data)){
        cout << a.first << "->" << a.second << endl;
    }
    return 0;
}

