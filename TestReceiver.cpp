#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "test/catch.hpp"

#define private public
#include "Receiver.h"

using namespace std;

TEST_CASE("Check_for_Read_data_from_console")
{
  readTheDataFromConsole();
}

