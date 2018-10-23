
// Description: This class is a TrieNode, which supports the Trie class. Holds a
// letter, a boolean flag, and an array of pointers

#include "TrieNode.h"
#include <cstddef>
#include <iostream>
#include <string>

/*TriNode(char c, bool b)
 * This is the only constructor for the TrieNode class
 * post: a TrieNode is initialized with b and c, as well as an
 * array of ALPHABET nullpointers
 */
TrieNode::TrieNode(char c, bool b) : letter(c), endOfWord(b) {
  for (size_t i = 0; i < ALPHABET; i++) {
    array[i] = nullptr;
  }
}

/*TrieNode(const TrieNode& rhs)
 * Copy ctor for TrieNode
 * pre: rhs exists
 * post: a new TrieNode identical to rhs is created
 */
TrieNode::TrieNode(const TrieNode &rhs)
    : letter(rhs.letter), endOfWord(rhs.endOfWord)

{
  for (size_t i = 0; i < ALPHABET; i++) {
    if (rhs.array[i] != nullptr) {
      array[i] = new TrieNode(*rhs.array[i]);
    } else {
      array[i] = nullptr;
    }
  }
}
/*const TrieNode& operator=(const TrieNode& rhs)
 * Assignment operator
 * pre: rhs exists
 * post: The trienode that calls this assignment operator is now identical to
 * rhs, including its children
 */

const TrieNode &TrieNode::operator=(const TrieNode &rhs) {
  if (this != &rhs) {
    TrieNode tmp(rhs);
    std::swap(this->letter, tmp.letter);
    std::swap(this->endOfWord, tmp.endOfWord);
    std::swap(this->array, tmp.array);
  }
  return *this;
}

/*dtor
 * pre: The TrieNode exists
 * post: trienode is destroyed
 */
TrieNode::~TrieNode() {
  for (size_t i = 0; i < ALPHABET; i++) {
    if (array[i] != nullptr) {
      delete array[i];
    }
  }
}

/*Insert
 * Insert strstarting with the given TrieNode.
 * Create new TrieNodes as needed and sets the boolean flag on the last node to
 * true pre: node exists post: all letters below the node will reflect the word
 * passed
 */
void TrieNode::insert(const std::string &str) {
  if (str.length() == 0) {
    endOfWord = true;
    return;
  } else if (array[str[0] - 'a'] != nullptr) {
    if (str.length() == 1) {
      array[(str[0] - 'a')]->insert("");
    } else {
      array[(str[0] - 'a')]->insert(str.substr(1, str.length() - 1));
    }

  } else if (array[str[0] - 'a'] == nullptr) {
    array[str[0] - 'a'] = new TrieNode(str[0], false);
    if (str.length() == 1) {
      array[(str[0] - 'a')]->insert("");
    } else {
      array[(str[0] - 'a')]->insert(str.substr(1, str.length() - 1));
    }
  }
}

/* isWord
 * Returns true if str exists in the sub-Trie starting at the given TrieNode,
 * else returns false
 * pre: node exists
 * post: boolean value is returned
 */
bool TrieNode::isWord(const std::string &str) const {

  if (str.length() == 0 && endOfWord) {
    return true;
  } else if (str.length() == 0 && !endOfWord) {
    return false;
  } else if (array[str[0] - 'a'] == nullptr) {
    return false;
  } else {
    return array[str[0] - 'a']->isWord(str.substr(1, str.length() - 1));
  }
}

/* isPrefix
 * Returns true if pre is a prefix of a word in the sub-Trie starting at the
 * given TrieNode, else returns false pre: node exists post: boolean value is
 * returned
 */
bool TrieNode::isPrefix(const std::string &pre) const {
  if (pre.length() == 0) {
    return true;
  } else if (pre.length() == 1)
    return true;

  else if (array[pre[0] - 'a'] == nullptr) {
    return false;
  } else {
    return array[pre[0] - 'a']->isPrefix(pre.substr(1, pre.length() - 1));
  }
}

/* print
 *Prints all words starting at the given TrieNode.
 * The parameter string str stores the letters of all previous TrieNode
 * objects up to the node currently being processed.
 * pre: node exists
 * post: all words in the trie starting at the given node is printed
 */
void TrieNode::print(const std::string &str) const {
  if (endOfWord) {
    std::cout << str << std::endl;
  }
  for (size_t i = 0; i < ALPHABET; i++) {
    if (array[i] != nullptr) {
      array[i]->print(str + array[i]->letter);
    }
  }
}

/* wordCount
 * Returns a count all the nodes in the sub-Trie that end a word.
 * pre: node exists
 * post: size_t value returned
 */
size_t TrieNode::wordCount() const {
  size_t sum = 0;

  for (size_t i = 0; i < ALPHABET; i++) {
    if (array[i] != nullptr) {
      if (array[i]->endOfWord) {
        sum++;
      }
      sum += array[i]->wordCount();
    }
  }
  return sum;
}