#pragma once
#include <iostream>


using namespace std;

class Node {
public:
    double elem;
    Node* next;

    Node() {
        /*default constructor*/
        elem = -1;
        next = NULL;
    };

    Node(double e) {
        /*overload constructor*/
        elem = e;
        next = NULL;
    };
};

class Weather_Out_list {
    Node* head;
    Node* tail;
    int size;
public:
    Weather_Out_list() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void insertFirst(double elem) {
        Node* temp = new Node(elem);
        if (head == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            temp->next = head;
            head = temp;
        }
        size++;
    }
    void insertLast(double elem) {
        Node* temp = new Node(elem);
        if (head == NULL) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    void insertAt(double elem, int pos) {
        if (pos <0 || pos>size)
            cout << "Invalid Index" << endl;
        else if (pos == 0) {
            insertFirst(elem);
        }
        else if (pos == size) {
            insertLast(elem);
        }
        else {
            Node* temp = new Node(elem);
            Node* Current = head;
            for (int i = 0;i < pos;i++) {
                Current = Current->next;
            }
            temp->next = Current->next;
            Current->next = temp;
            size++;
        }
    }
    void deleteFirst() {
        if (head == NULL) {
            cout << "Empty List" << endl;
        }
        else {
            Node* temp = head;
            if (size == 1) {
                delete temp;
                head = NULL;
                tail = NULL;
                size = 0;
            }
            else {
                head = head->next;
                delete temp;
                size--;
            }
        }
    }
    void deleteLast() {
        if (head == NULL) {
            cout << "Empty List" << endl;
        }
        else {
            Node* temp = tail;
            if (size == 1) {
                delete temp;
                head = NULL;
                tail = NULL;
                size = 0;
            }
            else {
                Node* current = head;
                for (int i = 0; i < size - 2;i++)
                    current = current->next;
                tail = current;
                tail->next = NULL;
                delete temp;
                size--;
            }
        }
    }
    void deleteAt(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position" << endl;
        }
        else if (pos == 0) { deleteLast(); }
        else if (pos == size - 1) {
            deleteLast();
        }
        else {
            Node* temp = tail;
            if (size == 1) {
                delete temp;
                head = NULL;
                tail = NULL;
                size = 0;
            }
            else {
                Node* current = head;
                for (int i = 0; i < size - 2;i++)
                    current = current->next;
                Node* temp = current->next;
                current->next = temp->next;
                //current->next=(current->next)->next
                delete temp;
                size--;
            }
        }
    }
    void print_list() {
        while (head != NULL) {
            cout << head->elem << " ";
            head = head->next;
        }
    }
    /*void deleteWith(int src, int elem) {
        Node* current = head;
        int i = 0;
        while (size > i) {
            current = current->next;
            if (src == current) {
                current = new(elem);
            }
            i++;
        }

    }*/


};
