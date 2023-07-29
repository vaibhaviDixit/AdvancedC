/*
You are given an array of words, and you need to find the longest common prefix among them.

Input: {"apple", "ape", "april"}
Output: The longest common prefix is: ap

*/

#include <stdio.h>
#include <string.h>

// Function to find the longest common prefix
char* longestCommonPrefix(char* ar[], int n) {
    // If size is 0, return empty string
    if (n == 0)
        return "";

    // If size is 1 then just return that character
    if (n == 1)
        return ar[0];

    // Sort the given array (lexicographically)
    // so that the common prefix will be in the first and last string
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(ar[i], ar[j]) > 0) {
                char* temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }

    // Find the minimum length from first and last string
    int en = strlen(ar[0]);
    if (strlen(ar[n - 1]) < en)
        en = strlen(ar[n - 1]);

    // Now the common prefix in first and last string is the longest common prefix
    int i = 0;
    while (i < en && ar[0][i] == ar[n - 1][i])
        i++;

    char* pre = (char*)malloc((i + 1) * sizeof(char));
    strncpy(pre, ar[0], i);
    pre[i] = '\0';
    return pre;
}

int main() {
    char* ar[] = {"banana", "basket", "bandra"};
    int n = sizeof(ar) / sizeof(ar[0]);
    char* longestCP= longestCommonPrefix(ar, n);
    printf("The longest common prefix is: %s\n", longestCP);
    free(longestCP);
    return 0;
}

/*
The given C program finds the longest common prefix among the given array of words using lexicographical sorting
and comparison. It first sorts the array of strings in lexicographically increasing order.
Then, it compares the first and last strings to find the longest common prefix.

*/



