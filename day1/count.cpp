#include<bits/stdc++.h>
using std::cout;
using std::vector;
using std::swap;
template<typename T>
using vec = std::vector<T>;
#define for_inc(start, stop) for (int i = start; i < stop; ++i)

void count012(vec<int> &arr){
    int low = 0, mid = 0, high = arr.size()-1;

    for(;mid <= high;){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++; mid++;
        }
        else if(arr[mid] == 2){
            swap(arr[mid], arr[high]);
            --high;
        }
        else ++mid;
    }
}

int main(int argv, char **argc){
    vec<int> arr{0,0,2,1,1,0,2,2,1,1,0};
    count012(arr);
    for(auto &i: arr){
        cout<<i;
    }
    return 0;
}