/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christianmeng <christianmeng@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 14:11:43 by christianme       #+#    #+#             */
/*   Updated: 2024/01/12 14:20:09 by christianme      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator result;
	result = std::find(container.begin(), container.end(), value);

	if (result == container.end())
		throw std::exception();
	else
		return (result);
}