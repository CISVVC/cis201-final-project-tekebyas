#
all: main


main : *.cpp
	@g++ -o main -std=c++11 *.cpp 

run : main
	@echo "Running the program:"
	@./main alice.txt

edit:
	@vim main.cpp

debug:
	@gdb ./main

clean :
	@rm main
