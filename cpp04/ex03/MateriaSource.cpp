/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:54:10 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/16 16:09:55 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {}

MateriaSource::MateriaSource(const MateriaSource &materiaSource) {
    *this = materiaSource;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource) {
    if (this != &materiaSource) {
    }
    return (*this);
}

MateriaSource::~MateriaSource(void) {}

void MateriaSource::learnMateria(AMateria *aMateria) { (void)aMateria; }

AMateria *MateriaSource::createMateria(std::string const &type) {
    (void)type;
    return (NULL);
}
