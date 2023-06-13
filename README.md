# Visitor Design Pattern

### Description
Adding new methods within subclasses works fine if the program being developed isn't complex - simply add the methods to each of the individual subclasses. For example, if we have an Animal parent class, each of the Animal subclasses may need to implement a `makeSounds()` method. However, when our codebase consists of dozens of new methods to be implemented for dozens of subclasses, the code within each subclass becomes cluttered and often becomes difficult to maintain.

The visitor design pattern solves this problem. It allows for the addition of methods into subclasses *without modifying* the existing subclasses themselves. So, if we need all of our subclasses to implement the `makeSound()` method, instead of _indivdually_ going into each subclass and adding it, we can instead couple all the `makeSound()` implmentations for each subclass in one place. That way we only need to visit one section in our code and modify that section alone - effectively resulting in all subclasses having implemntations of `makeSound()` without having to visit each and every subclass seperately.

### Purpose
This small program and explanation (below) was developed to help myself understand the design pattern and use it as a quick reference before I go on to implement it in future projects. I would be glad if this can help others as well! 

### Detailed Walkthrough
>Note: The benefits of this design pattern shine when working with a complex codebase. A simplistic example with the help of pseudo-like code is used to aid in the explanation for the workings of the design pattern. If you wish to see the design pattern properly implemented, please take a look at the `main.cpp` and `visitor.h` files. 

Say we have two types of animals: dogs and cats
```c++
class Animal { }
class Dog : public Animal { }
class Cat : public Animal { }
```
We want to be able to define new animal behaviours for both of the animal types - like making sounds - without having to add a new method to each of the animal subclasses. We do this by defining a _**visitor class**_ that can hold all the implementations for the `makeSound()` method
```c++
class MakeSound : public VisitorInterface {
  // Implementation for the Cat class
  void visit(const Cat* obj) const { std::cout << "\"Meow\"" << std::endl; }
  
  // Implementation for the Dog class
  void visit(const Dog* obj) const { std::cout << "\"Woof\"" << std::endl; }
}
```
Now that we have a class where all of our animal subclass behaviour for sounds are neatly nested together, it's time to think of how each individual animal subclass might be connected to this new `MakeSound` visitor class. How would an instance of the `Cat` class redirect a call to it's `makeSound()` method so that it can be taken from the `MakeSound` visitor class? 

It's done through a polymorphic `accept()` method that each of the individual animal subclasses must implement.
```c++
class Cat : public Animal {
public:	
  virtual void accept(VisitorInterface* visitor) const override { visitor->visit(this); };
}
```
With this, whenever we wish to invoke the `makeSound()` method on a `Cat` instance, we'll need to call it with the following: 
```c++
Cat catInstance; 
MakeSound* makeSoundVisitor = new MakeSound(); 
catInstance.accept(makeSoundVisitor); // prints "Meow"
```
To perform an operation on a type of animal, we call its `accept()` method and pass in the visitor that corresponds to the operation we want to execute. In our case, since we wish to work with the `Cat` class, we create a new instance for both the `Cat` and `MakeSound` classes, then proceed to call the `Cat` class's `accept()` method which takes in the visitor class for animal sounds as an argument and then proceeds to call the visitor class's `visit()` method with itself passed as the argument. 

This is the main gist of the how the visitor pattern works. It allows us to use polymorphic dispath on the animal subclasses so that we can select the appropriate method on the visitor class in order to execute the desired behaviour.

Tracing the execution for the above looks like the following:
```
catInstance.accept(makeSoundVisitor)
-> [In Cat Class] accept(makeSoundVisitor)
-> [In Cat Class Method] makeSoundVisitor->visit(this) // 'this' is an instance of the Cat class 
-> [In MakeSound Visitor Class] visit(const Cat* obj) const; // prints "Meow" 

```

Just as how we've created the `MakeSound` visitor class, we can create multiple other visitor classes like `startHunt` or `startSleep`. Therefore, this is how arranging our code using the visitor design pattern makes it more maintainable in the long run.

If you spot any errors in the walkthrough explanation or feel that a better explanation could be provided  - please reach out and let me know!

>Additional Note: [Crafting Interpreters](https://craftinginterpreters.com/representing-code.html#the-visitor-pattern) by Robert Nystrom has greatly helped in my understanding of the concept as well as 
>a youtube [video](https://youtu.be/pL4mOUDi54o) from Derek Banas


<!-- Why we need the interface 
If we need to add other methods to the animal subclasses, like `startHunt()` or `startSleep()`, we simply need to create more visitor classes. To ensure every class correctly includes and implements the visit methods for each subclass, we make the classes inherit from the interface.
```c++
class VisitiorInterface {
  virtual void visit(const Cat* comp) const = 0;
  virtual void visit(const Dog* comp) const = 0;
}
```
-->
