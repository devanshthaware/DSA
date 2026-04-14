// Word ladder
// you are given ->
//  beginWord
//  endWord
//  wordList
// find the length of the shortest transformation sequence from:
//  beginWord -> endWord
// rules:
//  change only one letter at a time
//  each transformed word must exist in the wordList
// return:
//  length of shortest sequence
//  0 if transformation is not possible
// example ->
//  beginWord = "hit"
//  endWord = "cog"
//  wordList = ["hot", "dot", "dog", "lot", "log", cog]
// output: 5
// transformation : hit
//                   |
//                  hot
//                   |
//                  dot
//                   |
//                  dog
//                   |
//                  cog
// total words: 5
// trust each word as a node
// an edge exists if:
//  only one letter is different
// we use bfs because:
//  we need the shortest transformation sequence

// algorithm ->
// put all words into a set
// push beginWord into queue
// while queue not empty:
//  for each word:
//      try changing every character
//      generate new words
//      if new word == endWord:
//          return steps
//      if word exists in set:
//          push into queue
//          remove from set
// return 0

// use unordered_set ->
// O(1) lookup
// avoid revisiting words

#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord,
                 string endWord,
                 vector<string> &wordList)
{
    unordered_set<string> wordSet(
        wordList.begin(),
        wordList.end());
    // If endWord not present
    if (!wordSet.count(endWord))
        return 0;
    queue<string> q;
    q.push(beginWord);
    int steps = 1;
    while (!q.empty())
    {

        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            string word = q.front();
            q.pop();
            // Try all positions
            for (int j = 0; j < word.length(); j++)
            {
                char original = word[j];
                // Try a-z
                for (char c = 'a'; c <= 'z'; c++)
                {

                    word[j] = c;

                    if (word == endWord)
                        return steps + 1;

                    if (wordSet.count(word))
                    {

                        q.push(word);
                        wordSet.erase(word);
                    }
                }
                word[j] = original;
            }
        }
        steps++;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {
        "hot", "dot", "dog",
        "lot", "log", "cog"};
    cout << ladderLength(
        beginWord,
        endWord,
        wordList);
    return 0;
}