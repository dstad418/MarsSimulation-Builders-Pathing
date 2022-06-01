output: builders.o builder.o linkedList.o stack.o events.o
	g++ builders.o builderImp.o linkedListImp.o stackImp.o eventsImp.o structuretype.cpp structuretype.h -o output 

builders.o: builders.cpp
	g++ -c builders.cpp

builder.o: builderImp.cpp builder.h
	g++ -c builderImp.cpp

linkedList.o: linkedListImp.cpp linkedList.h
	g++ -c linkedListImp.cpp

stack.o: stackImp.cpp stack.h
	g++ -c stackImp.cpp

events.o: eventsImp.cpp events.h
	g++ -c eventsImp.cpp

clean: 
	rm *.o output
