/*
Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway
station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train
but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for
both departure of a train and arrival of another train. In such cases, we need different platforms.


Input: n = 6
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation:
Minimum 3 platforms are required to safely arrive and depart all trains.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the minimum number of platforms needed for a train schedule.
    int findPlatform(int arr[], int dep[], int n) {
        // Convert the input arrays to vectors for easier sorting.
        vector<int> ar(arr, arr + n);
        vector<int> de(dep, dep + n);

        // Sort the arrival and departure vectors in ascending order.
        sort(ar.begin(), ar.end());
        sort(de.begin(), de.end());

        int ans = 0; // Variable to store the minimum number of platforms needed.

        // Traverse through the arrival and departure times simultaneously.
        for (int i = 0; i < n; i++) {
            // Find the index of the first arrival time greater than or equal to the current departure time.
            int idx = upper_bound(ar.begin(), ar.end(), de[i]) - ar.begin();
            idx--; // Decrement the index to get the position of the last train that has arrived before the current departure time.
            ans = max(ans, idx - i + 1); // Calculate the number of trains present at the station and update the minimum platforms needed.
        }

        return ans; // Return the minimum number of platforms needed.
    }
};

int main() {
    int n;
    cin >> n; // Input the number of trains.

    int arr[n]; // Array to store the arrival times.
    int dep[n]; // Array to store the departure times.

    // Input the arrival times and departure times for each train.
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int j = 0; j < n; j++) {
        cin >> dep[j];
    }

    Solution ob; // Create an object of the Solution class.

    // Call the findPlatform function to get the minimum number of platforms needed.
    cout << ob.findPlatform(arr, dep, n) << endl;

    return 0;
}

/*
The findPlatform function takes three parameters: arr (an array of integers representing arrival times), dep (an array of integers representing departure times), and n (the number of trains in the schedule).
The function first converts the input arrays arr and dep into vectors ar and de for easier sorting and manipulation.
The arrival and departure vectors ar and de are sorted in ascending order using the sort function from the standard library.
The function initializes the variable ans to store the minimum number of platforms needed to accommodate the train schedule.
It then traverses through the arrival and departure times simultaneously and calculates the number of trains present at the station at each moment.
To find the number of trains present at a particular departure time, the function uses the upper_bound function to find the index of the first arrival time greater than or equal to the current departure time. It then decrements the index to get the position of the last train that has arrived before the current departure time.
The function updates the ans variable with the maximum number of trains observed at any moment during the schedule.
Finally, the function returns the minimum number of platforms needed (ans).
In the main function, the user is prompted to enter the number of trains (n).
Two arrays arr and dep of size n are declared to store the arrival times and departure times, respectively.
The arrival times and departure times for each train are input from the user using loops.
An object of the Solution class is created (named ob).
The findPlatform function is called on the object ob, passing the arrays arr, dep, and n.
The result (minimum number of platforms needed) is printed on the console.

*/



