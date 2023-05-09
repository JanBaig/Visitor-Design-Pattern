#include <string>
#include <iostream>
#include "visitor.h"

int main() {
    
    Cat catComponent;
    Dog dogComponent;

    MakeSound* visitor = new MakeSound(); 

    catComponent.accept(visitor);
    dogComponent.accept(visitor);

    return 0;
}

/*
Interfaces (Abstract Classes)
Interfaces (Abstract Classes)
- Component Interface
  - Interface for subclasses that implement the accept method
    ``` c++
    accept(visitorInterface* a) { a->visit(this) }
    ```
  - Uses polymorphic displatch to find the implementation (spceific to the subclass) within the visitor interface
- Visitor Interface
  - classes that couple the implementations for specific methods across subclasses
  - has a `visit()` method that executes each component's implementation
  ----
  # Visitor Design Pattern

### Description
Adding new methods within subclasses works fine if the program being developed is simple - simply add the methods to each of the indivudal subclasses. For example, if we have an Animal parent class, each of the Animal subclasses may need to implement the `makeSounds()` method. However, when the program becomes more complex - requiring dozens of new methods to be implmented for dozens of subclasses, the code within each subclass becomes cluttered and often becomes difficult to maintain and error-prone.

The visitor pattern solves this problem. It allows for the addition of methods to subclasses *without modifying* the existing subclasses themselves. So, if we need all of our subclasses to implement the `makeSound()` method, instead of _indivdually_ going into each subclasses and modifying the subclass, we can instead couple all the `makeSound()` implmentations for each subclass in one place. That way we only need to visit one section in our code and modify that section alone - effectly results in all subclasses having implemntations of `makeSound()` without having to visit each and every subclass.

### Purpose
This small program was developed to help myself understand the design pattern and use it as a quick reference before I go on to implement it in future projects.

### Detailed Walkthrough
<sub>Note: The benefits of this design pattern really shine when working with a complex codebase with dozens of subclasses each requiring dozens of methods. A simplistic example with the help of psuedo-like code is used to aid in the explaination for the workings of the design pattern. If you wish to see the design pattern properly implemented, please take a look at the `main.cpp` and `visitor.h` files. </sub>

Say we have two types of animals: dogs and cats
```c++
class Animal { }
class Dog : publlic Animal { }
class Cat : pubkic Animal { }
```
We want to be able to define new animal behaviours for both of the animal types - like making sounds - without having to add a new method to each of the animal subclasses. We do this by defining a single class that can hold all the implementations for the `makeSound()` method
```c++
class MakeSound : public VisitorInterface {
  void visit(const Cat* obj) const { std::cout << "\"Meow\"" << std::endl; }
  void visit(const Dog* obj) const { std::cout << "\"Woof\"" << std::endl; }
}
```

You might ask why the MakeSound class inherits from VisitorInterface. If we need to add other methods, like `startHunt()` or `startSleep()`, we simply need to create more classes for each. To ensure every class correctly includes and implements the visit methods for each subclass, we make the classes inherit from the interface.
```c++
class VisitiorInterface {
  virtual void visit(const Cat* comp) const = 0;
  virtual void visit(const Dog* comp) const = 0;
}
```



*/
