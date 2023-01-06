/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:24:09 by kabdenou          #+#    #+#             */
/*   Updated: 2023/01/06 17:24:10 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"
#include <iostream>

int main() {
    Harl h;

    std::cout << "DEBUG" << std::endl;
    h.complain("DEBUG");
    std::cout << "INFO" << std::endl;
    h.complain("INFO");
    std::cout << "WARNING" << std::endl;
    h.complain("WARNING");
    std::cout << "ERROR" << std::endl;
    h.complain("ERROR");
}