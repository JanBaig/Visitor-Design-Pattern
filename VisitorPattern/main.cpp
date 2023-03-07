#include <string>
#include <iostream>
#include "visitor.h"

int main() {
    
    ComponentA componentA;
    ComponentB componentB;

    Visitor1* visitor = new Visitor1();

    componentA.accept(visitor);
    componentB.accept(visitor);

    return 0;
}

