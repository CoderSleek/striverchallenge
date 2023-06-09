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

bool safe(std::pair<int, int> &coord, int n, vec<vec<bool>> &visited, vec<vec<int>> &arr){
    if(coord.first >= 0 && coord.first < n && coord.second >= 0 && coord.second < n
    && arr[coord.first][coord.second] == 1 && !visited[coord.first][coord.second]) return true;
    return false;
}

void check_maze(vec<vec<int>> &arr, vec<vec<bool>> &visited, std::pair<int, int> &coord, vec<char> &path, vec<std::string> &allans){
    visited[coord.first][coord.second] = true;
    int n = arr.size();

    // base case
    if(coord.first == n-1 && coord.second == n-1){
        allans.push_back(std::string(path.begin(), path.end()));
        return;
    }
    
    //down
    coord.first += 1;
    if(safe(coord, n, visited, arr)){
        path.push_back('D');
        check_maze(arr, visited, coord, path, allans);

        visited[coord.first][coord.second] = false;
        path.pop_back();
    }
    coord.first -= 1;

    //right
    coord.second += 1;
    if(safe(coord, n, visited, arr)){
        path.push_back('R');
        check_maze(arr, visited, coord, path, allans);

        visited[coord.first][coord.second] = false;
        path.pop_back();
    }
    coord.second -= 1;

    // up
    coord.first -= 1;
    if(safe(coord, n, visited, arr)){
        path.push_back('U');
        check_maze(arr, visited, coord, path, allans);

        visited[coord.first][coord.second] = false;
        path.pop_back();
    }
    coord.first += 1;

    //left
    coord.second -= 1;
    if(safe(coord, n, visited, arr)){
        path.push_back('L');
        check_maze(arr, visited, coord, path, allans);

        visited[coord.first][coord.second] = false;
        path.pop_back();
    }
    coord.second += 1;
    return;
}

void maze(vec<vec<int>> &arr){
    if(arr[0][0] == 0){
        return;
    }
    vec<vec<bool>> visited(arr.size(), vec<bool>(arr[0].size(), false));
    vec<std::string> allans;
    vec<char> path;
    std::pair<int, int> coord{0,0};
    check_maze(arr, visited, coord, path, allans);

    for(auto &ch : allans){
        cout<<ch<<std::endl;
    }
}

int main(int argv, char **argc){
    vec<vec<int>> arr{{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    maze(arr);
    return 0;
}