#include <iostream>
#include <vector>

using namespace std;

//
class Myheap {
public:
    vector<int> arr;
    int capacity;
    int size;

    Myheap(int cap) {
        size = 0;
        capacity = cap;
        arr = vector<int>(capacity, 0);
    }

    bool empty() {
        return size == 0;
    }

    int top() {
        if (!arr.empty()) {
            return arr[1];
        }
        return -1;
    }

    void push(int num) {
        size++;
        if (size >= capacity) {
            cout << "FULL" << endl;
            return;
        }
        arr[size] = num;
        int parentIndex = size / 2;
        int curIndex = size;
        while (parentIndex != 0 && arr[curIndex] > arr[parentIndex]) {
            swap(arr[curIndex], arr[parentIndex]);
            curIndex = parentIndex;
            parentIndex = curIndex / 2;
        }
    }

    void pop() {
        if (!empty()) {
            swap(arr[size], arr[1]);
            size--;
            int curIndex = 1;
            int nextIndex = 2 * curIndex;
            while (nextIndex <= size) {
                if (nextIndex + 1 <= size && arr[nextIndex + 1] > arr[nextIndex]) {
                    nextIndex = nextIndex + 1;
                }

                if (arr[curIndex] < arr[nextIndex]) {
                    swap(arr[curIndex], arr[nextIndex]);
                }
                else {
                    break;
                }
                curIndex = nextIndex;
                nextIndex = 2 * curIndex;
            }
        }
    }

    void printArr() {
        for (int num: arr) {
            cout << num << "\t" << endl;
        }
    }
};

int main() {
    Myheap heap = Myheap(20);
    heap.push(3);
    heap.push(6);
    heap.push(5);
    heap.push(1);
    heap.push(9);
    while (!heap.empty()) {
        cout << heap.top() << endl;
        heap.pop();
    }
    return 0;
}