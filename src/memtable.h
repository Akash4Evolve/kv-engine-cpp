#ifndef MEMTABLE_H
#define MEMTABLE_H

#include <string>
#include <map>

class MemTable {
private:
    
    std::map<std::string, std::string> table;
    
    // Track the current memory usage of this MemTable in bytes
    size_t current_size;

public:
    // Constructor
    MemTable();

    // Insert or update a key-value pair
    void put(const std::string& key, const std::string& value);

    // Retrieve a value by its key. Returns empty string if not found.
    std::string get(const std::string& key);

    // Check if a key exists
    bool contains(const std::string& key);

    // Get the current byte size of the data stored
    size_t get_size() const;

    // Clear all data from the MemTable (used after flushing to disk)
    void clear();
};

#endif // MEMTABLE_H