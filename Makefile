dictionary: Dictionary.o DictionaryApp.o
	g++ -o dictionary Dictionary.o DictionaryApp.o
Dictionary.o: Dictionary.cpp
	g++ -c Dictionary.cpp
DictionaryApp.o: DictionaryApp.cpp
	g++ -c DictionaryApp.cpp
clean:
	rm dictionary *.o
