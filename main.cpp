#include <iostream>
#include <string>

int main(){
	std::string str{"Hello World"};
	std::cout << str << '\n';
	auto lamba{
		[](int i) -> int {
			return i * 2;
		}
	}

	std::cout << lamba(5) << '\n';
  std::cout << "Hello\n";
	return 0;
}
