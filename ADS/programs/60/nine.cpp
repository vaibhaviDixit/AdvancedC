/*
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections.
The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between
any two intersections.
You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections
ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection
n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large,
return it modulo 109 + 7.

Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output: 4

*/

#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

const int mod = 1e9 + 7;

class Solution {
public:
    // Function to count the number of ways to reach from 0 to n-1 in the shortest time
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<ll> >d (n,vector<ll>(n,LONG_MAX));
        vector<vector<ll> >w (n,vector<ll>(n,0));

        // Initialize distance and weight arrays with road information
        for(int i=0;i<roads.size();i++){
            d[roads[i][0]][roads[i][1]]=roads[i][2];
            d[roads[i][1]][roads[i][0]]=roads[i][2];
            w[roads[i][0]][roads[i][1]]=1;
            w[roads[i][1]][roads[i][0]]=1;
        }
        for(int i=0;i<n;i++) {w[i][i]=1;d[i][i]=0;}

        // Floyd-Warshall algorithm
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i!=j and j!=k and k!=i and d[i][k]!=LONG_MAX and d[k][j]!=LONG_MAX){
                        if(d[i][j]>d[i][k]+d[k][j]){
                            w[i][j]=w[i][k];
                            d[i][j]=d[i][k]+d[k][j];
                        }
                        else if(d[i][j]==d[i][k]+d[k][j]){
                            w[i][j]=(w[i][j]+w[i][k])%mod;
                        }
                    }
                }
            }
        }

        // Return the number of ways to reach n-1 from 0 in shortest time
        return w[0][n-1];
    }
};

int main() {
    Solution obj;
    int n = 7;
    vector<vector<int>> roads = {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
    int result = obj.countPaths(n, roads);
    cout << "Number of ways: " << result << endl;
    return 0;
}

/*
This program defines a Solution class with the countPaths method to solve the given LeetCode problem.
It implements the Floyd-Warshall algorithm to find the shortest path between all pairs of nodes while
keeping track of the number of ways to reach each node. The program outputs the number of ways to reach
the last node from the first node in the shortest time modulo 10^9 + 7. The comments in the code explain
each step and data structure used to solve the problem.

*/




