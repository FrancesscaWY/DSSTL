#ifndef LINKED_H
#define LINKED_H

#include <cstddef> // for std::size_t
#include <iostream>
template <typename T>
class Linked {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;
    std::size_t length;

public:
    Linked() : head(nullptr), length(0) {}
    ~Linked() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_front(T item) {
        Node* newPtr = new Node;
        newPtr->data = item;
        newPtr->next = head;
        head = newPtr;
        length++;
    }

    [[nodiscard]] std::size_t getSize() const { return length; }

    class Iterator {
        friend class Linked<T>;
    protected:
        Node* nodePtr;
    public:
        explicit Iterator(Node* ptr) : nodePtr(ptr) {}
        Iterator operator++(int) {
            Iterator temp = *this;
            if (nodePtr) nodePtr = nodePtr->next;
            return temp;
        }
        Iterator operator++() {
            if (nodePtr) nodePtr = nodePtr->next;
            return Iterator(nodePtr);
        }
        bool operator==(const Iterator& iterator) const { return nodePtr == iterator.nodePtr; }
        bool operator!=(const Iterator& iterator) const { return nodePtr != iterator.nodePtr; }
        T& operator*() { return nodePtr->data; }
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }

    void findNode(T item) {
        Node* temp=new Node;
        temp->data=item;
        Iterator it=Iterator(temp);
        Iterator it2=Iterator(head);
        while(it2!=Iterator(nullptr)&&it2.nodePtr->data!=it.nodePtr->data) {
            ++it2;
        }
        if(it2==Iterator(nullptr)) {
            std::cout << "Not found node " << std::endl;
        }else {
            std::cout << "Found node " << std::endl;
        }
    }

    void pop_front() {
        Node* firstNode = head;
        head = head->next;
        delete firstNode;
        length--;
    }
    void reversPrintNode(Node* node) {
        if(node == nullptr) {
            return;
        }else {
            reversPrintNode(node->next);
            std::cout << node->data << std::endl;
        }
    }
    void reversePrint() {
        reversPrintNode(head);
    }

};

#endif // LINKED_H