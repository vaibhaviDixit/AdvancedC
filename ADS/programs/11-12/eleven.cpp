/*
Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.


Input: s = "abab"
Output: 1

*/

#include<iostream>
#include<string>

using namespace std;

// Function to check if a string can be formed by repeating a substring
bool repeatedSubstringPattern(string str)
{
    // Append the string to itself to handle circular cases, e.g., abab -> abababab
    string temp = str + str;

    // Remove the first and last character to avoid counting the original string itself
    // e.g., for abababab, the intermediate string would be bababa
    string check = temp.substr(1, temp.size()-2);

    // Find the first occurrence of the original string in the intermediate string
    // If it's not found, then the original string cannot be formed by repeating a substring
    int ans = check.find(str);
    if(ans == -1)
    {
        return false;
    }

    return true;
}

int main()
{
    string s;
    cin >> s;

    // Call the repeatedSubstringPattern function and store the result in 'result'
    bool result = repeatedSubstringPattern(s);

    // Output the result (1 for true, 0 for false)
    cout << result;

    return 0;
}

/*
The repeatedSubstringPattern function takes a string str as input and checks whether it can be formed by repeating a substring.
Inside the function, the string str is concatenated with itself, creating a temp string that handles circular cases. For example, if str is "abab", temp becomes "abababab".
The check string is then created by taking a substring of temp from the second character to the second-to-last character. This is done to remove the original string from the circular version, so we get an intermediate string that can be checked for repeated substrings.
The find method is used to search for the first occurrence of the original string str in the intermediate string check.
If the find method returns -1, it means that the original string str is not found in the intermediate string, and thus it cannot be formed by repeating a substring. In this case, the function returns false.
Otherwise, if the original string str is found in the intermediate string, the function returns true.
In the main function, a string s is read from the user using cin.
The repeatedSubstringPattern function is called with the input string s, and the result is stored in the boolean variable result.
Finally, the result is output using cout, where 1 represents true and 0 represents false.

*/

