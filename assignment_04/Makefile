# Compiler settings
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++14

TARGET = driver_app

# List of source files
SRCS = driver/driver.cpp src/fastMap.cpp ../utility/testing_utils.cpp ../utility/csr.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) driver_app.exe