/*
Given two words, beginWord and endWord, and a dictionary of word transformations, find the length of the shortest transformation sequence from
beginWord to endWord. Each transformation should be made only if the resulting word is in the dictionary.

Input:
beginWord = "hit"
endWord = "cog"
wordList = {"hot", "dot", "dog", "lot", "log", "cog"}

Output: Length of the shortest transformation sequence: 5

*/


// Code for Word Ladder

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (dict.find(endWord) == dict.end())
        return 0;

    queue<string> q;
    q.push(beginWord);
    int level = 1;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            string word = q.front();
            q.pop();

            for (int j = 0; j < word.length(); j++) {
                char original = word[j];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[j] = ch;
                    if (word == endWord)
                        return level + 1;
                    if (dict.find(word) != dict.end()) {
                        q.push(word);
                        dict.erase(word);
                    }
                }
                word[j] = original;
            }
        }
        level++;
    }

    return 0;
}

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    int length = ladderLength(beginWord, endWord, wordList);

    cout << "Length of the shortest transformation sequence: " << length;

    return 0;
}

/*
The Word Ladder program finds the length of the shortest transformation sequence from beginWord to endWord using a breadth-first search approach.
It uses a queue to explore possible transformations of words. For each word in the queue, it tries all possible one-letter transformations and checks
if the resulting word is in the dictionary. If it is, the word is added to the queue for further exploration, and its entry is removed from the
dictionary to avoid revisiting the same word again. The process continues until the endWord is found, and the length of the transformation
sequence is returned. If endWord is not in the dictionary, it means there is no valid transformation sequence, and 0 is returned.

*/



