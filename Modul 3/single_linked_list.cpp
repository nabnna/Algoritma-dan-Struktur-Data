#include "single_linked_list.h"
#include <iostream>
#include <stdexcept>

void SingleLinkedList::init() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool SingleLinkedList::is_empty() {
    return size == 0;
}

void SingleLinkedList::add_front(int val) {
    Node* newNode = new Node{val, nullptr};
    if (is_empty()) {
        head = newNode;
        tail = newNode;
        newNode->next = head;
    } else {
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
    size++;
}

void SingleLinkedList::add_back(int val) {
    Node* newNode = new Node{val, nullptr};
    if (is_empty()) {
        head = newNode;
        tail = newNode;
        newNode->next = head;
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
    size++;
}

void SingleLinkedList::add_idx(int val, int idx) {
    if (idx < 0 || idx > size) {
        throw std::out_of_range("Indeks di luar batas");
    }
    if (idx == 0) {
        add_front(val);
    } else if (idx == size) {
        add_back(val);
    } else {
        Node* newNode = new Node{val, nullptr};
        Node* temp = head;
        for (int i = 0; i < idx - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }
}

void SingleLinkedList::delete_front() {
    if (is_empty()) {
        throw std::out_of_range("Senarai kosong");
    }
    
    if (size == 1) {
        delete head;
        init();
    } else {
        Node* temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
        size--;
    }
}

void SingleLinkedList::delete_back() {
    if (is_empty()) {
        throw std::out_of_range("Senarai kosong");
    }
    
    if (size == 1) {
        delete_front();
    } else {
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = head;
        size--;
    }
}

void SingleLinkedList::delete_idx(int idx) {
    if (is_empty()) {
        throw std::out_of_range("Senarai kosong");
    }
    if (idx < 0 || idx >= size) {
        throw std::out_of_range("Indeks di luar batas");
    }
    
    if (idx == 0) {
        delete_front();
    } else if (idx == size - 1) {
        delete_back();
    } else {
        Node* temp = head;
        for (int i = 0; i < idx - 1; i++) {
            temp = temp->next;
        }
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
        size--;
    }
}

void SingleLinkedList::display() {
    if (is_empty()) return;
    
    Node* temp = head;
    do {
        std::cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    std::cout << "\n";
}

int SingleLinkedList::get(int idx) {
    if (is_empty()) {
        throw std::out_of_range("Senarai kosong");
    }
    if (idx < 0 || idx >= size) {
        throw std::out_of_range("Indeks di luar batas");
    }
    Node* temp = head;
    for (int i = 0; i < idx; i++) {
        temp = temp->next;
    }
    return temp->data;
}

void SingleLinkedList::set(int val, int idx) {
    if (is_empty()) {
        throw std::out_of_range("Senarai kosong");
    }
    if (idx < 0 || idx >= size) {
        throw std::out_of_range("Indeks di luar batas");
    }
    Node* temp = head;
    for (int i = 0; i < idx; i++) {
        temp = temp->next;
    }
    temp->data = val;
}

void SingleLinkedList::clear() {
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