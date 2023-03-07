#include <string>
#include <iostream>

class ComponentA;
class ComponentB;

class VisitorInterface { // the specific classes implement this

public:
	virtual void visitComponentA(const ComponentA* comp) const = 0;
	virtual void visitComponentB(const ComponentB* comp) const = 0;
}; 

class ComponentInterface { // visitable 'cat' 'dog'

public:
	virtual ~ComponentInterface() {};
	virtual void accept(VisitorInterface* visit) const = 0;
}; 

class ComponentA : public ComponentInterface {

public:

	ComponentA() {};

	virtual void accept(VisitorInterface* visitor) const override {
		visitor->visitComponentA(this);
	};

	std::string ComponentAFunc() const {
		return "ComponentA";
	}
};

class ComponentB : public ComponentInterface {

public:

	ComponentB() {};

	virtual void accept(VisitorInterface* visitor) const override {
		visitor->visitComponentB(this);
	};

	std::string ComponentBFunc() const {
		return "ComponentB";
	}
}; 

// Define the visitors

class Visitor1 : public VisitorInterface {

public:
	
	void visitComponentA(const ComponentA* comp) const {
		std::cout << "Visited " << comp->ComponentAFunc() << " from visitor.\n" << std::endl;
	}
	
	void visitComponentB(const ComponentB* comp) const {
		std::cout << "Visited " << comp->ComponentBFunc() << " from visitor.\n" << std::endl;
	}

};




