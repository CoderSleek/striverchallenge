// my approach
/*#include<bits/stdc++.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

template<typename T>
using vec = std::vector<T>;

#define for_inc(i, m) for (int index = i; index < m; ++index)

void makezero(std::vector<std::vector<int>> &matrix, int i, int j){
    for(int n = 0; n < matrix[0].size(); ++n){
        matrix[i][n] = 0;
    }

    for(int m = 0; m < matrix.size(); ++m){
        matrix[m][j] = 0;
    }
};

vec<vec<int>> flipToZero(std::vector<std::vector<int>> &matrix){
    vec<vec<int>> zeromatrix(matrix.size(), vec<int> (matrix[0].size(), -1));

    for(int i = 0; i < matrix.size(); ++i){
        for(int j = 0; j < matrix[i].size(); ++j){
            if(matrix[i][j] == 0){
                makezero(zeromatrix, i, j);
            }
            else if(zeromatrix[i][j] != 0){
                zeromatrix[i][j] = matrix[i][j];
            }
        }
    }
    matrix = zeromatrix;
    return matrix;
}

void print(std::vector<std::vector<int>> &matrix){
    for(auto &i : matrix){
        for(auto &j : i){
            cout<<j<<'\t';
        }
        cout<<endl;
    }
}

int main(){
    std::vector<std::vector<int>> matrix{{1,2,3,4,5},{6,7,0,8,9},{10,11,12,13,14},{8,7,6,5,4}};

    vec<vec<int>> result = flipToZero(matrix);
    print(result);
    return 0;
} */

// optimal

#include<bits/stdc++.h>

using namespace std;

template<typename T>
using vec = std::vector<T>;

#define for_inc(i, m) for (int index = i; index < m; ++index)

vec<vec<int>> flipToZero(std::vector<std::vector<int>> &matrix){
    bool col0 = true;
    int r = matrix.size(), c = matrix[0].size();

    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            if (matrix[i][j] == 0 && j == 0){
                col0 = false;
                matrix[i][0] = 0;
            }
            else if(matrix[i][j] == 0){
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for(int i = r - 1; i >= 1; --i){
        for(int j = c - 1; j >= 1; --j){
            if (matrix[0][j] == 0 || matrix[i][0] == 0){
                matrix[i][j] = 0;
            }
        }
    }

    if(matrix[0][0] == 0){
        for(int j = 0; j < c; ++j) matrix[0][j] = 0;
    }

    if(!col0){
        for(int i = 0; i < r; ++i) matrix[i][0] = 0;
    }
    return matrix;
}

void print(std::vector<std::vector<int>> &matrix){
    for(auto &i : matrix){
        for(auto &j : i){
            cout<<j<<'\t';
        }
        cout<<endl;
    }
}

int main(){
    // std::vector<std::vector<int>> matrix{{1,2,3,4,5},{6,7,0,8,9},{10,11,12,13,14},{8,7,6,5,4}};
    std::vector<std::vector<int>> matrix{{1,2,3,4},{5,0,7,8},{0,10,11,12},{13,14,15,0}};
    
    vec<vec<int>> result = flipToZero(matrix);
    print(result);
    return 0;
}