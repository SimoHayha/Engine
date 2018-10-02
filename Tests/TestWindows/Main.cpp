#include <iostream>

#include <Engine/Engine.hpp>

using namespace Ngine;

int main(int ac, char** av)
{
	auto ngine = std::make_unique<Engine>();

	int32_t exitCode = ngine->Run();

	std::cout << "Press enter to continue...";
	std::cin.get();

	return exitCode;
}