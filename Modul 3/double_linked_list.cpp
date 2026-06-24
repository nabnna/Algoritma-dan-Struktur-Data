#include "double_linked_list.h"
#include <iostream>

void DoubleLinkedList::init() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool DoubleLinkedList::is_empty() {
    return size == 0;
}

void DoubleLinkedList::add_front(char val) {
    Node* newNode = new Node{val, nullptr, nullptr};
    if (is_empty()) {
        head = tail = newNode;
        head->next = head;
        head->prev = head;
    } else {
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
    }
    size++;
}

void DoubleLinkedList::add_back(char val) {
    Node* newNode = new Node{val, nullptr, nullptr};
    if (is_empty()) {
        head = tail = newNode;
        head->next = head;
        head->prev = head;
    } else {
        newNode->prev = tail;
        newNode->next = head;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }
    size++;
}

void DoubleLinkedList::add_idx(char val, int idx) {
    if (idx < 0 || idx > size) {
        std::cout << "Indeks di luar batas!\n";
        return;
    }
    if (idx == 0) {
        add_front(val);
    } else if (idx == size) {
        add_back(val);
    } else {
        Node* newNode = new Node{val, nullptr, nullptr};
        Node* curr = head;
        for (int i = 0; i < idx; i++) {
            curr = curr->next;
        }
        newNode->prev = curr->prev;
        newNode->next = curr;
        curr->prev->next = newNode;
        curr->prev = newNode;
        size++;
    }
}

void DoubleLinkedList::delete_front() {
    if (is_empty()) return;
    
    Node* temp = head;
    if (size == 1) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = tail;
        tail->next = head;
    }
    delete temp;
    size--;
}

void DoubleLinkedList::delete_back() {
    if (is_empty()) return;

    Node* temp = tail;
    if (size == 1) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
    }
    delete temp;
    size--;
}

void DoubleLinkedList::delete_idx(int idx) {
    if (idx < 0 || idx >= size || is_empty()) {
        std::cout << "Indeks tidak valid!\n";
        return;
    }
    if (idx == 0) {
        delete_front();
    } else if (idx == size - 1) {
        delete_back();
    } else {
        Node* curr = head;
        for (int i = 0; i < idx; i++) {
            curr = curr->next;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        size--;
    }
}

void DoubleLinkedList::display() {
    if (is_empty()) {
        std::cout << "List kosong.\n";
        return;
    }
    Node* curr = head;
    do {
        std::cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    std::cout << "\n";
}

char DoubleLinkedList::get(int idx) {
    if (idx < 0 || idx >= size || is_empty()) {
        return '\0';
    }
    Node* curr = head;
    for (int i = 0; i < idx; i++) {
        curr = curr->next;
    }
    return curr->data;
}

void DoubleLinkedList::set(char val, int idx) {
    if (idx < 0 || idx >= size || is_empty()) {
        return;
    }
    Node* curr = head;
    for (int i = 0; i < idx; i++) {
        curr = curr->next;
    }
    curr->data = val;
}

void DoubleLinkedList::clear() {
    if (is_empty()) return;
    
    tail->next = nullptr; 
    
    Node* curr = head;
    while (curr != nullptr) {
        Node* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    
    init();
}