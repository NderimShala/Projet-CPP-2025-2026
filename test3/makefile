.SILENT:
HEADERS=./Headers/
OBJETS=./Objets/
SOURCES=./Sources/

Test3 : $(SOURCES)Test3.cpp $(OBJETS)Car.o $(OBJETS)Model.o $(OBJETS)Option.o
	echo Création de Test3
	g++ $(SOURCES)Test3.cpp -I $(HEADERS) $(OBJETS)Car.o $(OBJETS)Model.o $(OBJETS)Option.o -o Test3

$(OBJETS)Car.o : $(HEADERS)Car.h $(SOURCES)Car.cpp
	echo Création de Car.o
	g++ -c $(SOURCES)Car.cpp -I $(HEADERS) -o $(OBJETS)Car.o

$(OBJETS)Model.o : $(SOURCES)Model.cpp $(HEADERS)Model.h
	echo Création de Model.o
	g++ -c $(SOURCES)Model.cpp -I $(HEADERS) -o $(OBJETS)Model.o

$(OBJETS)Option.o : $(SOURCES)Option.cpp $(HEADERS)Option.h
	echo Création de Option.o
	g++ -c $(SOURCES)Option.cpp -I $(HEADERS) -o $(OBJETS)Option.o