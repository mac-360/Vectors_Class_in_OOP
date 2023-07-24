# Vectors Class - C++ Templated Dynamic Array Implementation

The `Vectors` class is a C++ templated dynamic array implementation that provides functionality similar to the standard vector container. It allows for dynamic resizing and management of elements stored in an array-like structure. The class uses templates to enable the storage of elements of any data type.

## Features

1. **Dynamic Array**: The class provides a dynamic array that grows automatically when the number of elements exceeds the current capacity.

2. **Resizable**: The array can be resized to accommodate more elements, and unused memory can be deallocated to save space.

3. **Element Access**: It allows access to individual elements using the `at`, `front`, and `back` member functions.

4. **Iterators**: Supports iteration over elements using the `begin` and `end` functions.

5. **Modifiers**: Various member functions to add, remove, and modify elements in the array, such as `push_back`, `pop_back`, `resize`, `erase`, and `clear`.

6. **Initializer List Support**: The class supports initialization with an initializer list of elements.

7. **Copy and Assignment**: Supports copy construction and copy assignment for easy handling of vectors.

8. **Emplacement**: Provides emplacement functions to insert elements at specific positions, which constructs elements in-place.

9. **Reverse Iterators**: The class provides reverse iterators to iterate over elements in reverse order.

10. **Capacity Information**: Functions to get the current size and capacity of the vector.

11. **`shrink_to_fit`**: It allows reducing the capacity to match the current size.

## Member Functions

### Constructor

- **Vectors()**: Default constructor that creates an empty vector with an initial capacity of 10.

- **Vectors(int totalcap, int noofelements)**: Constructor that creates a vector with a given initial capacity and the number of elements.

- **Vectors(std::initializer_list\<Type\> elements)**: Constructor to initialize the vector with an initializer list of elements.

### Element Access

- **Type at(int index)**: Access the element at the specified index. Throws an exception if the index is out of bounds.

- **Type front()**: Access the first element of the vector.

- **Type back()**: Access the last element of the vector.

### Capacity

- **int size()**: Returns the current number of elements in the vector.

- **int capacity()**: Returns the current capacity of the vector.

- **bool empty()**: Checks if the vector is empty.

- **int maxsize()**: Returns the maximum number of elements the vector can hold (based on the data type).

### Modifiers

- **void push_back(Type val)**: Appends the given element to the end of the vector.

- **void pop_back()**: Removes the last element from the vector.

- **void resize(int newsize, Type val = Type())**: Resizes the vector to the specified size. Additional elements are filled with the provided value.

- **void clear()**: Removes all elements from the vector.

- **void erase(int position)**: Removes the element at the specified position.

- **void erase(int start, int end)**: Removes elements in the range [start, end) from the vector.

- **void insert(int position, const Type& value)**: Inserts an element at the specified position.

- **void emplace_back(const Type& val)**: Emplaces a copy-constructed element at the end of the vector.

- **template \<typename... Args> void emplace_back(Args&&... args)**: Emplaces a new element with provided arguments at the end of the vector.

- **Type\* emplace(Type\* ref, Args&&... args)**: Emplaces a new element at the given position.

### Iterators

- **Type\* begin()**: Returns an iterator pointing to the first element of the vector.

- **Type\* end()**: Returns an iterator pointing to one past the last element of the vector.

- **Type\* rbegin()**: Returns a reverse iterator pointing to the last element of the vector.

- **Type\* rend()**: Returns a reverse iterator pointing to one position before the first element of the vector.

### Reverse Iterators

- **const Type\* rbegin() const**: Returns a constant reverse iterator pointing to the last element of the vector.

- **const Type\* rend() const**: Returns a constant reverse iterator pointing to one position before the first element of the vector.

### Miscellaneous

- **const Type\* cend() const**: Returns a constant iterator pointing to one past the last element of the vector.

- **const Type\* crbegin() const**: Returns a constant reverse iterator pointing to the last element of the vector.

- **const Type\* crend() const**: Returns a constant reverse iterator pointing to one position before the first element of the vector.

- **const Type\* data() const**: Returns a pointer to the underlying data of the vector.

- **void swap(Vectors& obj)**: Swaps the contents of two vectors.

- **void shrink_to_fit()**: Reduces the capacity of the vector to match the current size.
### Additional Details  
For a comprehensive exploration of C++ vectors and to access illustrative sample programs, we cordially invite you to visit the provided link. This valuable resource, hosted by JavaTpoint, offers expert guidance and practical demonstrations, enabling you to proficiently harness the potential of the vector class in your C++ programming endeavors.  
## `[C++ Vectors](https://www.javatpoint.com/cpp-vector)`    
Explore the comprehensive array of professional and versatile functions available in the esteemed Vectors class. This illustrative image showcases the power and flexibility of the class, providing a glimpse into the multitude of operations that can be effortlessly performed to manage dynamic arrays and optimize data handling. Embark on your journey to proficiency and efficiency with the exceptional functionality offered by the Vectors class.    
[Function List 1](C:\Users\Akhyar\Downloads\Functionlist1.png)    
[Function List 2](C:\Users\Akhyar\Downloads\FunctionList2.png)

[Vectors Function]()
## Conclusion

The `Vectors` class is a flexible and efficient dynamic array implementation, providing essential vector-like functionality. It allows for easy manipulation of elements and dynamic resizing to accommodate varying data sizes. Developers can use this class as a drop-in replacement for the standard vector container, especially when more control over the memory management is required.
