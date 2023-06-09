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
#define for_inc(start, stop, var) for (int var = start; var < stop; ++var)
#define for_dec(start, stop) for (int i = start; i > stop; --i)

pair<int, int> func(vec<int> &nums, int n){
    long rpt_minus_mis = accumulate(nums.begin(), nums.end(), 0) - (n * (n+1))/2;
    long sq = accumulate(nums.begin(), nums.end(), 0, 
    [](long total, long curr){
        return total + powl(curr, 2);
    });
    //OR
    // long sq=0;
    // for_each(nums.begin(), nums.end(), 
    // [&sq](int ele){
    //     sq += powl(ele, 2);
    // });

    long rptsq_minus_missq = sq - (n * (n+1) * (2*n+1))/6;
    long rpt_plus_mis = rptsq_minus_missq / rpt_minus_mis;
    long rep = (rpt_plus_mis + rpt_minus_mis) / 2;
    long mis = rpt_plus_mis - rep;

    return pair<int,int>{rep, mis};
}

pair<int, int> funcxor(vec<int> &nums, int n){
    int xr = 0;
    for(int i = 0; i < n; ++i){
        xr ^= nums[i];
        xr ^= (i+1);
    }

    int number = (xr & ~(xr-1)), zero = 0, one = 0;

    for(int i = 0; i < n; ++i){
        if((nums[i] & number) != 0){
            one ^= nums[i];
        } else {
            zero ^= nums[i];
        }
    }
    for(int i = 1; i <= n; ++i){
        if((i & number) != 0){
            one ^= i;
        } else {
            zero ^= i;
        }
    }
    int count = 0;
    for_inc(0, n, i){
        if(nums[i] == zero) ++count;
    }
    if(count == 2) return {zero, one};
    return {one, zero};
}

int main(int argv, char **argc){
    vec<int> nums{1,2,3,4,5,5};
    // func(nums, nums.size());
    auto &&a = funcxor(nums, nums.size());
    cout<<a.first<<" "<<a.second;
    return 0;
}