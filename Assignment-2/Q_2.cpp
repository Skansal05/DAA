#include <iostream>
using namespace std;

int findPlatforms(int at[], int dt[], int n) {
    sort(at, at+n);
    sort(dt, dt+n);

    int plat = 1, maxPlat = 1;
    int i = 1, j = 0;

    while (i < n && j < n) {
        if (at[i] <= dt[j]) {
            plat++;
            i++;
        } else {
            plat--;
            j++;
        }
        maxPlat = max(maxPlat, plat);
    }
    return maxPlat;
}

int main() {
    int at[] = {900, 910, 920, 1100, 1120};
    int dt[] = {940, 1200, 950, 1130, 1140};
    int n = 5;

    cout << "Minimum platforms = " << findPlatforms(at, dt, n);
}