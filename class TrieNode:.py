# Definition of a TrieNode, which is a single node in the Trie structure
class TrieNode:
    def __init__(self):
        self.children = {}  # Dictionary to hold child nodes, where keys are characters
        self.is_end_of_word = False  # Boolean flag to mark the end of a word

# Definition of the Trie data structure
class Trie:
    def __init__(self):
        self.root = TrieNode()  # Initialize the Trie with a root TrieNode

    # Method to insert a word into the Trie
    def insert(self, word):
        node = self.root  # Start from the root node
        for char in word:  # Iterate through each character in the word
            if char not in node.children:  # If the character is not in the current node's children
                node.children[char] = TrieNode()  # Create a new TrieNode and add it to the children
            node = node.children[char]  # Move to the child node
        node.is_end_of_word = True  # After inserting all characters, mark the last node as the end of the word
        self.print_trie()  # Print the Trie structure on success

    # Method to search for a word in the Trie
    def search(self, word):
        node = self.root  # Start from the root node
        
        for char in word:  # Iterate through each character in the word
            if char not in node.children:  # If the character is not in the current node's children
                return False  # The word is not in the Trie
            node = node.children[char]  # Move to the child node
        self.print_trie()  # Print the Trie structure on success
        return node.is_end_of_word  # Return True if the last node is marked as the end of a word, else False

    # Method to check if any word in the Trie starts with a given prefix
    def starts_with(self, prefix):
        node = self.root  # Start from the root node
        for char in prefix:  # Iterate through each character in the prefix
            if char not in node.children:  # If the character is not in the current node's children
                return False  # No word in the Trie starts with the given prefix
            node = node.children[char]  # Move to the child node
        self.print_trie()  # Print the Trie structure on success
        return True  # If all characters in the prefix are found, return True
    
    def print_trie(self):
        def dfs(node, prefix):
            if node.is_end_of_word:
                print(f"Word: {prefix}")
            for char, next_node in node.children.items():
                dfs(next_node, prefix + char)
                
        print("Current Trie structure:")
        dfs(self.root, "")
        print("")

# Example usage of the Trie
trie = Trie()  # Create a new Trie object
trie.insert("hello")  # Insert the word "hello" into the Trie
trie.insert("world")  # Insert the word "world" into the Trie

print(trie.search("hello"))  # Output: True, because "hello" is in the Trie
print(trie.search("zar"))   

print(trie.starts_with("hell"))  # Output: True, because there is a word ("hello") that starts with "hell"
print(trie.starts_with("worlds"))  # Output: False, because no word in the Trie starts with "worlds"