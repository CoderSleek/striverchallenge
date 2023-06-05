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

int profit(vec<int> &price){
    int n = price.size();
    int max = prize[n-1], profit = INT16_MIN;
    for(int i = n - 1; i >= 0; --i){
        if(price[i] > max) max = price[i];
        if(max - price[i] > profit){
            profit = max - price[i];
        }
    }

    return profit;
}

int main(int argv, char **argc){
    vec<int> prices{2,2,2,2};
    cout<<profit(prices);
    return 0;
}