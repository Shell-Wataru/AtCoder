//AGC035B
//木としてDFSで全探索する
int dfs(ll parent,ll node,map<ll,set<ll>> &G){
    // cout << parent << "-" << node << endl;
    vector<ll> children;

    while(!G[node].empty()){
        ll p = *G[node].begin();
        G[node].erase(p);
        G[p].erase(node);
        ll count = dfs(node,p,G);
        if (count != 0){
            children.push_back(p);
        }
        if (children.size() == 2){
            cout << node << " " << children[0] << endl;
            cout << node << " " << children[1] << endl;
            children.clear();
        }
    }

    if (children.size()  == 0){
        return 1;
    }else{
        cout << node << " " << children[0] << endl;
        cout << node << " " << parent << endl;
        return 0;
    }
}