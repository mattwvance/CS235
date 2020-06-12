#include "Hashmap.h"


Hashmap::Hashmap() {
    for (int i = 0; i < BUCKETS; ++i) {
        buckets[i] = NULL;
    }
    mapSize = 0;
};

Hashmap::~Hashmap() {
    this->clear();
};

void Hashmap::insert(string key, int value) {
    cout << "inserting" << endl;
    unsigned int location = hash(key);
    Node *node = new Node;
    node->key = key;
    node->value = value;
    if (buckets[location] == NULL) {
        cout << mapSize << endl;
        ++mapSize;
        buckets[location] = node;
    } else {
        if (contains(key)) {
            int val = get(key);
            val += value;
        } else {
            Node *find = buckets[location];
            while (find->next != NULL) {
                find = find->next;
            }
            ++mapSize;
            find->next = node;
        }
    }
    cout <<key <<  mapSize << endl;
};

bool Hashmap::contains(string key) const {
    cout << "in contains" << endl;
    bool isThere = false;
    unsigned int location = hash(key);
    Node* find = buckets[location];
    while (find != NULL) {
        if (find->key == key) {
            isThere = true;
        }
        find = find->next;
    }
    return isThere;
};

int Hashmap::get(string key) const {
    cout << "getting stuff" << endl;
    int location = hash(key);
    Node* find = buckets[location];
    while (find->key != key) {
        cout << find->key << endl;
        find = find->next;
    }
    int val = find->value;
    return val;
};

int& Hashmap::operator [](string key) {
    // Is the key in the map?
    unsigned int bucket = hash(key);
    Node *last = NULL;
    Node *current = buckets[bucket];
    while (current != NULL && current->key != key) {
        last = current;
        current = current->next;
    }
    // If current is not NULL, then that means I found it
    if (current != NULL) {
        return current->value;
    }
    // If current is NULL, then i did not find it and I need to add it
    Node *newNode = new Node();
    mapSize++;
    newNode->key = key;
    newNode->value = 0;
    if (last == NULL) {
        // Update head pointer to point to new node
        buckets[bucket] = newNode;
        newNode->prev = NULL;
        newNode->next = NULL;
        return newNode->value;
    }
    // If there is something in this bucket, append newNode to the end
    last->next = newNode;
    newNode->prev = last;
    newNode->next = NULL;
    return newNode->value;
};

bool Hashmap::remove(string key) {
    cout << "removing" << endl;
    return true;
};

void Hashmap::clear() {
    cout << "clearing" << endl;
};

string Hashmap::toString() const {
    cout << "converting to a string" << endl;
    return "";
};

int Hashmap::size() const {
    cout << "finding size" << endl;
    return mapSize;
};

string Hashmap::toSortedString() const {
    stringstream ss;
    priority_queue<Node *, vector<Node *>, NodeCompare> nodeHeap;
    for (int i = 0; i < BUCKETS; i++) {
        // Iterate through each bucket. Use nodeHeap.push to push all Node* onto heap.
        nodeHeap.push(buckets[i]);
    }
    while (!nodeHeap.empty()) {
        Node *top = nodeHeap.top();
        ss << top->key << " => " << top->value << endl;
        nodeHeap.pop();                                 
    }
    return ss.str();
};