#include "QS.h"

void QS::sortAll() {
    int q = medianOfThree(0, position);
    partition(0, position, q);
};

int QS::medianOfThree(int first, int last) {
    int middle = (first + last) / 2;
    int front = qsArray[first];
    int median = qsArray[middle];
    int back = qsArray[last];
    if (size == 0 || first + last < 2) {
        return -1;
    }
    if (median < front) {
        int holder = qsArray[middle];
        qsArray[middle] = qsArray[first];
        qsArray[first] = holder;
        front = median;
        median = qsArray[middle];
    }
    if (back < front) {
        int holder = qsArray[last];
        qsArray[last] = qsArray[first];
        qsArray[first] = holder;
        back = front;
        front = holder;
    }
    if (median > back) {
        int holder = qsArray[last];
        qsArray[last] = median;
        qsArray[middle] = holder;
        back = median;
        median = holder;
    }
    return middle;
};

int QS::partition(int first, int last, int pivotIndex) {
    int up = first + 1;
    int down = last - 1;
    if (qsArray == NULL || (pivotIndex > last || pivotIndex < first) || (first < 0 || last > size -1 || first > last)) {
        return -1;
    }
    while (1) {
        do {
            --down;
        } while (qsArray[down] > qsArray[pivotIndex]);
        do {
            ++up;
        } while (qsArray[up] < qsArray[pivotIndex]);
        if (up < down) {
            int holder = qsArray[up];
            qsArray[up] = qsArray[down];
            qsArray[down] = holder;
        }
    };
    return 1;
};

string QS::getArray() const {
    string arrayContents;
    if (qsArray == NULL || position == 0) {
        return "";
    }
    for (int i = 0; i < position; ++i) {
        if (i < position - 1) {
            arrayContents += (to_string(qsArray[i]) + ",");
        } else {
            arrayContents += to_string(qsArray[i]);
        }
    }
    return arrayContents;
};

int QS::getSize() const {
    return position;
};

bool QS::addToArray(int value) {
    if (position < size) {
        qsArray[position] = value;
        ++position;
        return true;
    } else {
        return false;
    }
};

bool QS::createArray(int capacity) {
    if (!isAvail) {
        isAvail = true;
        size = capacity;
        qsArray = new int[capacity];
        return true;
    }
    clear();
    createArray(capacity);
    return true;
};

void QS::clear() {
    int* ptr = qsArray;
    delete[] ptr;
    isAvail = false;
    qsArray = NULL;
    size = 0;
    position = 0;
};