#include "memtable.h"

// Constructor initializes size to 0
MemTable::MemTable() : current_size(0) {}

void MemTable::put(const std::string& key, const std::string& value) {
    
    if (table.find(key) != table.end()) {
        current_size -= (key.size() + table[key].size());
    }
    
    // Store the data
    table[key] = value;
    
    // Add the new data footprint to our size tracker
    current_size += (key.size() + value.size());
}

std::string MemTable::get(const std::string& key) {
    if (table.find(key) != table.end()) {
        return table[key];
    }
    return ""; 
}

bool MemTable::contains(const std::string& key) {
    return table.find(key) != table.end();
}

size_t MemTable::get_size() const {
    return current_size;
}

void MemTable::clear() {
    table.clear();
    current_size = 0;
}