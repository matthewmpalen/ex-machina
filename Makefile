all: BlueBookCpp BlueBookJava BlueBookGo

BlueBookCpp:
	g++ -Wall -g -std=c++11 BlueBook.cpp -o BlueBookCpp

BlueBookJava:
	javac BlueBook.java

BlueBookGo:
	go build -o bluebook_go bluebook.go
