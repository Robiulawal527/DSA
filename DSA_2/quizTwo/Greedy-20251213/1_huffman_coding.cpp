#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct HuffmanNode
{
    char ch;
    int freq;
    HuffmanNode *left;
    HuffmanNode *right;

    // NOTE: yes dont be surprised to see a constructor in a struct in C++. it supports oop
    HuffmanNode(char ch, int freq)
    {
        this->ch = ch;
        this->freq = freq;
        this->left = this->right = nullptr;
    }

    HuffmanNode(int freq, HuffmanNode *leftChild, HuffmanNode *rightChild) // for nodes that are internal
    {
        this->ch = '\0';
        this->freq = freq;
        this->left = leftChild;
        this->right = rightChild;
    }

    bool isLeaf() // see if this is a leaf node or not
    {
        return left == nullptr && right == nullptr;
    }
};

struct CompareNodesComparator // comparator for the priority queue. this forms a min-heap based on freq
{
    bool operator()(HuffmanNode *a, HuffmanNode *b)
    {
        return a->freq > b->freq; // lower freq means higher priority
    }
};

// function to build out the huffman tree and return the root
// you might see it different from other algos in the internet, but feel free to use whatever easier cod e works for you
HuffmanNode *buildHuffmanTree(map<char, int> &freqs)
{
    // we need to create a min heap for the nodes
    priority_queue<HuffmanNode *, vector<HuffmanNode *>, CompareNodesComparator> minHeap;

    // first make leaf nodes for each character and add to heap
    for (auto &pair : freqs)
    {
        minHeap.push(new HuffmanNode(pair.first, pair.second));
    }

    // handle the case of only one unique character
    if (minHeap.size() == 1)
    {
        HuffmanNode *only = minHeap.top();
        minHeap.pop();
        // this is why we make a dummy parent so the single character gets a code
        return new HuffmanNode(only->freq, only, nullptr);
    }

    // this is where the greedy algo happens -> repeatedly combine two smallest nodes
    while (minHeap.size() > 1)
    {
        // first e extrac the two nodes with lowest freq
        HuffmanNode *left = minHeap.top();
        minHeap.pop();

        HuffmanNode *right = minHeap.top();
        minHeap.pop();

        // then create a new internal node with these as children. itts freq is the sum of childrens freqs
        int combinedFreq = left->freq + right->freq;
        HuffmanNode *parent = new HuffmanNode(combinedFreq, left, right);

        // push new node back into the heap
        minHeap.push(parent);
    }

    // and the last remaining node after algo runs is the root
    return minHeap.top();
}

// NOTE: BE SURE TO CLEAN UP MEMORY BY DELETING THE TREE
void deleteTree(HuffmanNode *root)
{
    if (root == nullptr)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// util func to encode a string using the generated codes
string encode(const string &text, map<char, string> &codes)
{
    string encoded = "";
    for (char c : text)
    {
        encoded += codes[c];
    }
    return encoded;
}

// util func to decode a binary string using the Huffman tree
string decode(const string &encoded, HuffmanNode *root)
{
    string decoded = "";
    HuffmanNode *current = root;

    for (char bit : encoded)
    {
        if (bit == '0')
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }

        // if reached a leaf -> decoded a character
        if (current->isLeaf())
        {
            decoded += current->ch;
            current = root; // reset to root for next character
        }
    }

    return decoded;
}

// utility function to generate codes by traversing the tree
void generateCodes(HuffmanNode *root, string currentCode, map<char, string> &codes)
{
    if (root == nullptr)
    {
        return;
    }

    // weve reached a leaf so store the code
    if (root->isLeaf())
    {
        // NOTE: PLEASE ENSURE TO HANDLE THE SINGLE CHARACTER EDGE CASE
        codes[root->ch] = currentCode.empty() ? "0" : currentCode;
        return;
    }

    // go left (add '0') and then go right (add '1')
    generateCodes(root->left, currentCode + "0", codes);
    generateCodes(root->right, currentCode + "1", codes);
}

// utli func to print the huffman codes
void printCodes(map<char, string> &codes)
{
    cout << "Huffman Codes:\n";
    cout << "==============\n";
    for (auto &pair : codes)
    {
        if (pair.first == ' ')
        {
            cout << "' ' : " << pair.second << "\n";
        }
        else if (pair.first == '\n')
        {
            cout << "'\\n': " << pair.second << "\n";
        }
        else
        {
            cout << " " << pair.first << "  : " << pair.second << "\n";
        }
    }
    cout << "==============\n";
}

int main()
{
    string text = "banana";

    cout << "original text: \"" << text << "\"\n";
    cout << "original size: " << text.length() * 8 << " bits (8 bits per char)\n\n";

    // always create the hashmap of freq count chars
    map<char, int> freqs;
    for (char c : text)
    {
        freqs[c]++;
    }

    cout << "character freqs:\n";
    for (auto &pair : freqs)
    {
        if (pair.first == ' ')
        {
            cout << "' ' : " << pair.second << "\n";
        }
        else
        {
            cout << " " << pair.first << "  : " << pair.second << "\n";
        }
    }
    cout << "\n";

    // build the huffman tree
    HuffmanNode *root = buildHuffmanTree(freqs);

    // generate codes from the tree
    map<char, string> codes;
    generateCodes(root, "", codes);
    printCodes(codes);

    // encode the original text
    string encoded = encode(text, codes);
    cout << "encoded: " << encoded << "\n";
    cout << "encoded size: " << encoded.length() << " bits\n";
    cout << "compression ratio: " << (1.0 - (double)encoded.length() / (text.length() * 8)) * 100 << "%\n\n";

    // decode back to check
    string decoded = decode(encoded, root);
    cout << "decoded: \"" << decoded << "\"\n";
    cout << "decoding " << (decoded == text ? "successful!" : "failed!") << "\n";

    // remove friom mem
    deleteTree(root);

    return 0;
}