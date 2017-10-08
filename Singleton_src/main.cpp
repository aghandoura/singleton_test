#include<iostream>

#include"singleton.h"



int
main(int argc, char* argv[])
{
	singleton* first_instance;
	first_instance = singleton::get_instance();

	std::cout << "hello " << std::endl;
	std::cout << "first id " << first_instance->get_instances_count() << std::endl;
	singleton* second_instance;
	second_instance = singleton::get_instance();
	std::cout << "second id " << second_instance->get_instances_count() << std::endl;

	first_instance->kill();
	second_instance->kill();
	system("pause");
	return 0;
}