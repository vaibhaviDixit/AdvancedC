/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Input: nums = [2,7,11,15], target = 9
Output: [0,1]

Input: nums = [3,2,4], target = 6
Output: [1,2]

*/

#include <iostream>

using namespace std;

void targetSum(int a[],int target,int n,int res[])
{
    for(int i = 0 ; i < n - 1 ; i++){
        for(int j = i + 1 ; j < n ; j++)
        {
            if(a[i] + a[j] == target){
                res[0]=i;
                res[1]=j;

            }
        }
    }

}

int main()
{
    int a[]= {2,7,11,15};

    int n=sizeof(a)/sizeof(a[0]);

    int target = 9;
    int res[]={};
    targetSum(a,target,n,res);

    for(int i=0;i<2;i++){
        cout<<res[i]<<" ";
    }

    cout << '\n';
}
