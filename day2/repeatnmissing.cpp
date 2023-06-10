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

// mark all non repeatingas -ve
pair<int, int> funcmark(vec<int> &nums, int n){
    int m, d;
    for_inc(0, n, i){
        int x = abs(nums[i])-1;
        if(nums[x] < 0){
            d = x+1;
        } else {
            nums[x] *= -1;
        }
    }

    for_inc(0, n, i){
        if(nums[i] > 0){
            m = i+1;
        } else {
            nums[i] = abs(nums[i]);
        }
    }
    return {m, d};
}

// math trick
pair<int, int> func(vec<int> &nums, int n){
    long long int s = 0, sn = 0, sq = 0, sqn = 0;
    for_inc(0, n, i){
        s += nums[i];
        sq += (long long int)nums[i] * (long long int)nums[i];
    }

    long long int m = (long long int)(n);
    sn = (m * (m + 1)) / 2;
    sqn = (m * (m + 1) * (2 * m + 1)) / 6;
    
    long long int m_minus_d = sn - s;
    long long int msq_minus_dsq = sqn - sq;
    long long int m_plus_d = msq_minus_dsq / m_minus_d;

    int mis = (m_minus_d + m_plus_d) / 2;
    int dup = (m_plus_d - mis);

    return pair<int,int>{mis, dup};
}

// xor
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
    auto &&a = func(nums, nums.size());
    // auto &&a = funcxor(nums, nums.size());
    // auto &&a = funcmark(nums, nums.size());
    cout<<a.first<<" "<<a.second;
    return 0;
}