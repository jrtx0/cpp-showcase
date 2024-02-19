#include <iostream>

class Animal {
public:
    virtual void makeSound() const {
        std::cout << "Animal make a sound." << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Dog barks." << std::endl;
    } 
};

class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Cat meows." << std::endl;
    }
};

int main() {
    Animal animal;
    Dog dog;
    Cat cat;

    Animal* animalPtr = &dog;
    animalPtr -> makeSound();

    animalPtr = &cat;
    animalPtr -> makeSound();

    return 0;
}

/* compile command: g++ polymorphics.cpp -o polymorhics */