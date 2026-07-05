#include <iostream>
#include <string>
#include "memtable.h"

int main() {
    MemTable db;
    std::string command, key, value;

    std::cout << "========================================\n";
    std::cout << "  🚀 High-Performance KV-Engine Live CLI \n";
    std::cout << "  Commands: SET [k] [v] | GET [k] | SIZE | EXIT\n";
    std::cout << "========================================\n";

    while (true) {
        std::cout << "\nkv-engine> ";
        std::cin >> command;

        if (command == "SET" || command == "set") {
            std::cin >> key >> value;
            db.put(key, value);
            std::cout << "SUCCESS: Stored [" << key << " -> " << value << "]";
        } 
        else if (command == "GET" || command == "get") {
            std::cin >> key;
            if (db.contains(key)) {
                std::cout << key << " => " << db.get(key);
            } else {
                std::cout << "ERROR: Key [" << key << "] not found.";
            }
        } 
        else if (command == "SIZE" || command == "size") {
            std::cout << "Current In-Memory Footprint: " << db.get_size() << " bytes";
        } 
        else if (command == "EXIT" || command == "exit") {
            std::cout << "Shutting down engine gracefully...\n";
            break;
        } 
        else {
            std::cout << "Invalid Command! Use SET, GET, SIZE, or EXIT.";
            // Clear input buffer stream in case of messy typing
            std::cin.clear();
            std::string discard;
            std::getline(std::cin, discard);
        }
    }

    return 0;
}