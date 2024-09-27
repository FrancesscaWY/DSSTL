#include <iostream>
#include "Linked.h"

int main() {
    // Create a linked object
    Linked<std::string> nameList;

    // Add elements to the front of the nameList
    nameList.push_front("Francesca");
    nameList.push_front("Alex");
    nameList.push_front("John");
    nameList.push_front("Bob");

    // Print the elements of nameList using an Iterator
    for (Linked<std::string>::Iterator it = nameList.begin(); it != nameList.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Use the findNode method to find a node
    nameList.findNode("Francesca");
    nameList.findNode("Hellen");

    // use the method pop_front to remove the first element
    nameList.pop_front();

    // Print the elements of nameList using an Iterator
    for(Linked<std::string>::Iterator it = nameList.begin();it != nameList.end();it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}