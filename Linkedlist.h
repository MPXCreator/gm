//
// Created by Reyes on 2023/11/13.
//

#ifndef GM_LINKEDLIST_H
#define GM_LINKEDLIST_H

#include <iostream>
#include <fstream>

std::string logTimel() {
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    std::string time = "[" + std::to_string(1900 + ltm->tm_year) + "/" + std::to_string(1 + ltm->tm_mon) + "/" +
                       std::to_string(ltm->tm_mday) + " " + std::to_string(ltm->tm_hour) + ":" +
                       std::to_string(ltm->tm_min) + ":" + std::to_string(ltm->tm_sec) + "]";
    return time;
}

#define YELLOW  "\033[33m"

namespace gm {
    template<typename T>
    class Linkedlist {
    private:
        struct Node {
            T data;
            Node *next;
        };

        Node *head;
        Node *tail;
        int size;
    public:
        Linkedlist() {
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        Linkedlist(const Linkedlist<T> &list) {
            head = nullptr;
            tail = nullptr;
            size = 0;
            Node *temp = list.head;
            while (temp != nullptr) {
                add(temp->data);
                temp = temp->next;
                size++;
            }
        }

        ~Linkedlist() {
            clear();
        }

        void add(T data) {
            Node *temp = new Node;
            temp->data = data;
            temp->next = nullptr;
            if (head == nullptr) {
                head = temp;
                tail = temp;
            }
            else {
                tail->next = temp;
                tail = temp;
            }
            size++;
        }

        int getSize() { return size; }

        void clear() {
            Node *temp = head;
            while (temp != nullptr) {
                Node *next = temp->next;
                delete temp;
                temp = next;
            }
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        bool isEmpty() { return size == 0; }

        void print() {
            Node *temp = head;
            while (temp != nullptr) {
                std::cout << YELLOW << *temp->data << std::endl;
                temp = temp->next;
            }
        }

        void log() {
            Node *temp = head;
            while (temp != nullptr) {
                std::clog << "[DATA] " << logTimel() << std::endl << *temp->data << std::endl;
                temp = temp->next;
            }
        }

        void sort() {
            Node *temp = head;
            while (temp != nullptr) {
                Node *temp2 = temp->next;
                while (temp2 != nullptr) {
                    if (temp->data > temp2->data) {
                        T data = temp->data;
                        temp->data = temp2->data;
                        temp2->data = data;
                    }
                    temp2 = temp2->next;
                }
                temp = temp->next;
            }
        }

        void sort(bool (*compare)(T, T)) {
            Node *temp = head;
            while (temp != nullptr) {
                Node *temp2 = temp->next;
                while (temp2 != nullptr) {
                    if (compare(temp->data, temp2->data)) {
                        T data = temp->data;
                        temp->data = temp2->data;
                        temp2->data = data;
                    }
                    temp2 = temp2->next;
                }
                temp = temp->next;
            }
        }

        Node *getHead() { return head; }
    };

}

#endif //GM_LINKEDLIST_H
