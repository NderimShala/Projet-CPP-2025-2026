.SILENT:
HEADERS=./Headers/
OBJETS=./Objets/
SOURCES=./Sources/

Test4 : $(SOURCES)Test4.cpp $(OBJETS)Person.o
	echo Création de Test4
	g++ $(SOURCES)Test4.cpp -I $(HEADERS) $(OBJETS)Person.o -o Test4

$(OBJETS)Person.o : $(HEADERS)Person.h $(SOURCES)Person.cpp
	echo Création de Person.o
	g++ -c $(SOURCES)Person.cpp -I $(HEADERS) -o $(OBJETS)Person.o