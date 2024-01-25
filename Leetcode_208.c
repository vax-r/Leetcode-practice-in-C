typedef struct TrieNode {
    struct TrieNode *children[26];
    bool isEndOfWord;
};

struct TrieNode *createNode () {
    struct TrieNode *node = calloc(1, sizeof(struct TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i<26; i++)
        node->children[i] = NULL;
    return node;
}

typedef struct {
    struct TrieNode *root;
} Trie;


Trie* trieCreate() {
    Trie *t = calloc(1, sizeof(Trie));
    t->root = createNode();
    return t;
}

void trieInsert(Trie* obj, char* word) {
    struct TrieNode *cur = obj->root;
    for (int i=0; i < strlen(word); i++) {
        if (!cur->children[word[i] - 'a'])
            cur->children[word[i] - 'a'] = createNode();
        cur = cur->children[word[i] - 'a'];
    }
    cur->isEndOfWord = true;
}

bool trieSearch(Trie* obj, char* word) {
    struct TrieNode *cur = obj->root;
    for (int i=0; i<strlen(word); i++) {
        if (!cur->children[word[i] - 'a'])
            return false;
        cur = cur->children[word[i] - 'a'];
    }
    return cur->isEndOfWord;
}

bool trieStartsWith(Trie* obj, char* prefix) {
    struct TrieNode *cur= obj->root;
    for (int i=0; i<strlen(prefix); i++) {
        if (!cur->children[prefix[i] - 'a'])
            return false;
        cur = cur->children[prefix[i] - 'a'];
    }
    return true;
}

void trieFree(Trie* obj) {
    free(obj);
}