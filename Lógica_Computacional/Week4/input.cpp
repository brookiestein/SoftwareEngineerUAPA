#include "input.hpp"

#include <iostream>
#include <print>
#include <type_traits>

Input::Input()
{

}

std::string Input::getString(const std::string &message)
{
	 while (true) {
		  std::string str;
		  std::print("{}: ", message);
		  std::getline(std::cin, str);

		  if (str.empty()) {
			   std::println("No ingresaste nada.");
			   continue;
		  }

		  return str;
	 }
}

double Input::getNumber(const std::string &message)
{
	 double result;
	 
	 while (true) {
		  std::string input = getString(message);
		  try {
			   result = std::stod(input);
			   break;
		  } catch (...) {
			   std::println("El valor introducido: {}, no es un número válido.", input);
		  }
	 }

	 return result;
}
