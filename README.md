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
### OOP Concepts Used  
For a comprehensive analysis of the Object-Oriented Programming (OOP) concepts employed in the implementation of the `Vectors` class, we invite you to refer to the following link:  
[Link to Vectors Class OOP Concepts](https://github.com/mac-360/Vectors_Class_in_OOP/files/12144933/Vectors.Class.docx)  

This invaluable resource will provide an in-depth exploration of the OOP principles intricately woven into the `Vectors` class. Discover how encapsulation, abstraction, constructor overloading, copy constructor, copy assignment, operator overloading, dynamic memory allocation, destructor, and member functions converge harmoniously to create a robust, reusable, and maintainable dynamic array implementation in C++. Embark on a journey of understanding the elegance and power of OOP within the realm of `Vectors` class, setting the standard for excellence in modern programming paradigms.
### Additional Details  
For a comprehensive exploration of C++ vectors and to access illustrative sample programs, we cordially invite you to visit the provided link. This valuable resource, hosted by JavaTpoint, offers expert guidance and practical demonstrations, enabling you to proficiently harness the potential of the vector class in your C++ programming endeavors.  
#### [C++ Vectors Details with Sample Programs](https://www.javatpoint.com/cpp-vector)    
Explore the comprehensive array of professional and versatile functions available in the esteemed Vectors class. This illustrative image showcases the power and flexibility of the class, providing a glimpse into the multitude of operations that can be effortlessly performed to manage dynamic arrays and optimize data handling. Embark on your journey to proficiency and efficiency with the exceptional functionality offered by the Vectors class.    
Sure, here's the formatted version of the provided links with the images aligned perfectly below each other:

[Function List 1]()
![Function List 1](https://github.com/mac-360/Vectors_Class_in_OOP/assets/122281916/0fe31eb1-e414-4409-b235-98b90a65deec)

[Function List 2]()
![Function List 2](https://github.com/mac-360/Vectors_Class_in_OOP/assets/122281916/209c9f68-5df7-4263-8b03-66fb235f0da8)
## Incorporating Vectors.h: A Simple Guide  
Incorporating the code from the header file "Vectors.h" in your project involves a few steps. Here's the correct way to attach and use the header file:  

1. **Create a Separate Header File**: First, create a new file named "Vectors.h" and copy-paste the contents of the header file "Vectors" into this new file.  

2. **Save the Header File**: Save the "Vectors.h" header file in the same directory as your main code file or in a directory where your code can access it.  

3. **Include the Header File**: In your main code file (where you want to use the "Vectors" class), include the "Vectors.h" header at the beginning of the file using the `#include` preprocessor directive. This makes the class and its member functions accessible in your main code.  

Here's an example of how to include the "Vectors.h" header in your main code:

```cpp
#include "Vectors.h" // Include the Vectors.h header file

int main() {
    // Your code using the Vectors class here
    Vectors<int> myVector;
    myVector.push_back(10);
    myVector.push_back(20);

    // Rest of your code
    return 0;
}
```
  
4. **Compile and Run**: Once you have included the header file, compile your code, linking it with the implementation of the "Vectors" class. Ensure that the compiler can locate the "Vectors.h" header and the implementation file (usually a .cpp file) containing the member function definitions.  

Using this approach, your main code will have access to the functionalities provided by the "Vectors" class, and you can utilize the class as needed in your project.  

I have uploaded the "Vectors.h" header file on GitHub, you can also include it in your project using the URL to the raw file, but it is generally recommended to have a local copy of the header file for ease of use and offline development.  
## Conclusion

The `Vectors` class is a flexible and efficient dynamic array implementation, providing essential vector-like functionality. It allows for easy manipulation of elements and dynamic resizing to accommodate varying data sizes. Developers can use this class as a drop-in replacement for the standard vector container, especially when more control over the memory management is required.  

## Seeking Assistance or Offering Suggestions  
Dear Developer,  
If you need any assistance or have valuable suggestions regarding the code, we are here to lend a helping hand. Your commitment to improvement is commendable, and we highly appreciate your input.  

Please feel free to reach us via email at akhyarch307@gmail.com or l227461@lhr.nu.edu.pk. We value your contribution and look forward to collaborating with you to enhance the code's quality and efficiency.  

Thank you for trusting us with your development journey. We eagerly await your response and are ready to support you every step of the way.

Best regards.  
