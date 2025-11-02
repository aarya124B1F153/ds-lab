#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "How many temperature readings do you want to enter? ";
    cin >> n;

    float temps[100];
    cout << "Provide the " << n << " temperatures below:\n";
    for (int i = 0; i < n; i++) {
        cin >> temps[i];
    }

    for (int pass = 0; pass < n - 1; pass++) {
        for (int j = 0; j < n - pass - 1; j++) {
            if (temps[j] > temps[j + 1]) {
                float temp = temps[j];
                temps[j] = temps[j + 1];
                temps[j + 1] = temp;
            }
        }
    }

    cout << "\nSorted list of temperatures:\n";
    for (int i = 0; i < n; i++) {
        cout << temps[i] << " ";
    }
    cout << "\n";

    return 0;
}
