#include<bits/stdc++.h>

#define vt vector
#define ll long long
#define pr pair
#define mkpr make_pair
#define pb push_back
#define len(arr) (sizeof(arr)/sizeof(arr[0]))

using namespace std;

int main() {
   string input; cin >> input;
   int n = input.length();
   int z_values[n + 1];
   fill_n(z_values, n + 1, -1);
   for (int i = 1; i <= n; i++) {
      cout << z_values[i] << ',';
   }
   cout << '\n';

   z_values[1] = 0;
   int idx_longest = 1;
   for (int i = 2; i < n; i++) {
      if (idx_longest + z_values[idx_longest] - 1 > i) {
         if (z_values[i - idx_longest + 1] < z_values[idx_longest] - (i - idx_longest + 1)) {
            z_values[i] = z_values[i - idx_longest + 1];
         } else if (z_values[i - idx_longest + 1] > z_values[idx_longest] - (i - idx_longest + 1)) {

         } else {
            //Do the comparisons
            int z = 0;
            for (int j = 1; j < i && i + j <= n; j++) {
               if (input[j] == input[i + j]) 
                  z++;
            }
            z_values[i] = z;
            if (z_values[i] + i - 1 > z_values[idx_longest] + idx_longest - 1) 
               idx_longest = i;

         }
      } else {
         //Do the comparisons
         int z = 0;
         for (int j = 1; j < i && i + j  - 2 < n; j++) {
            if (input[j - 1] == input[i + j - 2]) z++;
         }
         z_values[i] = z;
         if (z_values[i] + i - 1 > z_values[idx_longest] + idx_longest - 1) 
            idx_longest = i;

      }
   }
   return 0;
}


/*
//INT_MAX, INT_MIN
#include <limits>
using namespace std;
int main() {
    int n; cin >> n;
    int dp[n]; fill_n(dp, n, INT_MAX);
    return 0;
}

//initialize vector dp matrix
vector<vector<int>> dp(n, vector<int>(m));

vector.clear(); //clears out the vector
vector.erase(vector.begin() + 1);//delete second element from vector

//sort vector
#include <bits/stdc++.h>
sort(vector.begin(), vector.end())


//sort with lambda
sort(vector.begin(), vector.end(), [](int a, int b) -> bool { return a - b; });

//for each
for (auto& x: a)


//function for initializing vector matrix
template <typename T> vector<vector<T>> make_matrix(int n, T m) {
    vector<vector<T>> dp(n, vector<T>(m));
    return dp;
}

//maps
#include<map>
map<char, int> mp;
map<char, int> mp = {
   {'J', 0},
   {'F', 3},
   {'S', 10}
};
mp['J'];//access
mp['X'] = 30;//insert
mp.insert(pair<char, int>('E', 12));//more formal way to insert (?)
mp.erase('X');
mp.clear();
mp.empty(); //1 if empty, 0 otherwise
mp.size(); //returns the size of the map


//Check if key exists
if (mp.find(letter) == mp.end()) {
   //key does not exist
}

//iterate through map
for (auto itr = mp.begin(); itr != mp.end(); itr++) {
    cout << itr->first << ": " << itr->second << '\n';
}

//With C++ 11
for (auto const& p : mp) {
   cout << p.first << ": " << p.second << '\n';
}

//With C++ 17
for (auto const& [key, value] : mp) {
   cout << key << ": " << value << '\n';
}

*/
