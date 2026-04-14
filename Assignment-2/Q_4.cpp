#include <iostream>
using namespace std;

struct Job {
    char id;
    int deadline, profit;
};

bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int main() {
    Job arr[] = {
        {'J1',2,100},
        {'J2',1,19},
        {'J3',2,27},
        {'J4',1,25},
        {'J5',3,15}
    };

    int n = 5;
    sort(arr, arr+n, compare);

    int maxDeadline = 3;
    vector<char> result(maxDeadline+1, '-');

    int profit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = arr[i].deadline; j > 0; j--) {
            if (result[j] == '-') {
                result[j] = arr[i].id;
                profit += arr[i].profit;
                break;
            }
        }
    }

    cout << "Selected Jobs: ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (result[i] != '-') cout << result[i] << " ";
    }

    cout << "\nMax Profit = " << profit;
}