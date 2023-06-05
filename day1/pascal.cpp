#include<bits/stdc++.h>
using std::cout;
using std::vector;

using ll = long long;
using dl = long double;
template<typename T>
using vec = std::vector<T>;
template<typename T>
using viter = typename vector<T>::iterator;
#define for_inc(start, stop) for (int i = start; i < stop; ++i)

vec<ll> generateRow(int rowsize){
    ll ans = 1;
    vec<ll> anslist = {};
    anslist.push_back(1);

    for_inc(1, rowsize){
        ans = (ans * (rowsize - i)) / i;
        anslist.push_back(ans);
    }
    return anslist;
}

vec<vec<ll>> pascal(int row){
    vec<vec<ll>> ans;
    for(int i = 1; i <= row; ++i){
        ans.push_back(generateRow(i));
    }

    for_inc(0, ans.size()){
        for(int j = 0; j < ans[i].size(); ++j){
            cout<<ans[i][j]<<" ";
        }
    }
    return ans;
}

int main(int argv, char **argc){
    pascal(7);
    return 0;
}