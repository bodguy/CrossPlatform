#include "Helper/StringUtil.h"
#include <Catch2/catch.hpp>
#include <string>

using namespace Theodore;

TEST_CASE("StringUtil unit test") {
  SECTION("string contains") {
    REQUIRE(StringUtil::Contains("seafood", "foo"));
		REQUIRE_FALSE(StringUtil::Contains("seafood", "bar"));
		REQUIRE(StringUtil::Contains("seafood", ""));
		REQUIRE(StringUtil::Contains("", ""));
  }

  SECTION("string split with delimiter") {
  	std::vector<std::string> ref_vec;
  	REQUIRE(StringUtil::Split("The quick brown fox jumps over the lazy dog", ref_vec, " ") == 9);
  	REQUIRE(StringUtil::Join(", ", "[ ", " ]", ref_vec.begin(), ref_vec.end()) == "[ The, quick, brown, fox, jumps, over, the, lazy, dog ]");
  }

  SECTION("string replace") {
  	REQUIRE(StringUtil::Replace("oink oink oink", "k", "ky", 2) == "oinky oinky oink");
		REQUIRE(StringUtil::Replace("oink oink oink", "k", "ky", 0) == "oink oink oink");
  	REQUIRE(StringUtil::Replace("oink oink oink", "oink", "moo", -1) == "moo moo moo");
		REQUIRE(StringUtil::ReplaceAll("oink oink oink", "oink", "moo") == "moo moo moo");
  }

  SECTION("string joining with vector") {
  	std::vector<std::string> iterable{ "a", "b", "c", "d", "e" };
  	REQUIRE(StringUtil::Join(", ", iterable.begin(), iterable.end()) == "a, b, c, d, e");
  }

  SECTION("string joining with plain old array") {
  	std::string iterable[5] = { "a", "b", "c", "d", "e" };
		REQUIRE(StringUtil::Join(", ", iterable, iterable + 5) == "a, b, c, d, e");
  }

  SECTION("string joining with prefix and suffix") {
		std::string iterable[5] = { "a", "b", "c", "d", "e" };
		REQUIRE(StringUtil::Join(", ", "[ ", " ]", iterable, iterable + 5) == "[ a, b, c, d, e ]");
  }

  SECTION("string joining with prefix and suffix from complex vector container") {
  	std::vector<std::vector<int>> nested_vec = {
			{ 1, 2, 3}, { 4, 5, 6}, { 7, 8, 9}
  	};
  	std::vector<std::string> flat_vec;
  	for (const auto& vec : nested_vec) {
			flat_vec.emplace_back(StringUtil::Join(", ", "[", "]", vec.begin(), vec.end()));
  	}
  	REQUIRE(StringUtil::Join(", ", "[ ", " ]", flat_vec.begin(), flat_vec.end()) == "[ [1, 2, 3], [4, 5, 6], [7, 8, 9] ]");
  }

  SECTION("string leading trim") {
  	REQUIRE(StringUtil::TrimLeft("   Hello World!") == "Hello World!");
  }

	SECTION("string trailing trim") {
		REQUIRE(StringUtil::TrimRight("Hello World!   ") == "Hello World!");
	}

	SECTION("string leading and trailing trim") {
		REQUIRE(StringUtil::Trim("   Hello World!    ") == "Hello World!");
  }

  SECTION("string to lower case") {
		REQUIRE(StringUtil::ToLower("Hello World!") == "hello world!");
  }

	SECTION("string to upper case") {
		REQUIRE(StringUtil::ToUpper("Hello World!") == "HELLO WORLD!");
	}

	SECTION("string last index of") {
		REQUIRE(StringUtil::Index("Hello gorilla", "ll") == 2);
		REQUIRE(StringUtil::LastIndex("Hello gorilla", "ll") == 10);
		REQUIRE(StringUtil::LastIndex("Hello gorilla", "og") == -1);
  }

  SECTION("string repeat") {
		REQUIRE("ba" + StringUtil::Repeat("na", 2) == "banana");
  	REQUIRE(StringUtil::Repeat("co", 2) + "nut" == "coconut");
  }

  SECTION("string occurance count") {
		REQUIRE(StringUtil::Count("every", "e") == 2);
  	REQUIRE(StringUtil::Count("occurance", "cc") == 1);
		REQUIRE(StringUtil::Count("five", "") == 5);
  }
}