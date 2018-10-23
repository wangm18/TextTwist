
// Description: This class is a Trie, a tree like structure, that holds
// words to serve as a lexicon


#ifndef PA10_TRIE_H
#define PA10_TRIE_H
#include "TrieNode.h"
#include <string>
class Trie {
private:
  TrieNode headNode;

public:
  // default ctor
  Trie();

  /*Insert
   * Insert strstarting with the head Node.
   * Create new TrieNodes as needed and sets the boolean flag on the last node
   * to true pre: node exists post: all letters below the node will reflect the
   * word passed
   */
  void insert(const std::string &word);

  /* loadFromFile
   * Method takes in strings from a text file and inserts them into the trie
   * pre: file and trie exists
   * post: trie is updated with words found in the file
   */
  void loadFromFile(const std::string &filename);

  /* isWord
   * Returns true if str exists in the trie,
   * else returns false
   * pre: trie exists
   * post: boolean value is returned
   */
  bool isWord(const std::string &word) const;

  /* isPrefix
   * Returns true if pre is a prefix of a word in the sub-Trie starting at the
   * given TrieNode, else returns false pre: node exists post: boolean value is
   * returned
   */
  bool isPrefix(const std::string &pre) const;

  /* print
   *Prints all words contained by the trie.
   * The parameter string str stores the letters of all previous TrieNode
   * objects up to the node currently being processed.
   * pre: node exists
   * post: all words in the trie starting at the given node is printed
   */
  void print() const;

  /* wordCount
   * Returns a count all the nodes in the sub-Trie that end a word.
   * pre: node exists
   * post: size_t value returned
   */
  size_t wordCount() const;
};
#endif // PA10_TRIE_H
