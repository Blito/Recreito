#include <array>
#include <iostream>

#include <glm/vec3.hpp>

int main()
{
	std::array<int, 5> myArray;
	for (auto i : myArray)
	{
		i = i;
	}

	glm::vec3 myVec(1.0f, 2.0f, 3.0f);
	std::cout << myVec.x << " " << myVec.y << " " << myVec.z << std::endl;
}