#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int fifo(int pages[], int n, int capacity) {
    unordered_set<int> memory;
    queue<int> order;
    int faults = 0;

    for (int i = 0; i < n; i++) {
        if (memory.find(pages[i]) == memory.end()) {
            if (memory.size() == capacity) {
                memory.erase(order.front());
                order.pop();
            }
            memory.insert(pages[i]);
            order.push(pages[i]);
            faults++;
        }
    }
    return faults;
}

int predict(int pages[], vector<int>& frames, int n, int idx) {
    int farthest = idx, replace_idx = -1;

    for (int i = 0; i < frames.size(); i++) {
        int j;
        for (j = idx; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    replace_idx = i;
                }
                break;
            }
        }
        if (j == n) return i;
    }
    return (replace_idx == -1) ? 0 : replace_idx;
}

int optimal(int pages[], int n, int capacity) {
    vector<int> frames;
    int faults = 0;

    for (int i = 0; i < n; i++) {
        if (find(frames.begin(), frames.end(), pages[i]) == frames.end()) {
            if (frames.size() < capacity) {
                frames.push_back(pages[i]);
            } else {
                int j = predict(pages, frames, n, i + 1);
                frames[j] = pages[i];
            }
            faults++;
        }
    }
    return faults;
}

int lru(int pages[], int n, int capacity) {
    list<int> recent;
    unordered_map<int, list<int>::iterator> position;
    int faults = 0;

    for (int i = 0; i < n; i++) {
        if (position.find(pages[i]) == position.end()) {
            if (recent.size() == capacity) {
                int last = recent.back();
                recent.pop_back();
                position.erase(last);
            }
            faults++;
        } else {
            recent.erase(position[pages[i]]);
        }
        recent.push_front(pages[i]);
        position[pages[i]] = recent.begin();
    }
    return faults;
}

int main() {
    int pages[] = {1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
    int n = sizeof(pages) / sizeof(pages[0]);

    cout << "Page Replacement Algorithms (FIFO, OPTIMAL, LRU)\n";
    cout << "Reference: 1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6\n\n";

    cout << left << setw(12) << "Frame Size"
         << setw(15) << "FIFO"
         << setw(17) << "Optimal"
         << setw(12) << "LRU" << "\n";
    cout << "--------------------------------------------------------\n";

    for (int frame = 3; frame <= 7; frame++) {
        cout << left << setw(12) << frame
             << setw(15) << fifo(pages, n, frame)
             << setw(17) << optimal(pages, n, frame)
             << setw(12) << lru(pages, n, frame) << "\n";
    }

    return 0;
