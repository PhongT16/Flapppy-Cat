#include <catch2/catch.hpp>

#include <core/rename_this_file.h>
#include <iostream>

TEST_CASE("Check that 126 is the best class") {
  std::cout << "Hello World" << std::endl;
  REQUIRE(naivebayes::Placeholder().GetBestClass() == "CS 126");
}

