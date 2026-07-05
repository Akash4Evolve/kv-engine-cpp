# 🚀 High-Performance Key-Value Storage Engine (C++)

`kv-engine-cpp` is an in-progress, lightweight, high-performance NoSQL storage engine built from scratch in C++. It utilizes a **Log-Structured Merge-Tree (LSM-Tree)** architecture to achieve fast write throughput while maintaining efficient key lookups using core Data Structures and Algorithms (DSA).

⚠️ **Status:** In Active Development (Phase 1: In-Memory Component)

## 🏗️ System Architecture
*   **MemTable (In-Memory):** Powered by a self-balancing binary search tree (**Red-Black Tree** or **SkipList**) to handle $O(\log N)$ writes and lookups.
*   **Write-Ahead Log (WAL):** Ensures durability by logging append-only write operations sequentially to disk before updating memory.
*   **SSTables (On-Disk):** Sorted String Tables that store data immutably on disk once the MemTable reaches capacity.

## 🛠️ Tech Stack & Concepts
*   **Language:** C++17
*   **Core DSA:** Self-Balancing Trees, Hashing, Binary Search
*   **Systems Concepts:** Memory Management, File I/O Streams, Serialization

## 📅 Development Roadmap
- [x] Design system architecture and file layouts
- [ ] Implement the in-memory MemTable via custom BST/SkipList
- [ ] Add sequential Write-Ahead Logging (WAL) for fault tolerance
- [ ] Implement SSTable flushing and binary search on-disk lookups
- [ ] Create an interactive CLI client loop

## 🚀 Local Setup (In Progress)
To compile the current CLI skeleton:
```bash
git clone [https://github.com/your-username/kv-engine-cpp.git](https://github.com/your-username/kv-engine-cpp.git)
cd kv-engine-cpp
make
./kv_engine