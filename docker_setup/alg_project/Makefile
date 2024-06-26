CC=gcc
CXX=g++

INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin
TEST_SRC_DIR = ./testsrc
TEST_TMP_DIR = ./testtmp

CXXFLAGS = -std=c++17 -I $(INC_DIR)
LDFLAGS = -lgtest -lgtest_main -lpthread -lexpat -lgmock

all: directories runtests

runtests:	run_test_aho_corasick

# HIDING OUTPUTS IN FILES ---------------------------------------------------------------------------------------------------------------------------------------------------

run_test_aho_corasick: $(BIN_DIR)/test_aho_corasick
	$(BIN_DIR)/test_aho_corasick --gtest_output=xml:$(TEST_TMP_DIR)/test_aho_corasick
	mv $(TEST_TMP_DIR)/run_test_aho_corasick run_test_aho_corasick

# teststrutils ---------------------------------------------------------------------------------------------------------------------------------------------------

$(BIN_DIR)/test_aho_corasick: $(OBJ_DIR)/aho_corasick.o $(OBJ_DIR)/aho_corasick_test.o
	$(CXX) -o $(BIN_DIR)/test_aho_corasick $(OBJ_DIR)/aho_corasick.o $(OBJ_DIR)/aho_corasick_test.o $(LDFLAGS)

$(OBJ_DIR)/aho_corasick.o: $(SRC_DIR)/aho_corasick.cpp
	$(CXX) -o $(OBJ_DIR)/aho_corasick.o $(CXXFLAGS) -c $(SRC_DIR)/aho_corasick.cpp

$(OBJ_DIR)/aho_corasick_test.o: $(TEST_SRC_DIR)/aho_corasick_test.cpp
	$(CXX) -o $(OBJ_DIR)/aho_corasick_test.o $(CXXFLAGS) -c $(TEST_SRC_DIR)/aho_corasick_test.cpp


clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BIN_DIR)
	rm -rf $(TEST_TMP_DIR)

directories:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)
	mkdir -p $(TEST_TMP_DIR)
