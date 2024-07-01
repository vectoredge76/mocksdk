#include <iostream>
#include <vector>
#include <queue>
#include <string>

struct TrieNode {
	public:
		TrieNode* children; // 26 possible states for each red
		TrieNode* parent; // the parent of each state and where it came from
		TrieNode* fail; // the pointer to a failure link from every node
		std::vector<int> output; // output for the end of words on the node
		char value;
		TrieNode(char ch);
};
