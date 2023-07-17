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
#define for_dec(start, stop, var) for (int var = start; var > stop; --var)

bool searchmatrix(vector<vector<int>>& matrix, int target) {
    int lo = 0, n = matrix.size(), m = matrix[0].size();
    if(!n) return false;
    int hi = (n * m) - 1;
    
    while(lo <= hi) {
        int mid = (lo + (hi - lo) / 2);
        if(matrix[mid / m][mid % m] == target) {
            return true;
        }
        if(matrix[mid / m][mid % m] < target) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return false;
}

int main(int argv, char **argc){
    matrix<int> mat{{1,2,3},{4,5,6},{7,8,9}};
    searchmatrix(mat, 5);
    return 0;
}