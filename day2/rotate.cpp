// #include<bits/stdc++.h>
// using namespace std;

// using ll = long long;
// using dl = long double;
// using str = std::string;
// template<typename T>
// using vec = std::vector<T>;
// template<typename T>
// using matrix = std::vector<std::vector<T>>;
// template<typename T>
// using viter = typename vector<T>::iterator;
// #define for_inc(start, stop, var) for (int var = start; var < stop; ++var)
// #define for_dec(start, stop, var) for (int var = start; var > stop; --var)

// void rotate(vec<vec<int>> &mat, int sr, int sc, matrix<bool> &isrotated){
//     //base case
//     int n = mat.size(), m = mat[0].size();
//     if(sr == n/2 && n%2==1) return;
//     if(isrotated[n/2][m/2] && isrotated[n/2-1][m/2-1] && isrotated[n/2-1][m/2] && isrotated[n/2][m/2-1]) return;

//     int i = sr, j = sc, toswap = mat[sr][sc], temp;
//     //l->r
//     for(;j+1 < m && !isrotated[i][j+1]; j++){
//         temp = mat[i][j+1];
//         mat[i][j+1] = toswap;
//         toswap = temp;
//         isrotated[i][j+1] = true;
//     }

//     //u->d
//     for(;i+1 < n && !isrotated[i+1][j]; i++){
//         temp = mat[i+1][j];
//         mat[i+1][j] = toswap;
//         toswap = temp;
//         isrotated[i+1][j] = true;
//     }

//     //r->l
//     for(;j-1 >= 0 && !isrotated[i][j-1]; j--){
//         temp = mat[i][j-1];
//         mat[i][j-1] = toswap;
//         toswap = temp;
//         isrotated[i][j-1] = true;
//     }

//     // d->u
//     for(;i-1 >= 0 && !isrotated[i-1][j]; i--){
//         temp = mat[i-1][j];
//         mat[i-1][j] = toswap;
//         toswap = temp;
//         isrotated[i-1][j] = true;
//     }
//     rotate(mat, sr+1, sc+1, isrotated);
// }

// void print(vec<vec<int>> &arr){
//     for (auto &var : arr){
//         for(auto &i : var){
//             cout<<i<<" ";
//         } cout<<endl;
//     }
// }

// int main(int argv, char **argc){
//     int n = 5;
//     // vec<vec<int>> mat(n, vec<int>(n));
//     vec<vec<int>> mat{{5},{7}, {3},{2}};
//     matrix<bool> isrotated(4, vec<bool>(1, false));
//     int i = 1;
//     for (auto &var : mat){
//         for(auto &j : var){
//             j = i++;
//         }
//     }
//     rotate(mat, 0, 0, isrotated);
//     print(mat);
//     return 0;
// }

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


void rotate90(vector<vector<int>>& mat) {
    int n = mat.size();
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            if(i != j){
                swap(mat[i][j], mat[j][i]);
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n/2; ++j){
            swap(mat[i][j], mat[i][n-j-1]);
        }
    }
}

void rotateSpiral(matrix<int> &mat){
    int pass_num = 0, n = mat.size(), m = mat[0].size();
    
    while(pass_num < n/2 && pass_num < m/2){
        int i = pass_num, j = pass_num;
        int &start = mat[i][j];
        for(; j < m - pass_num; ++j){
            swap(start, mat[i][j]);
        }
        j-=1;
        i += 1;

        for(;i < n - pass_num; ++i){
            swap(start, mat[i][j]);
        }
        i -= 1;
        j -= 1;

        for(; j >= pass_num ; --j){
            swap(start, mat[i][j]);
        }
        j += 1;
        i -= 1;

        for (; i >= pass_num; --i) {
        swap(start, mat[i][j]);
        }
        ++pass_num;
    }
}

void print(vec<vec<int>> &mat){
    for(auto &i: mat){
        for(auto &j: i){
            cout<<j<<" ";
} cout<<endl;
}}

int main(int argv, char **argc){
    matrix<int> mat1(4, vec<int>(4));
    matrix<int> mat2(4, vec<int>(4));

    int m = 1;
    for(int i = 0; i < mat1.size(); ++i){
        for(int j = 0; j < mat1[0].size(); ++j){
            mat1[i][j] = mat2[i][j] = m++;
        }
    }
    print(mat1);
    cout<<endl;
    rotate90(mat1);
    rotateSpiral(mat2);
    print(mat1);
    cout<<endl;
    print(mat2);
    return 0;
}