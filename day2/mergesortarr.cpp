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

void mergesortedarr(vec<int> &arr1, vec<int> &arr2, int n, int m){
    int right = n -1, left = 0;

    while(left < n && right >= 0){
        if(arr1[right] > arr2[left]){
            swap(arr1[right], arr2[left]);
            --right;
        }
        ++left;
    }

    for(int i = 0; i < m; ++i){
        arr1[n+i] = arr2[i];
    }

    sort(arr1.begin(), arr1.begin() + n);
    sort(arr1.begin() + n, arr1.end());
}


void print(vec<int> &arr){
    for(auto &i: arr){
        cout<<i<<" ";
}}
int main(int argv, char **argc){
    vec<int> a{1,2,3,0,0,0}, b{2,5,6};
    mergesortedarr(a, b, 3, 3);
    print(a);
    return 0;
}