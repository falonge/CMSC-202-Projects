CXX = g++
CXXFLAGS = -Wall

lab10: Song.o lab10.cpp
	$(CXX) $(CXXFLAGS) Song.o lab10.cpp -o lab10
Song.o: Song.cpp Song.h
	$(CXX) $(CXXFLAGS) -c Song.cpp
clean:
	rm *.o*
	rm *~
run:
	./lab10
