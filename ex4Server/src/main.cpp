//main.cpp

#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <sstream>
#include "MoviesSystem.h"
#include "gtest.h"


using namespace std;
GTEST_API_ int main(int argc, char* argv[]) {
	printf("Running main() from main.cpp\n");
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	MoviesSystem* ms = new MoviesSystem();
	(*ms).start();
}
