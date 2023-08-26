/*
In a party of N people, only one person is known to everyone. Such a person may be present at the party, if yes, (s)he doesn’t know anyone at the party.
We can only ask questions like “does A know B? “. Find the stranger (celebrity) in the minimum number of questions.
We can describe the problem input as an array of numbers/characters representing persons in the party.
We also have a hypothetical function HaveAcquaintance(A, B) which returns true if A knows B, and false otherwise. How can we solve the problem?

Input: MATRIX = { {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0} }
Output: Celebrity ID=2

Input: MATRIX = { {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 1, 0, 0}, {0, 0, 1, 0} }
Output: No celebrity

*/

// C++ program to find the celebrity
#include <bits/stdc++.h>
#include <list>
using namespace std;

// Max # of persons in the party
#define N 8

// Person with 2 is the celebrity
bool MATRIX[N][N] = { { 0, 0, 1, 0 },
                      { 0, 0, 1, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 1, 0 } };

// Function to check if person 'a' knows person 'b'
bool knows(int a, int b) {
    return MATRIX[a][b];
}

// Function to find the celebrity
int findCelebrity(int n) {
    stack<int> s;

    // Celebrity
    int C;

    // Push everybody onto the stack
    for (int i = 0; i < n; i++)
        s.push(i);

    // Find a potential celebrity
    while (s.size() > 1) {
        int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();
        if (knows(A, B)) {
            s.push(B);
        } else {
            s.push(A);
        }
    }

    // Potential candidate?
    C = s.top();
    s.pop();

    // Check if C is actually a celebrity or not
    for (int i = 0; i < n; i++) {
        // If any person doesn't know 'C' or 'C' doesn't
        // know any person, return -1
        if ((i != C) && (knows(C, i) || !knows(i, C)))
            return -1;
    }

    return C;
}


int main() {
    int n = 4;
    int id = findCelebrity(n);
    id == -1 ? cout << "No celebrity"
             : cout << "Celebrity ID " << id;
    return 0;
}

/*
This program aims to find a celebrity in a party using a two-pass elimination approach. A celebrity is a person who is known by everyone but
knows nobody in return. The MATRIX array represents the relationships between people (1 if person i knows person j, otherwise 0).
The program uses a stack to iteratively eliminate potential candidates, assuming that a celebrity knows nobody and others know the celebrity.
After the elimination process, the remaining candidate is checked to ensure that they are indeed a celebrity by verifying that everyone knows
them and they know nobody. If a celebrity is found, their ID is returned; otherwise, -1 is returned. The program demonstrates a common interview
problem that involves logical reasoning and stack usage.

*/



