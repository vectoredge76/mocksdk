#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

//hello 

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    TrieNode* failureLink = nullptr;
    vector<int> output;
};

class AhoCorasick {
public:
    AhoCorasick(const vector<string>& patterns) {
        root = new TrieNode();
        buildTrie(patterns);
        buildFailureLinks();
    }

    ~AhoCorasick() {
        deleteTrie(root);
    }

    vector<pair<int, int>> search(const string& text) {
        vector<pair<int, int>> results;
        TrieNode* currentNode = root;

        for (int i = 0; i < text.size(); ++i) {
            while (currentNode != root && currentNode->children.find(text[i]) == currentNode->children.end()) {
                currentNode = currentNode->failureLink;
            }
            if (currentNode->children.find(text[i]) != currentNode->children.end()) {
                currentNode = currentNode->children[text[i]];
            }
            for (int patternIndex : currentNode->output) {
                results.push_back({i, patternIndex});
            }
        }

        return results;
    }

private:
    TrieNode* root;

    void buildTrie(const vector<string>& patterns) {
        for (int i = 0; i < patterns.size(); ++i) {
            TrieNode* currentNode = root;
            for (char c : patterns[i]) {
                if (currentNode->children.find(c) == currentNode->children.end()) {
                    currentNode->children[c] = new TrieNode();
                }
                currentNode = currentNode->children[c];
            }
            currentNode->output.push_back(i);
        }
    }

    void buildFailureLinks() {
        queue<TrieNode*> q;
        root->failureLink = root;

        for (auto& pair : root->children) {
            pair.second->failureLink = root;
            q.push(pair.second);
        }

        while (!q.empty()) {
            TrieNode* currentNode = q.front();
            q.pop();

            for (auto& pair : currentNode->children) {
                char c = pair.first;
                TrieNode* childNode = pair.second;

                TrieNode* failureNode = currentNode->failureLink;
                while (failureNode != root && failureNode->children.find(c) == failureNode->children.end()) {
                    failureNode = failureNode->failureLink;
                }
                if (failureNode->children.find(c) != failureNode->children.end()) {
                    childNode->failureLink = failureNode->children[c];
                } else {
                    childNode->failureLink = root;
                }

                for (int patternIndex : childNode->failureLink->output) {
                    childNode->output.push_back(patternIndex);
                }

                q.push(childNode);
            }
        }
    }

    void deleteTrie(TrieNode* node) {
        for (auto& pair : node->children) {
            deleteTrie(pair.second);
        }
        delete node;
    }
};

int main() {
    vector<string> patterns = {"he", "she", "his", "hers"};
    string text = "ahishers";

    AhoCorasick ac(patterns);
    vector<pair<int, int>> results = ac.search(text);

    for (const auto& result : results) {
        cout << "Pattern found at index " << result.first - patterns[result.second].size() + 1
             << " for pattern " << patterns[result.second] << endl;
    }

    return 0;
}
