.SILENT:
HEADERS=./Headers/
OBJETS=./Objets/
SOURCES=./Sources/

Test2a : $(SOURCES)Test2a.cpp $(OBJETS)Car.o $(OBJETS)Model.o
	echo Création de Test2a
	g++ $(SOURCES)Test2a.cpp -I $(HEADERS) $(OBJETS)Car.o $(OBJETS)Model.o -o Test2a

$(OBJETS)Car.o : $(HEADERS)Car.h $(SOURCES)Car.cpp $(OBJETS)Model.o
	echo Création de Car.o
	g++ -c $(SOURCES)Car.cpp -I $(HEADERS) -o $(OBJETS)Car.o

$(OBJETS)Model.o : $(SOURCES)Model.cpp $(HEADERS)Model.h
	echo Création de Model.o
	g++ -c $(SOURCES)Model.cpp -I $(HEADERS) -o $(OBJETS)Model.o