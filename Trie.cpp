// Description: This class is a Trie, a tree like structure, that holds
// words to serve as a lexicon

#include "Trie.h"
#include <fstream>
#include <iostream>

// default ctor
Trie::Trie() : headNode(' ', false) {
  // nothing to do
}

/*Insert
 * Insert strstarting with the head Node.
 * Create new TrieNodes as needed and sets the boolean flag on the last node to
 * true pre: node exists post: all letters below the node will reflect the word
 * passed
 */
void Trie::insert(const std::string &word) { headNode.insert(word); }

/* loadFromFile
 * Method takes in strings from a text file and inserts them into the trie
 * pre: file and trie exists
 * post: trie is updated with words found in the file
 */
void Trie::loadFromFile(const std::string &filename) {
  std::string str;
  std::ifstream file(filename.c_str());
  // Do error checking here
  if (!file) {
    std::cout << "invalid file name!" << std::endl;
    throw std::invalid_argument("Unable to open file.");
  }

  while (file >> str) {
    headNode.insert(str);
  }
}

/* isWord
 * Returns true if str exists in the trie,
 * else returns false
 * pre: trie exists
 * post: boolean value is returned
 */
bool Trie::isWord(const std::string &word) const {
  return headNode.isWord(word);
}

/* isPrefix
 * Returns true if pre is a prefix of a word in the sub-Trie starting at the
 * given TrieNode, else returns false pre: node exists post: boolean value is
 * returned
 */
bool Trie::isPrefix(const std::string &pre) const {
  return headNode.isPrefix(pre);
}

/* print
 *Prints all words contained by the trie.
 * The parameter string str stores the letters of all previous TrieNode
 * objects up to the node currently being processed.
 * pre: node exists
 * post: all words in the trie starting at the given node is printed
 */
void Trie::print() const { headNode.print(""); }

/* wordCount
 * Returns a count all the nodes in the sub-Trie that end a word.
 * pre: node exists
 * post: size_t value returned
 */
size_t Trie::wordCount() const { return headNode.wordCount(); }