/*
Given a string S. The task is to find all permutations (need not be different) of a given string.

Input:
S = AAA
Output: AAA AAA AAA AAA AAA AAA

Input:
S = ABSG
Output: ABGS ABSG AGBS AGSB ASBG ASGB
BAGS BASG BGAS BGSA BSAG BSGA GABS
GASB GBAS GBSA GSAB GSBA SABG SAGB
SBAG SBGA SGAB SGBA

*/

#include<bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<string> ans;

    void helper(string str,int ind)
    {
        if(ind == str.length())
        {
            ans.push_back(str); // store permutation
            return;
        }

        for(int i = ind; i < str.length(); i++)
        {
            swap(str[ind],str[i]);
            helper(str,ind+1);
            swap(str[ind],str[i]);
        }
    }

    vector<string> permutation(string S)
    {
        helper(S,0);
        sort(ans.begin(),ans.end()); // sort permutations
        return (ans);
    }
};


int main()
{

    string S;
    cin>>S;
    Solution ob;
    vector<string> vec = ob.permutation(S);
    for(string s : vec)
    {
        cout<<s<<" ";
    }
    cout<<endl;


    return 0;
}
/*
In above cpp program we have to calculate all possible permutations of given string.

*/

