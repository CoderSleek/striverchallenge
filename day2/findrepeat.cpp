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

int findrepeat(vec<int> &nums){
    int slow = nums[0], fast = nums[0];
    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while(slow != fast);

    fast = nums[0];
    while(slow != fast){
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    return nums[slow];
}

int main(int argv, char **argc){
    vec<int> nums{2,5,9,6,9,3,8,9,7,1};
    cout<<findrepeat(nums);
    return 0;
}