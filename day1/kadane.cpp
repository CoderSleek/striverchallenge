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

void maxsum(vec<int> arr){
    ll max = LONG_LONG_MIN, sum = 0;
    int ansStart = -1, ansEnd = -1, start = 0;

    for(int i = 0; i < arr.size(); ++i){
        sum += arr[i];
        sum = sum > 0 ? sum : 0;
        if(sum == 0) start = i;
        if(sum > max){
            max = sum;
            ansStart = start;
            ansEnd = i;
        }
    }

    cout<<(max > 0 ? max : 0);
    cout<<std::endl<<ansStart+1<<" "<<std::endl<<ansEnd;
}

int main(int argv, char **argc){
    vec<int> arr{-2, -3, 4, -1, -2, 1, 5, -3};
    maxsum(arr);
    return 0;
}