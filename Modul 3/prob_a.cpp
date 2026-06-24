#include <iostream>
#include "single_linked_list.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    long long K;
    
    if (!(cin >> N >> K)) return 0;

    long long K_awal = K;
    SingleLinkedList list;
    list.init();

    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        list.add_back(val);
    }

    if (list.is_empty()) return 0;

    Node* curr = list.head;
    Node* prev = list.tail;

    while (list.size > 1) {
        long long steps = (K - 1) % list.size;
        if (steps < 0) steps += list.size; 

        for (long long i = 0; i < steps; ++i) {
            prev = curr;
            curr = curr->next;
        }

        int val = curr->data;

        if (val % 2 == 0) {
            K++;
        } else {
            K--;
        }

        if (K <= 0) {
            K = K_awal;
        }

        prev->next = curr->next;
        if (curr == list.head) list.head = curr->next;
        if (curr == list.tail) list.tail = prev;

        Node* temp = curr;
        curr = curr->next; 
        
        delete temp;
        list.size--;
    }

    cout << list.head->data << "\n";

    list.clear();

    return 0;
}