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

// my approach
// int longestSubstrNotRepeat(string &s){
//     if(s.size()==1) return 1;
//     int n = s.size();
//     unordered_set<char> dupl;
//     int max_size = 0;
//     for(int i = 0; i < n; ++i){
//         for(int j = i; j < n; ++j){
//             if(dupl.find(s[j]) != dupl.end()){
//                 max_size = max((int)dupl.size(), (int)max_size);
//                 dupl.clear();
//                 break;
//             } else {
//                 dupl.insert(s[j]);

//             }
//         }
//     }

//     return max_size;
// }

// my approach optimized
// int longestSubstrNotRepeat(string &s){
//     if(s.size() == 0 || s.size() == 1) return s.size();

//     unordered_set <char> ele;
//     // can use 2 pointer instead q to save space
//     queue<char> q;
//     int max_len = 0;
//     for(int i = 0; i < s.size(); ++i){
//         if(ele.find(s[i]) != ele.end()){
//             while(q.front() != s[i]){
//                 ele.erase(q.front());
//                 q.pop();
//             };
//             q.pop();
//         }
//         q.push(s[i]);
//         ele.insert(s[i]);
//         max_len = max(max_len, (int)q.size());
//     }

//     return max_len;
// }

// super optimized
int longestSubstrNotRepeat(string s) {
    if(s.size() == 0 || s.size() == 1) return s.size();

    unordered_map<char, int> ele;
    int max_len = 0, left = 0;
    for(int right = 0; right < s.size(); ++right){
        if(ele.find(s[right]) != ele.end()){
            left = max(ele[s[right]] + 1, left);
        }
        ele[s[right]] = right;
        max_len = max(max_len, right-left+1);
    }

    return max_len;
}

int main(int argv, char **argc){
    string s = "abcabcbb";
    cout<<longestSubstrNotRepeat(s);
    return 0;
}