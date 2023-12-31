/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:12:17 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/20 16:08:02 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
    const int size = 2;
    Animal** animals = new Animal*[size];
    // Animal animal;

    for (int i = 0; i < size / 2; ++i) {
        animals[i] = new Dog();
        animals[i]->makeSound();
    }

    for (int i = size / 2; i < size; ++i) {
        animals[i] = new Cat();
        animals[i]->makeSound();
    }

    for (int i = 0; i < size; ++i) {
        delete animals[i];
    }

    delete[] animals;

    return 0;

    // const Animal* meta = new Animal();
    // const WrongAnimal* i = new WrongCat();
    // const Animal* j = new Dog();
    // std::cout << "Type: " << i->getType() << " " << std::endl;
    // std::cout << "Type: " << j->getType() << " " << std::endl;
    // i->makeSound();  // will output the cat sound!
    // j->makeSound();
    // meta->makeSound();
    // delete j;
    // delete i;
    // delete meta;
    // return (0);
}