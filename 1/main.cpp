// ConsoleApplication10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int buff;
	std::ifstream input("input.txt");
	if (input.is_open() == 0)
	{
		std::cout << "ERROR!!! File \"input.txt\" Don't found " << std::endl;
		return 1;
	}
	std::set<int> set_input;
	while (!input.eof())
	{
		input >> buff;
		set_input.insert(buff);
	}
	input.close();
	std::ifstream test("test.txt");
	if (test.is_open() == 0)
	{
		std::cout << "ERROR!!! File \"test.txt\" Don't found " << std::endl;
		return 1;
	}
	std::vector<int> set_test;
	while (!test.eof())
	{
		test >> buff;
		set_test.push_back(buff);
	}
	test.close();

	size_t count_plus = 0;
	size_t count_minus = 0;

	std::ofstream output("output.txt");
	for (auto interator_test : set_test )
	{
		if (set_input.count(interator_test)) ///set_test.find(interator_input) != set_test.end()
			output << "yes\n", ++count_plus;
		else
			output << "no\n", ++count_minus;
	}
	std::cout << "Count plus = " << count_plus << std::endl
		<< "Count minus = " << count_minus << std::endl;
	output.close();
	return 0;
}

