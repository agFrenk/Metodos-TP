PYBIND11_INCLUDE := $(shell python3 -m pybind11 --includes)
PYTHON_INCLUDE := $(shell python3-config --includes)
PYTHON_LIB := $(shell python3-config --ldflags)
EIGEN_INCLUDE := /usr/include/eigen3

SRC_DIR := src
TARGET := $(SRC_DIR)/metnum$(shell python3-config --extension-suffix)

CXX := g++
CXXFLAGS := -O3 -Wall -shared -std=c++14 -fPIC $(PYBIND11_INCLUDE) $(PYTHON_INCLUDE) -I$(EIGEN_INCLUDE)
LDFLAGS := $(PYTHON_LIB)

SRC_FILES := $(SRC_DIR)/metodos.cpp $(SRC_DIR)/test_integration.cpp

all: $(TARGET)

$(TARGET): $(SRC_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGET)
