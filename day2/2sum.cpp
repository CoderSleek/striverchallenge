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

vec<int> sum2(vec<int> &nums, int target){
    const int n = nums.size();
    unordered_map<int, int> count{{nums[0], 0}};

    for(int i = 1; i < n; ++i){
        int to_find = target - nums[i];
        if(count.find(to_find) != count.end()){
            return vector<int>{count[to_find], i};
        } else {
            count[nums[i]] = i;
        }
    }
    return vector<int>();
}

int main(int argv, char **argc){
    vec<int> nums{2,7,11,15};
    vec<int> ans = sum2(nums, 9);
    for(auto &i: ans)
        cout<<i<<" ";
    return 0;
}