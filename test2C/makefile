.SILENT:
HEADERS=./Headers/
OBJETS=./Objets/
SOURCES=./Sources/

Test2c : $(SOURCES)Test2c.cpp $(OBJETS)Car.o $(OBJETS)Model.o $(OBJETS)Option.o
	echo Création de Test2c
	g++ $(SOURCES)Test2c.cpp -I $(HEADERS) $(OBJETS)Car.o $(OBJETS)Model.o $(OBJETS)Option.o -o Test2c

$(OBJETS)Car.o : $(HEADERS)Car.h $(SOURCES)Car.cpp $(OBJETS)Model.o $(OBJETS)Option.o
	echo Création de Car.o
	g++ -c $(SOURCES)Car.cpp -I $(HEADERS) -o $(OBJETS)Car.o $(OBJETS)Option.o

$(OBJETS)Model.o : $(SOURCES)Model.cpp $(HEADERS)Model.h
	echo Création de Model.o
	g++ -c $(SOURCES)Model.cpp -I $(HEADERS) -o $(OBJETS)Model.o

$(OBJETS)Option.o : $(SOURCES)Option.cpp $(HEADERS)Option.h
	echo Création de Option.o
	g++ -c $(SOURCES)Option.cpp -I $(HEADERS) -o $(OBJETS)Option.o