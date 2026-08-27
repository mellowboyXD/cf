CC := gcc
CXX := g++
CFLAGS := -std=c11
CXXFLAGS := -std=c++11
BUILD_DIR := build

.PHONY: all clean

# make hello  -> looks for hello.c or hello.cpp
%: $(BUILD_DIR)/%.o
	$(CXX) -o $(BUILD_DIR)/$@ $<

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

MAKEFLAGS += -r
