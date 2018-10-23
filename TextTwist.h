
// Description: This program implements a "TextTwist" game, which outputs all
// words at least three letters long using characters supplied by a user email:

#include "Trie.h"


class TextTwist {
public:
  /* TextTwist()
   * Game constructor - creates the three tries, and loads the dictionary Trie
   * with the text file. Then asks the user for a seven-character string to
   * process Post: a TextTwist game is created with the tree tries, and a
   * seven-character string of lower case letters is accepted.
   */
  TextTwist();

  /* solve()
   * Solves the game by calling solveHelper and passing an empty string to
   * parameter currString and the seven-character user input to parameter input.
   * Pre: the game has been successfully created and the user has entered a
   * valid string. Post: All valid words with minimum three characters
   * constructed using the user's input is loaded into Trie words.
   */
  void solve();

  /* solveHelper()
   * Helper method that analyzes the strings passed to it and determines if they
   * should be inserted into Trie words. After this analysis, recursively calls
   * itself to examine all permutations of the seven-character input. To make
   * this more efficient, this method checks if the current combination of
   * letters has been analyzed before, and also backtracks if the currString is
   * not a prefix to any word in Trie dictionary. Pre: the helper method is
   * originally passed with blank string for currString and the user input for
   * input. Post: All words that 1. are at least three characters long
   *                      2. exist in Trie dictionary
   * are inserted into Trie words.
   */
  void solveHelper(std::string currString, std::string input);

  /* printFinal()
   * Prints out contents of Trie words.
   * Pre: game has been solved.
   * Post: results are printed out
   */
  void printFinal();

private:
  Trie dictionary;   // this trie holds the definitions
  Trie words;        // this trie holds the valid words
  Trie prefixes;     // this trie keeps track of what prefixes have been checked
  std::string input; // user's seven-character input
};

