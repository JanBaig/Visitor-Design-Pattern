#include <string>
#include <iostream>

class Cat;
class Dog;

class VisitorInterface {

public:
	virtual void visit(const Cat* comp) const = 0;
	virtual void visit(const Dog* comp) const = 0;
}; 

class ComponentInterface { 

public:
	virtual ~ComponentInterface() {};
	virtual void accept(VisitorInterface* visit) const = 0;
}; 

class Cat : public ComponentInterface {

public:

	Cat() {};

	virtual void accept(VisitorInterface* visitor) const override {
		visitor->visit(this);
	};

};

class Dog : public ComponentInterface {

public:

	Dog() {};

	virtual void accept(VisitorInterface* visitor) const override {
		visitor->visit(this);
	};
}; 

class MakeSound : public VisitorInterface {

public:

	void visit(const Cat* comp) const {
		std::cout << "Visited Cat component implementation: " << "\"Meow\"" << " from MakeSound visitor.\n" << std::endl;
	}

	void visit(const Dog* comp) const {
		std::cout << "Visited Dog component implementation: " << "\"Woof\"" << " from MakeSound visitor.\n" << std::endl;
	}

};

