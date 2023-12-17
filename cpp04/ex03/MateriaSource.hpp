/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:51:35 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/16 16:33:32 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
   public:
    MateriaSource(void);                                           // Default Constructor
    MateriaSource(const MateriaSource &materiaSource);             // Copy Constructor
    MateriaSource &operator=(const MateriaSource &materiaSource);  // Assignation Operator
    ~MateriaSource();

    void learnMateria(AMateria *aMateria);
    AMateria *createMateria(std::string const &type);

   private:
};

#endif