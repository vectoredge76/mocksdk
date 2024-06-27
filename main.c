#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 256

// TrieNode structure
typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    struct TrieNode *fail;
    char **output;
    int output_size;
    int output_capacity;
} TrieNode;

// AhoCorasick structure
typedef struct {
    TrieNode *root;
} AhoCorasick;

// Create a new TrieNode
TrieNode* createTrieNode() {
    TrieNode *node = (TrieNode*)malloc(sizeof(TrieNode));
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        node->children[i] = NULL;
    }
    node->fail = NULL;
    node->output = NULL;
    node->output_size = 0;
    node->output_capacity = 0;
    return node;
}

// Initialize AhoCorasick
void initAhoCorasick(AhoCorasick *ac) {
    ac->root = createTrieNode();
}

// Resize output list of a TrieNode
void resizeOutput(TrieNode *node) {
    if (node->output_capacity == 0) {
        node->output_capacity = 4;
        node->output = (char**)malloc(node->output_capacity * sizeof(char*));
    } else {
        node->output_capacity *= 2;
        node->output = (char**)realloc(node->output, node->output_capacity * sizeof(char*));
    }
}

// Insert pattern into Trie
void insertPattern(AhoCorasick *ac, const char *pattern) {
    TrieNode *node = ac->root;
    while (*pattern) {
        unsigned char index = (unsigned char)*pattern;
        if (!node->children[index]) {
            node->children[index] = createTrieNode();
        }
        node = node->children[index];
        pattern++;
    }
    if (node->output_size == node->output_capacity) {
        resizeOutput(node);
    }
    node->output[node->output_size] = strdup(pattern);
    node->output_size++;
}

// Build failure links
void buildFailureLinks(AhoCorasick *ac) {
    TrieNode *root = ac->root;
    TrieNode **queue = (TrieNode**)malloc(ALPHABET_SIZE * sizeof(TrieNode*));
    int front = 0, rear = 0;

    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (root->children[i]) {
            root->children[i]->fail = root;
            queue[rear++] = root->children[i];
        }
    }

    while (front < rear) {
        TrieNode *current_node = queue[front++];
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            TrieNode *next_node = current_node->children[i];
            if (next_node) {
                TrieNode *fail_node = current_node->fail;
                while (fail_node && !fail_node->children[i]) {
                    fail_node = fail_node->fail;
                }
                if (fail_node) {
                    next_node->fail = fail_node->children[i];
                } else {
                    next_node->fail = root;
                }
                if (next_node->fail) {
                    for (int j = 0; j < next_node->fail->output_size; ++j) {
                        if (next_node->output_size == next_node->output_capacity) {
                            resizeOutput(next_node);
                        }
                        next_node->output[next_node->output_size++] = strdup(next_node->fail->output[j]);
                    }
                }
                queue[rear++] = next_node;
            }
        }
    }
    free(queue);
}

// Search for patterns in text
void searchPatterns(AhoCorasick *ac, const char *text) {
    TrieNode *node = ac->root;
    const char *text_start = text;  // Remember the start of the text for position calculation

    while (*text) {
        unsigned char index = (unsigned char)*text;
        while (node && !node->children[index]) {
            node = node->fail;
        }
        if (node) {
            node = node->children[index];
        } else {
            node = ac->root;
        }
        if (node) {
            for (int i = 0; i < node->output_size; ++i) {
                printf("Pattern '%s' found at position %ld\n", node->output[i], text - text_start - strlen(node->output[i]) + 1);
            }
        }
        text++;
    }
}

// Free the Trie
void freeTrie(TrieNode *node) {
    if (!node) return;
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (node->children[i]) {
            freeTrie(node->children[i]);
        }
    }
    for (int i = 0; i < node->output_size; ++i) {
        free(node->output[i]);
    }
    free(node->output);
    free(node);
}

// Free AhoCorasick
void freeAhoCorasick(AhoCorasick *ac) {
    freeTrie(ac->root);
}

// Main function for testing
int main() {
    AhoCorasick ac;
    initAhoCorasick(&ac);

    const char *patterns[] = {"he", "she", "his", "her"};
    for (int i = 0; i < 4; ++i) {
        insertPattern(&ac, patterns[i]);
    }

    buildFailureLinks(&ac);

    const char *text = "ahishers";
    searchPatterns(&ac, text);

    freeAhoCorasick(&ac);

    return 0;
}
