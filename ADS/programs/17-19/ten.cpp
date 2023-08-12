/*
Given a 2D board of letters and a list of words, find all words in the board.

Input:
board= {'o', 'a', 'a', 'n'}
        {'e', 't', 'a', 'e'}
        {'i', 'h', 'k', 'r'}
        {'i', 'f', 'l', 'v'}

words = {"oath", "pea", "eat", "rain"}

Output:
Words found in the board:
oath
eat

*/


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

const vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    string word;
};

void insertWord(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (char ch : word) {
        if (!node->children.count(ch))
            node->children[ch] = new TrieNode();
        node = node->children[ch];
    }
    node->word = word;
}

void searchWord(TrieNode* root, int x, int y, vector<vector<char>>& board, vector<string>& result) {
    if (!root || board[x][y] == '#' || !root->children.count(board[x][y]))
        return;

    char ch = board[x][y];
    TrieNode* nextNode = root->children[ch];

    if (!nextNode->word.empty()) {
        result.push_back(nextNode->word);
        nextNode->word.clear();
    }

    board[x][y] = '#'; // Mark cell as visited

    for (const auto& dir : directions) {
        int newX = x + dir.first;
        int newY = y + dir.second;
        if (newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size())
            searchWord(nextNode, newX, newY, board, result);
    }

    board[x][y] = ch; // Restore the original character
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> result;
    TrieNode* root = new TrieNode();

    for (const string& word : words)
        insertWord(root, word);

    for (int x = 0; x < board.size(); x++) {
        for (int y = 0; y < board[0].size(); y++) {
            searchWord(root, x, y, board, result);
        }
    }

    return result;
}

int main() {
    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };

    vector<string> words = {"oath", "pea", "eat", "rain"};

    vector<string> result = findWords(board, words);

    cout << "Words found in the board:\n";
    for (const string& word : result) {
        cout << word << endl;
    }

    return 0;
}

/*
The Word Search II program finds all words present in a 2D board of letters using a Trie data structure.
First, we build a Trie containing all the words from the input list. Then, we perform a depth-first search on the board starting from each
cell to search for words that are prefixes in the Trie. If a word is found in the Trie during the search, we add it to the result and clear
the word in the Trie to avoid duplicates. The findWords function calls searchWord for each cell in the board to find all words present.

*/


