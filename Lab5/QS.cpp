#include "QS.h"

void QS::sortAll() {
    int q;
    if (position = 0) {
        return;
    }
    q = medianOfThree(0, position);
    partition(0, position, q);
};

int QS::medianOfThree(int first, int last) {
    int middle = (last - first) / (2 + first);
    int front = qsArray[first];
    int median = qsArray[middle];
    int back = qsArray[last-1];
    if (qsArray[0] == 0) {
        return - 1;
    }
    if (median > front && median < back || median > back && median < front) {
        int holder = qsArray[middle];
        qsArray[middle] = qsArray[first];
        qsArray[first] = holder;
        front = median;
        median = qsArray[middle];
    } else if (back > front && back < median || back > median && back < front) {
        qsArray[first] = back;
        qsArray[last] = front;
    }
    return middle;
};

int QS::partition(int first, int last, int pivotIndex) {
    int up = first + 1;
    int down = last - 1;
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
    return position;
};

bool QS::addToArray(int value) {
    if (position < size) {
        cout << "here" << endl;
        qsArray[position] = value;
        cout << "here" << endl;
        ++position;
        return true;
    } else {
        return false;
    }
};

bool QS::createArray(int capacity) {
    if (qsArray) {
        clear();
    }
    if (capacity < 0) {
        return false;
    }
    size = capacity;
    qsArray[capacity];
    return true;
};

void QS::clear() {
    fill_n(qsArray, position, 0);
    delete [] qsArray;
};