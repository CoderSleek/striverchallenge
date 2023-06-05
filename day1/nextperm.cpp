/*#include<bits/stdc++.h>
using std::cout;
using std::vector;

using ll = long long;
using dl = long double;
template<typename T>
using vec = std::vector<T>;
template<typename T>
using viter = typename vector<T>::iterator;
#define for_inc(i, m) for (int index = i; index < m; ++index)

vec<int> nextperm(vec<int> &arr){
    bool next = next_permutation(arr.begin(), arr.end());

    if(next) return arr;

    sort(arr.begin(), arr.end());
    return arr;
}

int main(int argv, char **argc){
    vec<int> arr{3,2,1};
    auto a = nextperm(arr);
    for(auto &i : a){
        cout<<i<<" ";
    }
    return 0;
}*/

// without stl

/*void nextPermutation(vector<int>& arr) {
    int index = -1, n = arr.size();

    for(int i = n-2; i >= 0; --i){
        if(arr[i] < arr[i + 1]){
            index = i;
            break;
        }
    }

    if(index == -1){
        reverse(arr.begin(), arr.end());
        return;
    }

    for(int i = n-1; i > index; --i){
        if(arr[i] > arr[index]){
            swap(arr[i], arr[index]);
            break;
        }
    }

    reverse(arr.begin() + index + 1, arr.end());
}*/

// bonus permutation of all strings

// #include<bits/stdc++.h>

// using namespace std;
// class Solution {
//   private:
//     void recurPermute(vector < int > & ds, vector < int > & nums, vector < vector < int >> & ans, int freq[]) {
//       if (ds.size() == nums.size()) {
//         ans.push_back(ds);
//         return;
//       }
//       for (int i = 0; i < nums.size(); i++) {
//         if (!freq[i]) {
//           ds.push_back(nums[i]);
//           freq[i] = 1;
//           recurPermute(ds, nums, ans, freq);
//           freq[i] = 0;
//           ds.pop_back();
//         }
//       }
//     }
//   public:
//     vector < vector < int >> permute(vector < int > & nums) {
//       vector < vector < int >> ans;
//       vector < int > ds;
//       int freq[nums.size()];
//       for (int i = 0; i < nums.size(); i++) freq[i] = 0;
//       recurPermute(ds, nums, ans, freq);
//       return ans;
//     }
// };

// int main() {
//   Solution obj;
//   vector<int> v{1,2,3, 4, 5, 6};
//   vector < vector < int >> sum = obj.permute(v);
//   cout << "All Permutations are " << endl;
//   for (int i = 0; i < sum.size(); i++) {
//     for (int j = 0; j < sum[i].size(); j++)
//       cout << sum[i][j] << " ";
//     cout << endl;
//   }
// }

#include<bits/stdc++.h>
using std::cout;
using std::vector;
using std::string;
using std::swap;

template<typename T>
using vec = std::vector<T>;

#define for_inc(start, stop) for (int i = start; i < stop; ++i)

void permute(string &str, vec<string> &ans, int index){
    if(index >= str.size()){
        ans.push_back(str);
        return;
    }

    for(int j = index; j < str.size(); ++j){
        swap(str[index], str[j]);
        permute(str, ans, index+1);
        swap(str[index], str[j]); // offset shuffling by 1st swap
    }
}

int main(int argv, char **argc){
    vec<string> ans;
    string start = "12345";
    permute(start, ans, 0);

    for(auto &st: ans){
        cout<<st<<std::endl;
    }
    return 0;
}