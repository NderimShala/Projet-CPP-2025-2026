.SILENT:
HEADERS=./Headers/
OBJETS=./Objets/
SOURCES=./Sources/

Test4 : $(SOURCES)Test4.cpp $(OBJETS)Person.o $(OBJETS)Client.o $(OBJETS)Actor.o
	echo Création de Test4
	g++ $(SOURCES)Test4.cpp -I $(HEADERS) $(OBJETS)Person.o $(OBJETS)Client.o $(OBJETS)Actor.o -o Test4

$(OBJETS)Person.o : $(HEADERS)Person.h $(SOURCES)Person.cpp
	echo Création de Person.o
	g++ -c $(SOURCES)Person.cpp -I $(HEADERS) -o $(OBJETS)Person.o

$(OBJETS)Actor.o : $(HEADERS)Actor.h $(SOURCES)Actor.cpp
	echo Création de Actor.o
	g++ -c $(SOURCES)Actor.cpp -I $(HEADERS) -o $(OBJETS)Actor.o

$(OBJETS)Client.o : $(HEADERS)Client.h $(SOURCES)Client.cpp
	echo Création de Client.o
	g++ -c $(SOURCES)Client.cpp -I $(HEADERS) -o $(OBJETS)Client.o