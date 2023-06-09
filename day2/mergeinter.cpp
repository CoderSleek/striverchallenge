#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using dl = long double;
using str = std::string;

template<typename T>
using vec = std::vector<T>;
template<typename T>
using matrix = std::vector<std::vector<T>>;
template<typename T>
using viter = typename std::vector<T>::iterator;
#define for_inc(start, stop) for (int i = start; i < stop; ++i)
#define for_dec(start, stop) for (int i = start; i > stop; --i)

matrix<int> mergeinter(matrix<int> &intervals){
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> arr;
    for(auto &&i : intervals){
        bool shouldpush = true;
        if(!arr.empty()){
            int &first = arr.back()[0];
            int &second = arr.back()[1];
            if(first == i[0] && second == i[1]) continue;
            if(first <= i[0] && i[0] <= second){
                first = min(first, i[0]);
                second = max(second, i[1]);
                shouldpush = false;
            }
        }
        if(shouldpush){
            arr.push_back(vector<int>{i[0], i[1]});
        }
    }

    return arr;
}

void print(vec<vec<int>> &mat){
    for(auto &i: mat){
        for(auto &j: i){
            cout<<j<<" ";
} cout<<endl;
}}

int main(int argv, char **argc){
    matrix<int> mat{{1,3},{2,6},{8,10},{15,18}}, ans;
    ans= mergeinter(mat);
    print(ans);
    return 0;
}