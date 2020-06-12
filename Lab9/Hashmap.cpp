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
    unsigned int location = hash(key);
    Node *node = new Node();
    node->key = key;
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    if (buckets[location] == NULL) {
        ++mapSize;
        buckets[location] = node;
    } else {
        if (contains(key)) {
            Node *find = buckets[location];
            while (find->key != key) {
                find = find->next;
            }
            find->value = value;
            delete node;
            node = NULL;
        } else {
            Node *find = buckets[location];
            while (find->next != NULL) {
                find = find->next;
            }
            node->prev = find;
            find->next = node;
            ++mapSize;
        }
    }
};

bool Hashmap::contains(string key) const {
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
    int location = hash(key);
    Node* find = buckets[location];
    if (buckets[location] != NULL) {
        while (find->key != key) {
            if (find->next == NULL) {
                throw std::invalid_argument("key");
            }
            find = find->next;
        }
    } else {
        throw std::invalid_argument("key");
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
    unsigned int location = hash(key);
    Node* find = buckets[location];
    if (contains(key)) {
        while (find->key != key) {
            find = find->next;
        }
        Node *prev = find->prev;
        Node* next = find->next;
        if (prev == NULL) {
            buckets[location] = next;
        } else {
            prev->next = next;
        }
        if (next != NULL) {
            next->prev = prev;
        }
        delete find;
        find = NULL;
        // if (find->key != key) {
        //     while (find->key != key) {
        //         if (find->next == NULL) {
        //             return false;
        //         }
        //         find = find->next;
        //     }
        //     Node *toDelete = find->next;
        //     find->next = toDelete->next;
        //     delete toDelete;
        //     toDelete = NULL;
        // } else {
        //     buckets[location] = find->next;
        //     find->next->prev = NULL;
        //     delete find;
        //     find = NULL;
        // }
        --mapSize;
        return true;
    } else {
        return false;
    }
};

void Hashmap::clear() {
    for (unsigned int i = 0; i < BUCKETS; ++i) {
        while (buckets[i] != NULL) {
            remove(buckets[i]->key);
        }
    //     if (buckets[i] != NULL) {
    //         Node *find = buckets[i];
    //         Node *temp = NULL;
    //         while (find->next != NULL) {
    //             temp = find;
    //             find = temp->next;
    //             remove(temp->key);
    //             temp = NULL;
    //         }
    //         remove(find->key);
    //     }
    //     buckets[i] = NULL;
    }
    mapSize = 0;
};

string Hashmap::toString() const {
    return "";
};

int Hashmap::size() const {
    return mapSize;
};

string Hashmap::toSortedString() const {
    stringstream ss;
    priority_queue<Node *, vector<Node *>, NodeCompare> nodeHeap;
    for (int i = 0; i < BUCKETS; i++) {
        // Iterate through each bucket. Use nodeHeap.push to push all Node* onto heap.
        Node* add = buckets[i];
        while (add != NULL) {
            nodeHeap.push(add);
            add = add->next;
        }
    }
    while (!nodeHeap.empty()) {
        Node *top = nodeHeap.top();
        ss << top->key << " => " << top->value << endl;
        nodeHeap.pop();                                 
    }
    return ss.str();
};