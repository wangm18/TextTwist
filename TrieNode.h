
// Description: This class is a TrieNode, which supports the Trie class. Holds a
// letter, a boolean flag, and an array of pointers

#ifndef PA10_TRIENODE_H
#define PA10_TRIENODE_H
#include <string>
const int ALPHABET = 26;

class TrieNode {
  typedef TrieNode *TrieNodePtr;

private:
public:
  char letter;
  bool endOfWord;
  TrieNodePtr array[ALPHABET];

  /*TriNode(char c, bool b)
   * This is the only constructor for the TrieNode class
   * post: a TrieNode is initialized with b and c, as well as an
   * array of ALPHABET nullpointers
   */
  TrieNode(char c, bool b);

  /*TrieNode(const TrieNode& rhs)
   * Copy ctor for TrieNode
   * pre: rhs exists
   * post: a deep TrieNode copy, identical to rhs is created
   */
  TrieNode(const TrieNode &rhs);

  /*dtor
   * pre: The TrieNode exists
   * post: trienode is destroyed
   */
  ~TrieNode();

  /*const TrieNode& operator=(const TrieNode& rhs)
   * Assignment operator
   * pre: rhs exists
   * post: The trienode that calls this assignment operator is now identical to
   * rhs, including its children
   */
  const TrieNode &operator=(const TrieNode &rhs);

  /*Insert
   * Insert strstarting with the given TrieNode.
   * Create new TrieNodes as needed and sets the boolean flag on the last node
   * to true pre: node exists post: all letters below the node will reflect the
   * word passed
   */
  void insert(const std::string &str);

  /* isWord
   * Returns true if str exists in the sub-Trie starting at the given TrieNode,
   * else returns false
   * pre: node exists
   * post: boolean value is returned
   */
  bool isWord(const std::string &str) const;

  /* isPrefix
   * Returns true if pre is a prefix of a word in the sub-Trie starting at the
   * given TrieNode, else returns false pre: node exists post: boolean value is
   * returned
   */
  bool isPrefix(const std::string &pre) const;

  /* print
   *Prints all words starting at the given TrieNode.
   * The parameter string str stores the letters of all previous TrieNode
   * objects up to the node currently being processed.
   * pre: node exists
   * post: all words in the trie starting at the given node is printed
   */
  void print(const std::string &str) const;

  /* wordCount
   * Returns a count all the nodes in the sub-Trie that end a word.
   * pre: node exists
   * post: size_t value returned
   */
  size_t wordCount() const;
};

#endif // PA10_TRIENODE_H
