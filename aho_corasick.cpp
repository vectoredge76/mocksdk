#include <iostream>
#include <vector>
#include <queue>
#include <string>


const int MAX_CHARS = 26;

// trieNode struct needed to build Trie
struct TrieNode {
public:
    TrieNode* children[MAX_CHARS]; // 26 possible states for each red
    TrieNode* parent; // the parent of each state and where it came from
    TrieNode* fail; // the pointer to a failure link from every node
    std::vector<int> output; // output for the end of words on the node
    char value;

	// constructor of the node
    TrieNode(char ch = '\0') {
		// filling node with empty default values
		parent = nullptr;
		fail = nullptr;
		value = ch;
		// setting all possible states from node null
        for (int i = 0; i < MAX_CHARS; i++) children[i] = nullptr;
    }
};

// logic for Aho-Corasick
// 1. building a trie from all the words
// 2. creating failure links from each of the nodes
// 3. traversing through the trie to find all possible words created
struct AhoCorasick {
private:
    TrieNode* root;

	// converting character to a relative index (max 26 because alpha)
    int charToIndex(char ch) {
        return ch - 'a';
    }

public:
    AhoCorasick() {
        root = new TrieNode();
    }

	// step 1: populating trie
    void insert(const std::string& word, int index) {
        TrieNode* node = root;
		// for each character in the word
        for (char ch : word) {
            int idx = charToIndex(ch);
			// if no edge exists create one and point to the indexed character
            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode(ch);
                node->children[idx]->parent = node; // update parent to follow
            }
			// traverse down to the new child
            node = node->children[idx];
        }
		// push that pointer (node) into the possible outputs to represent the end of a word 
        node->output.push_back(index);
    }

	// step 2: building failure links from every mismatch down the trie
    void buildFailureLinks() {
		// creating a queue (for BFS)
        std::queue<TrieNode*> q;
		// a link from root to itself because there are no previous states (suffixes)
        root->fail = root;

		// failure links of root
        for (int i = 0; i < MAX_CHARS; i++) {
			// if a child exists, set it's failure link to the root and push into the queue
            if (root->children[i]) {
                root->children[i]->fail = root;
                q.push(root->children[i]);
            }
			// otherwise make the child (potential state) point back to root
            else {
                root->children[i] = root;
            }
        }

		// take every state on the trie
        while (!q.empty()) {
            TrieNode* current = q.front();
            q.pop();

			// repeating the process but this time the mismatch case exists
            for (int i = 0; i < MAX_CHARS; i++) {
                if (current->children[i]) {
                    TrieNode* failNode = current->fail;
					// while a failure link does not exist, keep pointing it to the prefix (longest suffix)
                    while (failNode->children[i] == nullptr && failNode != root)
                        failNode = failNode->fail;
					// when one has been found, set it to point to where the failure link of the child is pointing
                    current->children[i]->fail = failNode->children[i];
                    current->children[i]->output.insert(current->children[i]->output.end(), current->children[i]->fail->output.begin(), current->children[i]->fail->output.end()); // updating output with the fail links and their end for algorithm to traverse during mismatch
					// pushing children to the queue (part of BFS)
                    q.push(current->children[i]);
                }
            }
        }
    }


	// step 3: traverse through the trie to find all possible words
    std::vector<std::pair<int, int>> search(const std::string& text) {
        TrieNode* node = root;
		// the results vector is a pair of the position in text and the indices of the patterns
        std::vector<std::pair<int, int>> results;

        for (int i = 0; i < text.size(); i++) {
            int idx = charToIndex(text[i]);
			// while no next state is found, update the failure link until right before the next state is found
            while (node->children[idx] == nullptr)
                node = node->fail;
			// set node to next state
            node = node->children[idx];
			// if there is a word ending at the current state, we find it and update the results
            if (!node->output.empty()) {
				// trying to traverse through the output array to find the word
                for (int patternIndex : node->output) {
                    results.emplace_back(i, patternIndex); // adding the position and the second is the index of the exact word it has found
                }
            }
        }
        return results;
    }
};

int main() {
    AhoCorasick ahoCorasick;

	std::vector< std::string > patterns = {"and", "ant", "do", "geek", "dad", "ball"};
	std::string text = "";

    for (int i = 0; i < patterns.size(); i++) {
        ahoCorasick.insert(patterns[i], i);
    }

    ahoCorasick.buildFailureLinks();
    std::vector<std::pair<int, int>> results = ahoCorasick.search(text);

    for (auto& result : results) {
        std::cout << "Pattern found at index " << result.first - patterns[result.second].size() + 1
                  << " for pattern \"" << patterns[result.second] << "\"" << std::endl;
    }

    return 0;
}
