#include <stdio.h>
#include <iostream>
#include <array>
#include <string>
#include <vector>

using namespace std;

// create a struct for each node that contains:
// - an array pointer to the children of that node and
// - a boolean for if it is the end of the word (instead of inserting values at the end)
struct TrieNode {
	// array pointer to children (assuming the trie is alphabetical)
	TrieNode* children[26];
	TrieNode* parent;
	bool isWordEnd;

	// filling the children array full of nulls and ensuring that the word hasn't ended at the start
	TrieNode() {
		isWordEnd = false;
		for(int i = 0;i < 26;i++){
			children[i] = nullptr;
		}
	}
};

// implementation of the actual Tire data structure which performs:
// - insertion
// - search
// - deletion
struct Trie {
	// initializing root node
	TrieNode* root;

	// constructor of Trie
	Trie() {
		root = new TrieNode();
	}

	// logic: keep traversing through the trie and insert a node where a letter doesn't exist as a child
	void insert(const std::string& key) {
		TrieNode* current = root;
		for(char c : key) {
			int radixIndex = c - 'a'; // finding the radix index assuming trie is only alphabetical
			// if the character doesn't exist in the branch
			if(current->children[radixIndex] == nullptr) {
				// create a node at the specific index (signifying that the character c at that radix location exists)
				current->children[radixIndex] = new TrieNode();
			}
			// moving down the trie
			current = current->children[radixIndex];
		}
		// after the whole key has been processed, we update that in the node (instead of inputting a value in it)
		current->isWordEnd = true;
	}

	// logic: keep traversing through the trie and check if every character from the key exists (return false wherever it doesn't)
	bool search(const std::string& key) {
		TrieNode* current = root;
		// for each character in the key
		for (char c : key) {
			// calculate relative index
			int radixIndex = c - 'a';
			// if we ever encounter a null link, return false
			if(current->children[radixIndex] == nullptr) return false;
			// otherwise keep traversing down the trie (assuming characters are being found)
			current = current->children[radixIndex];
		}
		// if we reach the end of the key, it exists
		return current->isWordEnd;
	}

	// logic: find the end of the word, make it null, and cascade back up the tree until 
	void deleteNode(const std::string& key) {
		// do not want to meaninglessly search the tree if the word does not exist
		if(!search(key)) {
			return;
		}
		TrieNode* current = root;
		// for each character in the key (we know that the word exists at this point because we've looked for it)
		for (char c : key) {
			// calculate relative index
			int radixIndex = c - 'a';
			// otherwise keep traversing down the trie (assuming characters are being found)
			current = current->children[radixIndex];
		}
		// we have gone through the entire key loop and have reached the end of the word
		// now we need to iteratively delete all the unique characters of the word
		
	}
};

int main() {

	TrieNode* root = new TrieNode();

	Trie* trie = new Trie();
	trie->root = root;

	std::vector< std::string > words = {"and", "ant", "do", "geek", "dad", "ball"};
	std::vector< std::string > queries = {"do", "geek", "bal"};

	for(int i = 0;i < 6;i++) {
		trie->insert(words[i]);
	}

	for(int i = 0;i < 3;i++) {
		if(trie->search(queries[i])) printf("The word was found in the trie!\n");
		else {
			printf("The word has not been found in the trie!\n");
		}
	}

	trie->deleteNode("and");

	return 0;
};

