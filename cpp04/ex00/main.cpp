/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:12:17 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/20 16:47:56 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " Type " << std::endl;
    std::cout << i->getType() << " Type " << std::endl;
    i->makeSound();  // will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete j;
    delete i;
    delete meta;

    std::cout << "\nWrongAnminal Tests" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << "WrongAnimal Type " << std::endl;
    std::cout << "WrongCat Type " << std::endl;
    wrongCat->makeSound();  // will output the WrongAnimal sound!
    wrongMeta->makeSound();
    delete wrongCat;
    delete wrongMeta;

    return (0);
}