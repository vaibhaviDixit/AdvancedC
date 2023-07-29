/*
Write a C++ program that takes a string as input and checks if it's a palindrome or not using a deque.
The program should print "It's a palindrome!" if the input string is a palindrome and "It's not a palindrome!" otherwise.

Input: Enter a string: madam
Output: It's a palindrome!

*/

#include <iostream>
#include <deque>
#include <string>
#include<algorithm>

bool isPalindrome(const std::deque<char>& chars) {
    std::deque<char> reversedChars = chars;
    std::reverse(reversedChars.begin(), reversedChars.end());
    return reversedChars == chars;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::cin >> input;

    std::deque<char> characters(input.begin(), input.end());

    if (isPalindrome(characters)) {
        std::cout << "It's a palindrome!" << std::endl;
    } else {
        std::cout << "It's not a palindrome!" << std::endl;
    }

    return 0;
}


/*
This program checks if a given input string is a palindrome or not using a deque. A palindrome is a word, phrase, number, or other sequence of
characters that reads the same forward and backward. The program converts the input string into a deque of characters and then checks if the deque
remains the same when reversed.
If it does, the input string is a palindrome.
*/
