
// Description: This program implements a "TextTwist" game, which outputs all
// words at least three letters long using characters supplied by a user email:
#include "TextTwist.h"
#include <iostream>

/* TextTwist()
 * Game constructor - creates the three tries, and loads the dictionary Trie
 * with the text file. Then asks the user for a seven-character string to
 * process Post: a TextTwist game is created with the tree tries, and a
 * seven-character string of lower case letters is accepted.
 */
TextTwist::TextTwist() {
  dictionary.loadFromFile("ospd.txt");
  std::cout << "Please enter seven characters" << std::endl;
  std::cin >> input;
  while (input.length() != 7) {
    std::cout << "please enter seven characters" << std::endl;
    std::cin >> input;
  }
  for (size_t i = 0; i < input.length(); i++) {
    input[i] = tolower(input[i]);
  }
}

/* solveHelper()
 * Helper method that analyzes the strings passed to it and determines if they
 * should be inserted into Trie words. After this analysis, recursively calls
 * itself to examine all permutations of the seven-character input. To make this
 * more efficient, this method checks if the current combination of letters has
 * been analyzed before, and also backtracks if the currString is not a prefix
 * to any word in Trie dictionary. Pre: the helper method is originally passed
 * with blank string for currString and the user input for input. Post: All
 * words that 1. are at least three characters long
 *                      2. exist in Trie dictionary
 * are inserted into Trie words.
 */
void TextTwist::solveHelper(std::string currString, std::string input) {
  if (!prefixes.isWord(currString)) {
    prefixes.insert(currString); // keep track of new prefix combos
  } else {
    return; // if this prefix has already been considered, back up
  }
  if (input.empty()) { // check to see if base case
    if (dictionary.isWord(currString)) {
      words.insert(currString);
    } else {
      return;
    }
  }
  if (!dictionary.isPrefix(currString)) {
    return; // do not continue exploring this route if current prefix is
            // dead-end
  } else {
    for (size_t i = 0; i < input.length(); i++) {
      // if currString has grown to appropriate length, check to see if it's a
      // word
      if (currString.length() >= 3 && dictionary.isWord(currString)) {
        words.insert(currString);
      }
      char character = input[i];
      currString = currString + character; // choose
      input.erase(i, 1);
      solveHelper(currString, input); // explore
      input = character + input;
      currString.erase(currString.length() - 1, 1); // back up
    }
  }
}

/* solve()
 * Solves the game by calling solveHelper and passing an empty string to
 * parameter currString and the seven-character user input to parameter input.
 * Pre: the game has been successfully created and the user has entered a valid
 * string. Post: All valid words with minimum three characters constructed using
 * the user's input is loaded into Trie words.
 */
void TextTwist::solve() { solveHelper("", input); }

/* printFinal()
 * Prints out contents of Trie words.
 * Pre: game has been solved.
 * Post: results are printed out
 */
void TextTwist::printFinal() { words.print(); }