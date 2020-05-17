#include "QS.h"

QS::QS() {};
QS::~QS() {};


void QS::sortAll() {

};

int QS::medianOfThree(int first, int last) {
    int middle = (first + last) / 2;
    if (qsArray[0] == NULL) {
        return - 1;
    }
    for (int i = 0; i < size - 1; ++ i) {
        if (qsArray[i] > qsArray[i+1]) {
            int holder = qsArray[i+1];
            qsArray[i+1] = qsArray[i];
            qsArray[i] = holder;
        }
    }
};

int QS::partition(int first, int last, int pivotIndex) {
    int up = first + 1;
    int down = last - 1;
    do {


    } while (up < down);
};

string QS::getArray() const {
    string arrayContents;
    for (int i = 0; i < size; ++i) {
        if (i < size - 1) {
            arrayContents += (to_string(qsArray[i]) + ", ");
        } else {
            arrayContents += to_string(qsArray[i]);
        }
    }
    return arrayContents;
};

int QS::getSize() const {
    return size;
};

bool QS::addToArray(int value) {

};

bool QS::createArray(int capacity) {
    int newArray[capacity];
    size = capacity;
    for (int i = 0; i < capacity; ++i) {
        qsArray[i] = newArray[i];
    }
};

void QS::clear() {
    
};