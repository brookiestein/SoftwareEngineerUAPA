#ifndef INPUT_HPP
#define INPUT_HPP

#include <string>
#include <type_traits>

class Input
{
public:
	 Input();
	 std::string getString(const std::string &message);
	 double getNumber(const std::string &message);
};

#endif // INPUT_HPP
