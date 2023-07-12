/*
Write a C++ program to concatenate two strings and three strings using method overloading.

Example:
Enter string 1: hello
Enter string 2: indian
Concatenated string: helloindian
Enter string 3: soldiers
Concatenated string: helloindiansoldiers
*/

#include<iostream>
#include<string>

// Concatenate two strings
std::string concatenateStrings(const std::string& str1, const std::string& str2)
{
    return str1 + str2;
}

// Concatenate three strings
std::string concatenateStrings(const std::string& str1, const std::string& str2, const std::string& str3)
{
    return str1 + str2 + str3;
}

int main()
{

    std::string str1, str2, str3;

    // Two strings
    std::cout << "Enter string 1: ";
    std::getline(std::cin, str1);

    std::cout << "Enter string 2: ";
    std::getline(std::cin, str2);

    std::cout << "Concatenated string: " << concatenateStrings(str1, str2) << std::endl;

    // Three strings
    std::cout << "Enter string 3: ";
    std::getline(std::cin, str3);

    std::cout << "Concatenated string: " << concatenateStrings(str1, str2, str3) << std::endl;

    return 0;
}
