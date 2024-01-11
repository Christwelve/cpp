/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:24:00 by cmeng             #+#    #+#             */
/*   Updated: 2024/01/11 15:20:34 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
Array<T>::Array(void) : array_(NULL), size_(0) {}

template <typename T>
Array<T>::Array(const unsigned int &n) : array_(new T[n]), size_(n) {}

template <typename T>
Array<T>::Array(const Array &source) : array_(new T[source.size_]), size_(source.size_) {
    for (unsigned int i = 0; i < source.size_; i++) {
        array_[i] = source.array_[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &source) {
    if (this != &source) {
        delete[] array_;
        array_ = new T[source.size_];
        size_ = source.size_;
        for (unsigned int i = 0; i < source.size_; i++) {
            array_[i] = source.array_[i];
        }
    }
    return (*this);
}

template <typename T>
Array<T>::~Array() {
    delete[] array_;
}

template <typename T>
unsigned int Array<T>::size(void) const {
    return (size_);
}
