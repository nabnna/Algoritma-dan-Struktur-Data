#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int arr[100];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (k <= 0 || k > n) {
        cout << "Invalid k" << endl;
        return 0;
    }

    Queue q;
    init(&q);

    int sum = 0;

    for (int i = 0; i < k; i++) {
        enqueue(&q, arr[i]);
        sum += arr[i];
    }

    cout << sum;

    for (int i = k; i < n; i++) {
        sum -= front(&q);
        dequeue(&q);

        enqueue(&q, arr[i]);
        sum += arr[i];

        cout << " " << sum;
    }

    cout << endl;

    return 0;
}