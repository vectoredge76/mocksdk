#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define ALPHABET_SIZE 256

class TrieNode {
public:
    TrieNode* children[ALPHABET_SIZE];
    TrieNode* fail;
    std::vector<std::string> output;

    TrieNode() {
        std::fill(children, children + ALPHABET_SIZE, nullptr);
        fail = nullptr;
    }
};

class AhoCorasick {
public:
    TrieNode* root;

    AhoCorasick() {
        root = new TrieNode();
    }

    ~AhoCorasick() {
        freeTrie(root);
    }

    void insertPattern(const std::string& pattern) {
        TrieNode* node = root;
        for (char c : pattern) {
            unsigned char index = (unsigned char)c;
            if (!node->children[index]) {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->output.push_back(pattern);
    }

    void buildFailureLinks() {
        std::queue<TrieNode*> q;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (root->children[i]) {
                root->children[i]->fail = root;
                q.push(root->children[i]);
            }
        }

        while (!q.empty()) {
            TrieNode* current_node = q.front();
            q.pop();
            for (int i = 0; i < ALPHABET_SIZE; ++i) {
                TrieNode* next_node = current_node->children[i];
                if (next_node) {
                    TrieNode* fail_node = current_node->fail;
                    while (fail_node && !fail_node->children[i]) {
                        fail_node = fail_node->fail;
                    }
                    if (fail_node) {
                        next_node->fail = fail_node->children[i];
                    } else {
                        next_node->fail = root;
                    }
                    next_node->output.insert(next_node->output.end(),
                                             next_node->fail->output.begin(),
                                             next_node->fail->output.end());
                    q.push(next_node);
                }
            }
        }
    }

    void searchPatterns(const std::string& text) {
        TrieNode* node = root;

        for (size_t pos = 0; pos < text.size(); ++pos) {
            unsigned char index = (unsigned char)text[pos];
            while (node && !node->children[index]) {
                node = node->fail;
            }
            if (node) {
                node = node->children[index];
            } else {
                node = root;
            }
            if (node) {
                for (const auto& pattern : node->output) {
                    std::cout << "Pattern '" << pattern << "' found at position "
                              << pos - pattern.size() + 1 << std::endl;
                }
            }
        }
    }

private:
    void freeTrie(TrieNode* node) {
        if (!node) return;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (node->children[i]) {
                freeTrie(node->children[i]);
            }
        }
        delete node;
    }
};

// Main function for testing
int main() {
    AhoCorasick ac;

    std::vector<std::string> patterns = {"he", "she", "his", "her"};
    for (const auto& pattern : patterns) {
        ac.insertPattern(pattern);
    }

    ac.buildFailureLinks();

    std::string text = "ahishers";
    ac.searchPatterns(text);

    return 0;
}
