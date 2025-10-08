#include "User.h"
#include <iostream>
#include <vector>

int main()
{
	int a = 5;
	int b = 7;
	// Suma lui a si a lui b este a+B
	std::cout << "Suma lui " << a << " si a lui " <<
		b << " este " << a + b << std::endl;

	// Martie 2025
	std::println("Suma lui {} si a lui {} este {}",
		a, b, a + b);

	std::vector<int> vector = { 1,2,3,8,10 };

	std::print("Vector: {::04x}", vector);

	User user("Ion", "Popescu");
	user.PrintInformation();

	return 0;
}