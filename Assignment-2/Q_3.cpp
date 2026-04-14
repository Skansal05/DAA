#include <iostream>
using namespace std;

struct Item {
    int value, weight;
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

int main() {
    int W = 50;
    Item arr[] = {{100,20}, {60,10}, {120,40}};
    int n = 3;

    sort(arr, arr+n, compare);

    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (W >= arr[i].weight) {
            totalValue += arr[i].value;
            W -= arr[i].weight;
        } else {
            totalValue += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }

    cout << "Maximum value = " << totalValue;
}