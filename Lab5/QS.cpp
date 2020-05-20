#include "QS.h"

void QS::sortAll() {
    if (qsArray == NULL || position == 0 || size < 2) {
        return;
    }
    quickSort(0, position-1);
};

void QS::quickSort(int first, int last) {
    //if (last == first || last - first < 2) { return; }
    if (last - first > 1) { 
        cout << "first input " << first << " " << last << endl;
        int pivot = medianOfThree(first, last);
        cout << "Before Partition " << first << " " << last << " " << pivot << " " << endl;
        pivot = partition(first, last, pivot);
        //if (pivot = -1) { return; }
        cout << "After Partition " << first << " " << last << " " << pivot << " " << endl;
        //if ()
        quickSort(first, pivot-1);
        quickSort(pivot+1, last);
        for (int i = 1; i < position-1; ++i) {
            if (qsArray[i] < qsArray[i-1]) {
                swapEm(i, (i-1));
            }
        }
    }
}

int QS::medianOfThree(int first, int last) {
    int middle = (first + last) / 2;
    if (position == 0 || (first + last) < 2 || qsArray == NULL || size == 0 || position <= last || first < 0 || first >= last) {
        cout << first << " " << last << " " << position << " " << size << endl;
        return -1;
    }
    if (qsArray[middle] < qsArray[first]) {
        swapEm(first, middle);
    }
    if (qsArray[last] < qsArray[first]) {
        swapEm(first, last);
    }
    if (qsArray[middle] > qsArray[last]) {
        swapEm(middle, last);
    }
    return middle;
};

int QS::partition(int first, int last, int pivotIndex) {
    if (qsArray == NULL || (pivotIndex > last || pivotIndex < first) || (first < 0 || last > size -1 || first > last) || position == 0 || first >= last) {
        return -1;
    }
    cout << getArray() << endl;
    swapEm(first, pivotIndex);
    int pivot = qsArray[first];
    int up = first + 1;
    int down = last;
    do {
         while (qsArray[up] <= pivot && up != last) {
            ++up;
        }
        while (qsArray[down] > pivot && down != first) {
            --down;
        }
        if (qsArray[up] < qsArray[down] || up < down) {
            swapEm(up, down);
        }
    } while (up < down);
    cout << getArray() << endl;
    swapEm(first, down);
    cout << getArray() << endl;
    return down;
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
    } else {
        clear();
        createArray(capacity);
        return true;
    }
    return false;
};

void QS::clear() {
    int* ptr = qsArray;
    delete[] ptr;
    isAvail = false;
    qsArray = NULL;
    size = 0;
    position = 0;
};

void QS::swapEm(int pos1, int pos2) {
    int holder = qsArray[pos1];
    qsArray[pos1] = qsArray[pos2];
    qsArray[pos2] = holder;
}