/*
Given an array of lowercase strings A[] of size N, determine if the strings can be chained together to form a circle.
A string X can be chained together with another string Y if the last character of X is same as first character of Y. If every string of the
array can be chained with exactly two strings of the array(one with the first character and second with the last character of the string),
it will form a circle.


Input:
N = 3
A[] = { "abc", "bcd", "cdf" }
Output:
0
Explaination: These strings can't form a circle because no string has 'd'at the starting index.

Input:
N = 4
A[] = { "ab" , "bc", "cd", "da" }
Output:
1

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Depth-First Search (DFS) function to find if a circular chain can be formed
    void dfs(int src, vector<string> &arr, int n, int &cnt, vector<int> &visited)
    {
        visited[src] = 1; // Mark the current node as visited
        for (int i = 0; i < n; i++)
        {
            if (!visited[i]) // If the node is not visited yet
            {
                // Check if the last character of the current string matches the first character of the next string
                if (arr[src][arr[src].length() - 1] == arr[i][0])
                {
                    cnt++; // Increment the count of strings in the circular chain
                    dfs(i, arr, n, cnt, visited); // Recursively call DFS on the next string in the chain
                }
            }
        }
        return;
    }

    // Function to check if a circular chain can be formed using the given strings
    int isCircle(int n, vector<string> arr)
    {
        // Create a frequency map to count occurrences of characters at the beginning and end of strings
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i][0]]++;
            mp[arr[i][arr[i].length() - 1]]++;
        }

        bool flag = 1;
        for (auto it : mp)
        {
            if (it.second % 2 == 1)
            {
                flag = false; // If there is any character with an odd frequency, a circular chain is not possible
                break;
            }
        }

        // Special case when only one string is provided
        if (n == 1)
        {
            if (arr[0][0] == arr[0][arr[0].length() - 1])
                return 1; // If the single string is already a circular chain, return true
            return 0; // Otherwise, return false
        }

        vector<int> visited(n, 0); // Create a vector to mark visited strings during DFS
        for (int i = 0; i < n; i++)
        {
            int cnt = 1; // Initialize the count of strings in the current chain to 1
            dfs(i, arr, n, cnt, visited); // Start DFS from the current string
            if (cnt == n)
                return 1 && flag; // If the count of strings in the chain is equal to the total number of strings, return true
        }
        return 0 && flag; // If no circular chain is found, return false
    }
};

int main()
{
    int N;
    cin >> N;
    vector<string> A;
    string s;

    for (int i = 0; i < N; i++)
    {
        cin >> s;
        A.push_back(s);
    }

    Solution ob;
    cout << ob.isCircle(N, A) << endl; // Output 1 if a circular chain can be formed, 0 otherwise

    return 0;
}

/*
The provided code defines a C++ class Solution with a method isCircle that checks whether a circular chain can be formed using a given set
of strings. The isCircle function uses a Depth-First Search (DFS) approach to traverse the strings and find a circular chain.
It also checks for some special cases like having only one string or if there are characters with odd frequency at the beginning or end of
the strings, as that would make forming a circular chain impossible. The main function takes the input strings and prints the result returned
by the isCircle method. If the method returns 1, it means a circular chain can be formed; otherwise, it returns 0, indicating it's not
possible to form a circular chain with the given strings.

*/


