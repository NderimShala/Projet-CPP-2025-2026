.SILENT:
HEADERS=./Headers/
OBJETS=./Objets/
SOURCES=./Sources/

Test2b:	$(SOURCES)Test2b.cpp $(OBJETS)Option.o
	echo Création de Test2b
	g++ $(SOURCES)Test2b.cpp $(OBJETS)Option.o -o Test2b

$(OBJETS)Option.o: $(SOURCES)Option.cpp $(HEADERS)Option.h
	echo Création de Option.o
	g++ -c $(SOURCES)Option.cpp -o $(OBJETS)Option.o