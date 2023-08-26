# Visitor Design Pattern

### Description
The visitor design pattern is a behavioural design pattern that allows for the separation of algorithms from the objects on which they operate. 

Adding new methods within subclasses works fine if the program being developed isn't complex - simply add the methods to each of the individual subclasses. For example, if we have an Animal parent class, each of the Animal subclasses may need to implement a `makeSounds()` method. However, when our codebase consists of dozens of new methods to be implemented for dozens of subclasses, the code within each subclass becomes cluttered and often becomes difficult to maintain.

The visitor design pattern solves this problem. It allows for the addition of methods into subclasses *without modifying* the existing subclasses themselves. So, if we need all of our subclasses to implement the `makeSound()` method, instead of _individually_ going into each subclass and adding it, we can instead couple all the `makeSound()` implementations for each subclass in one place. That way we only need to visit one section in our code and modify that section alone - effectively resulting in all subclasses having implementations of `makeSound()` without having to visit each and every subclass separately.


> I've written a [blog](https://janbaig.netlify.app/posts/visitor_design_pattern/) explaining the concept in far greater detail if you'd like to learn more! 👾
