/*
Given a sequence of words, and a limit on the number of characters that can be put in one line (line width). Put line breaks in the given sequence such
that the lines are printed neatly. Assume that the length of each word is smaller than the line width.
The word processors like MS Word do task of placing line breaks. The idea is to have balanced lines. In other words, not have few lines with lots of extra
spaces and some lines with small amount of extra spaces.

Input:
l[] = {3, 2, 2, 5}
n=4, m=6
Output:
Line number 1: From word no. 1 to 1
Line number 2: From word no. 2 to 3
Line number 3: From word no. 4 to 4


*/


// A Dynamic programming solution for Word Wrap Problem
#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

// A utility function to print the solution
int printSolution (int p[], int n);

// l[] represents lengths of different words in input sequence.
// For example, l[] = {3, 2, 2, 5} is for a sentence like "aaa bb cc ddddd". n is size of l[] and M is line width (maximum no. of characters that can fit in a line)
void solveWordWrap (int l[], int n, int M)
{
    // For simplicity, 1 extra space is used in all below arrays

    // extras[i][j] will have number of extra spaces if words from i
    // to j are put in a single line
    int extras[n+1][n+1];

    // lc[i][j] will have cost of a line which has words from
    // i to j
    int lc[n+1][n+1];

    // c[i] will have total cost of optimal arrangement of words from 1 to i
    int c[n+1];

    // p[] is used to print the solution.
    int p[n+1];

    int i, j;

    // calculate extra spaces in a single line. The value extra[i][j] indicates extra spaces if words from word number i to j are placed in a single line
    for (i = 1; i <= n; i++)
    {
        extras[i][i] = M - l[i-1];
        for (j = i+1; j <= n; j++)
            extras[i][j] = extras[i][j-1] - l[j-1] - 1;
    }

    // Calculate line cost corresponding to the above calculated extra spaces. The value lc[i][j] indicates cost of putting words from word number i to j in a single line
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (extras[i][j] < 0)
                lc[i][j] = INF;
            else if (j == n && extras[i][j] >= 0)
                lc[i][j] = 0;
            else
                lc[i][j] = extras[i][j]*extras[i][j];
        }
    }

    // Calculate minimum cost and find minimum cost arrangement. The value c[j] indicates optimized cost to arrange words from word number 1 to j.
    c[0] = 0;
    for (j = 1; j <= n; j++)
    {
        c[j] = INF;
        for (i = 1; i <= j; i++)
        {
            if (c[i-1] != INF && lc[i][j] != INF &&
                    (c[i-1] + lc[i][j] < c[j]))
            {
                c[j] = c[i-1] + lc[i][j];
                p[j] = i;
            }
        }
    }

    printSolution(p, n);
}

int printSolution (int p[], int n)
{
    int k;
    if (p[n] == 1)
        k = 1;
    else
        k = printSolution (p, p[n]-1) + 1;
    cout<<"Line number "<<k<<": From word no. "<<p[n]<<" to "<<n<<endl;
    return k;
}

int main()
{
    int l[] = {3, 2, 2, 5};
    int n = sizeof(l)/sizeof(l[0]);
    int M = 6;
    solveWordWrap (l, n, M);
    return 0;
}

/*
The solveWordWrap function is defined to solve the Word Wrap Problem. It takes the following arguments:

l[]: An array representing the lengths of different words in the input sequence.
n: The size of the l[] array, indicating the number of words.
M: The line width, i.e., the maximum number of characters that can fit in a line.
Inside solveWordWrap, several dynamic programming arrays are declared and initialized:

extras[i][j]: Represents the number of extra spaces if words from position i to j are put in a single line.
lc[i][j]: Represents the cost of a line that has words from position i to j. The cost is determined by the extra spaces.
c[i]: Stores the total cost of the optimal arrangement of words from position 1 to i.
p[i]: Stores the position of the word where a line ends for the optimal arrangement.
The program calculates extras[i][j] by iterating over all possible pairs of i and j. This step calculates how many extra spaces would be left at the end of a line if words from position i to j are placed on a single line.

Based on the calculated extras, lc[i][j] is calculated to represent the cost of a line with words from position i to j. If extras[i][j] is negative, it sets lc[i][j] to a very high value (INF) to indicate that this arrangement is not feasible.

The program initializes the c array and starts calculating the minimum cost for arranging words up to position j. It uses a nested loop to consider different possible starting positions i for the line.

For each i, it checks if the cost of starting a new line at position i and adding the cost of the current line (lc[i][j]) is less than the cost for the previous arrangement. If it is, it updates c[j] and p[j] to reflect this better arrangement.

Finally, the printSolution function is called to print the optimized arrangement of words. It uses the p array to determine where each line ends and displays the line number and the range of words in each line.

In the main function, an example array l representing the lengths of words and the line width M is provided. The program then calls solveWordWrap to find the optimized word wrapping arrangement and displays the result.

*/


