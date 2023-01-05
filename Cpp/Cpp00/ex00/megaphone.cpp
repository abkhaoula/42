/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabdenou <kabdenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:06:01 by kabdenou          #+#    #+#             */
/*   Updated: 2023/01/05 12:06:02 by kabdenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int main(int argc, char* argv[]) {
  // Check if at least one argument was passed
  if (argc < 2) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return 0;
  }

  // Concatenate all arguments into a single string
  std::string message;
  for (int i = 1; i < argc; i++) {
    message += argv[i];
  }

  // Convert the message to uppercase
  for (int i = 0; message[i] != '\0'; i++) {
    message[i] = toupper(message[i]);
  }

  // Print the message
  std::cout << message << std::endl;

  return 0;
}