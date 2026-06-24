#include <iostream>
#include "double_linked_list.h" 

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r;
    if (!(cin >> n >> r)) return 0;

    DoubleLinkedList dll;
    dll.init();

    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        dll.add_back(c);
    }

    Node* alpha = dll.head;
    Node* beta = dll.tail;

    for (int i = 0; i < r; i++) {
        long long x, y;
        cin >> x >> y;

        if (dll.size == 0) break;

        long long move_alpha = x % dll.size;
        for (long long j = 0; j < move_alpha; j++) alpha = alpha->next;

        long long move_beta = y % dll.size;
        for (long long j = 0; j < move_beta; j++) beta = beta->prev;

        if (alpha == beta) {
            Node* next_alpha = alpha->next;
            Node* prev_beta = beta->prev;

            if (dll.size == 1) {
                delete alpha;
                dll.init();
                break;
            } else {
                if (alpha == dll.head) dll.head = alpha->next;
                if (alpha == dll.tail) dll.tail = alpha->prev;

                alpha->prev->next = alpha->next;
                alpha->next->prev = alpha->prev;
                
                delete alpha;
                dll.size--;

                alpha = next_alpha;
                beta = prev_beta;
            }
        } else {
            bool linear_adj = false;
            
            if (alpha->next == beta && alpha != dll.tail) linear_adj = true;
            if (beta->next == alpha && beta != dll.tail) linear_adj = true;

            if (dll.size > 1 && linear_adj) {
                char temp_data = alpha->data;
                alpha->data = beta->data;
                beta->data = temp_data;
            }
        }
    }

    if (dll.size == 0) {
        cout << "EMPTY\n";
    } else {
        Node* curr = dll.head;
        for (int i = 0; i < dll.size; i++) {
            cout << curr->data;
            curr = curr->next;
        }
        cout << "\n";
    }

    dll.clear();
    return 0;
}