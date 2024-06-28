#include <gtest/gtest.h>
#include "aho_corasick.h"
#include <iostream>

using namespace std;

TEST(AhoCorasickTest, BasicTest){

	AhoCorasick ahoCorasick;

	std::vector< std::string > patterns_1 = {"and", "ant", "do", "geek", "dad", "ball"};
	std::string text_1 = "and";

	for (int i = 0; i < patterns_8.size(); i++) {
        ahoCorasick.insert(patterns_8[i], i);
    }

    ahoCorasick.buildFailureLinks();
    std::vector<std::pair<int, int>> results = ahoCorasick.search(text_8);

}
