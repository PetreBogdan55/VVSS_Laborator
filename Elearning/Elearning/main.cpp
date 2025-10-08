#include "User.h"
#include <iostream>
#include <vector>

int main()
{
	// Afisare c++ cu mesaje: Suma lui a si a lui b este a+b
	int a = 5;
	int b = 7;
	std::cout << "Suma lui " << a << " si a lui " << b << " este " << a + b << std::endl;

	// Doar pentru C++ 23 - Martie 2025
	std::println("Suma lui {} si a lui {} este {}",	a, b, a + b);
	std::vector<int> vector = { 1,2,3,8,10 };
	std::println("Vector: {::04x}", vector);

	// Apel clase
	User user("Ion", "Popescu", "ion.popescu@gmail.com", "Str. Lunga, nr 67A, Brasov, Romania", "0712345678");
	user.PrintInformation();

	return 0;
}