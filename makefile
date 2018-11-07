CC = g++ -std=c++14
CFLAGS = -Wextra -Wall -pedantic

%: mc_dlog.cpp test%.cpp HashTable.h HashNode.h
	$(CC) $(CFLAGS) -o hash mc_dlog.cpp test$*.cpp

clean:
	rm hash
