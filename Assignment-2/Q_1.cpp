#include <iostream>
using namespace std;

struct Activity {
    int start, finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n = 6;
    Activity arr[] = {{1,2}, {3,4}, {0,6}, {5,7}, {8,9}, {5,9}};

    sort(arr, arr+n, compare);

    cout << "Selected activities:\n";
    int i = 0;
    cout << "(" << arr[i].start << ", " << arr[i].finish << ") ";

    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            cout << "(" << arr[j].start << ", " << arr[j].finish << ") ";
            i = j;
        }
    }
}