# C++ structures and classes

In this practic, I will be focuing on learning Enumerated Types, Unions and Structures, and Classes.

> Enumerated types and unions are “variants”, i.e., “or”s.
> Structures are “non-variant”, i.e., “and”s

## Enumerated types and unions
Types can be user-defined through an enumeerated type, union or structure.
- **Enumerated types**. Often used in conjuntion with a switch statement

    **Sample code** 
    ```cpp
    typedef enum Level{
        LOW = 1,
        MEDIUM,
        HIGH
    };
    enum Level lv = MEDIUM;
    switch (myVar){
        case LOW:
            ...;
            break;
        ...
    }
    ```

- **Unions**.  Can store multiple different types in the same memory location. Only one member can store data at an instance.
    **Sample code**
    ```cpp
    typedef union Connection {
        int networkID;
        char networkName[4];
    }
    Connection id = 443;
    Connection ssid = "wififree";

    ```

- **Structure**. 
    ❑Comprise a collection or group of values.
    ❑As a type: can be thought of as a header in Excel.
    ❑As a value: can be thought of as a single row under that header.
    ❑Read as “and’s”

    **Example** 
    ```cpp
        typedef struct IPAddr {
            unsigned char Addr_1st;
            unsigned char Addr_2nd;
            unsigned char Addr_3rd;
            unsigned char Addr_4th;
        };

        IPAddr ip;
        ip.Addr_1st = 172;
        ip.Addr_2nd =  16;
        ip.Addr_3rd =  1 ;
        ip.Addr_4th =  205;   
    ```
    
    
    | Name       | Value |
    |-----------|-------|
    | Addr_1st      | 172 |
    | Addr_2nd    | 16|
    | Addr_3rd      | 1 |
    | Addr_4th    | 205|    

    E.g., 172.16.1.205    
        
    



## Class
Classes extend the concept of a structure.
Class similar to structures, have method, i.e., function members(methods and properties are collectively called members), vaule members are called properties.

**exameple**
```cpp
 class ClassName {
 protected:
 …
 private:
 …
 public:
 …
 };

```


## Template
A way to use the same code for different type of data.
Declared using: `template <typename type>`
This is how vectors work, the type is used to initialize the vector which uses generic code to manage lists of items.
[Watch this video for explaining the Template](https://www.youtube.com/watch?v=I-hZkUa9mIs)

**example**
```cpp
#include <iostream>
template<typename T>
    void Print(T value){
    std::cout << value << std::endl;
} 
int main(){


    Print(10);
    Print("hello");
    Print(3.14f);  
}
```

