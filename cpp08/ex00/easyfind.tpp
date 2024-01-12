/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeng <cmeng@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:11:43 by christianme       #+#    #+#             */
/*   Updated: 2024/01/12 20:51:25 by cmeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator result;
    result = std::find(container.begin(), container.end(), value);

    if (result == container.end())
        throw std::exception();
    else
        return (result);
}