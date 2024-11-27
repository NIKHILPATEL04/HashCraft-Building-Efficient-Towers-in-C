**HashCraft - Building Efficient Towers in C**


Nikhil Patel


**Program Design**


For this assignment, I built HashCraft, a library that starts with a foundational linked list implementation and evolves into a hash table to enable efficient data storage and retrieval. The design layers these data structures systematically, culminating in a unique word-counting application capable of identifying and tracking unique lines from an input text file. This layered approach ensures modularity, enabling each component to be independently tested and optimized while making the overall program maintainable and extensible.

I began with a linked list implementation in ll.c and ll.h, which provides a dynamic structure to manage data. Each node in the list stores a data point and a reference to the next node, creating a cohesive chain. Functions were implemented to handle operations like creating a list, adding nodes, removing nodes, searching for items, and cleaning up memory. Memory management was a key focus in this layer, as the linked list needed to handle dynamic allocation and deallocation properly to avoid memory leaks.

The second layer of development involved modifying item.c and item.h to support key/value pairs instead of simple integers. This required redefining the item structure to include a string key and an integer value and updating the comparison logic to match items based on their keys. These changes allowed the linked list to handle associative operations and served as the foundation for building the hash table.

The hash table implementation in hash.c and hash.h uses an array of linked lists (buckets) to store key/value pairs. This design ensures efficient lookups and insertions by distributing data across buckets using a hash function. Key operations, such as inserting or updating values, retrieving values, and cleaning up memory, were implemented with a focus on minimizing collisions and ensuring correctness. By combining the dynamic nature of linked lists with the speed of hashing, this layer provided a significant performance boost over a naive linked list approach.

Finally, the uniqq.c application integrates all components to process text input and count unique lines. It reads lines from stdin, stores them in the hash table with unique identifiers, and outputs the total count of unique lines. This application demonstrates the practical use of the hash table and highlights the efficiency gained through the layered design.

**Pseudocode Explanation**


The linked list is the foundational structure of the program. It handles dynamic data storage and provides basic operations for managing nodes. The design ensures that nodes can be added, removed, or searched efficiently. Special care was taken in implementing the list_remove function to handle different cases, such as removing the head of the list. Memory management is handled by list_destroy, which deallocates all nodes and sets the list pointer to NULL to avoid dangling pointers.

Building on the linked list, the hash table adds an additional layer of efficiency. The hash table uses a predefined number of buckets, each of which is a linked list. Keys are hashed to determine the appropriate bucket, and operations like insertion and retrieval are performed on the corresponding linked list. This design minimizes the time complexity of operations by reducing the number of elements that need to be traversed.

The final application leverages the hash table to identify unique lines of text. Each line is hashed and checked against the table. If it is not already present, it is added with a unique identifier. This process ensures that duplicate lines are not stored multiple times, and the program outputs the total number of unique lines at the end.

**Function Descriptions**


The linked list layer includes several functions:

list_create initializes a new linked list, setting its head to NULL. This function is responsible for allocating memory and ensuring the list starts in a consistent state.
list_add appends a new node with the specified data to the end of the list. This function dynamically allocates memory for the new node and updates the list pointers.
list_remove searches for and removes a node that matches a specified item. It uses a comparison function to identify the correct node and updates pointers to maintain the list structure.
list_find searches the list for a specific item and returns a pointer to it if found. If the item is not present, it returns NULL.
list_destroy frees all memory associated with the list, ensuring no memory leaks occur. This function also sets the list pointer to NULL after deallocation.
The hash table layer builds on the linked list and includes these key functions:

hash_create initializes the hash table by allocating memory for the array of buckets and setting up each bucket as a linked list.
hash_put inserts a key/value pair into the hash table or updates the value if the key already exists. This function hashes the key to determine the appropriate bucket and uses linked list operations to manage the data.
hash_get retrieves the value associated with a given key. It hashes the key to find the correct bucket and searches the linked list in that bucket for the key.
hash_destroy frees all memory associated with the hash table, including the linked lists in each bucket.
The uniqq.c application ties everything together. It reads lines of text from stdin, hashes each line, and stores it in the hash table. Lines that are already present in the table are skipped, while new lines are added with unique identifiers. At the end, the program outputs the total count of unique lines.

**Final Design Thoughts**


The HashCraft project demonstrates the power of structured, layered design in building efficient programs. Starting with a simple linked list, I extended the functionality to handle key/value pairs and integrated it into a hash table for improved performance. Each layer was rigorously tested to ensure correctness and memory safety, with tools like Valgrind verifying the absence of leaks. By applying these components in the uniqq.c application, I created a practical and efficient solution for counting unique lines of text. The modularity of the design makes the program maintainable and adaptable for future use, showcasing the value of combining foundational data structures with optimized algorithms.







