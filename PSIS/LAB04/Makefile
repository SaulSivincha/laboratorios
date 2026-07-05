CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
TARGETS = exercise5 exercise6 browser_history

all: $(TARGETS)

exercise5: exercise5.cpp
	$(CXX) $(CXXFLAGS) exercise5.cpp -o exercise5

exercise6: exercise6.cpp
	$(CXX) $(CXXFLAGS) exercise6.cpp -o exercise6

browser_history: browser_history.cpp
	$(CXX) $(CXXFLAGS) browser_history.cpp -o browser_history

run5: exercise5
	./exercise5

run6: exercise6
	./exercise6

run_history: browser_history
	./browser_history

clean:
	rm -f $(TARGETS)

.PHONY: all run5 run6 run_history clean
