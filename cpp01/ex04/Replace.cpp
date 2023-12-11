/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 06:00:29 by cmeng             #+#    #+#             */
/*   Updated: 2023/12/11 16:13:04 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(std::string filename, std::string s1, std::string s2)
    : filename_(filename), s1_(s1), s2_(s2) {
    return;
};

Replace::~Replace() {}

void Replace::replace() {
    std::fstream inFile(filename_);
    if (!inFile) {
        std::cerr << "Can't open file" << filename_ << std::endl;
        return;
    }

    std::ofstream outFile(filename_ + ".replace");
    if (!outFile) {
        std::cerr << "Can't open file " << filename_ + ".replace" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        size_t pos = 0;
        while ((pos = line.find(s1_, pos)) != std::string::npos) {
            line.erase(pos, s1_.length());
            line.insert(pos, s2_);
            pos += s2_.length();
        }
        outFile << line << "\n";
    }

    inFile.close();
    outFile.close();
}
