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

