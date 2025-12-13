.SILENT:
HEADERS=./Headers/
OBJETS=./Objets/
SOURCES=./Sources/
TEMP=./Template/

Test7 : $(SOURCES)Test7.cpp $(OBJETS)Person.o $(OBJETS)Client.o $(OBJETS)Actor.o $(OBJETS)Employee.o $(OBJETS)Car.o $(OBJETS)Model.o $(OBJETS)Option.o $(OBJETS)OptionException.o $(OBJETS)Exception.o $(OBJETS)PasswordException.o $(OBJETS)XmlFileSerializerException.o
	echo Création de Test7
	g++ $(SOURCES)Test7.cpp -I $(HEADERS) $(OBJETS)Person.o $(OBJETS)Client.o $(OBJETS)Actor.o $(OBJETS)Employee.o $(OBJETS)Car.o $(OBJETS)Model.o $(OBJETS)Option.o $(OBJETS)OptionException.o $(OBJETS)Exception.o $(OBJETS)PasswordException.o $(OBJETS)XmlFileSerializerException.o -I $(TEMP) -o Test7

$(OBJETS)Person.o : $(HEADERS)Person.h $(SOURCES)Person.cpp
	echo Création de Person.o
	g++ -c $(SOURCES)Person.cpp -I $(HEADERS) -o $(OBJETS)Person.o

$(OBJETS)Actor.o : $(HEADERS)Actor.h $(SOURCES)Actor.cpp
	echo Création de Actor.o
	g++ -c $(SOURCES)Actor.cpp -I $(HEADERS) -o $(OBJETS)Actor.o

$(OBJETS)Client.o : $(HEADERS)Client.h $(SOURCES)Client.cpp
	echo Création de Client.o
	g++ -c $(SOURCES)Client.cpp -I $(HEADERS) -o $(OBJETS)Client.o

$(OBJETS)Employee.o :	$(HEADERS)Employee.h $(SOURCES)Employee.cpp
	echo Création de Employee.OBJETS
	g++ -c $(SOURCES)Employee.cpp -I $(HEADERS) -o $(OBJETS)Employee.o

$(OBJETS)Car.o : $(HEADERS)Car.h $(SOURCES)Car.cpp
	echo Création de Car.o
	g++ -c $(SOURCES)Car.cpp -I $(HEADERS) -o $(OBJETS)Car.o

$(OBJETS)Model.o : $(SOURCES)Model.cpp $(HEADERS)Model.h
	echo Création de Model.o
	g++ -c $(SOURCES)Model.cpp -I $(HEADERS) -o $(OBJETS)Model.o

$(OBJETS)Option.o : $(SOURCES)Option.cpp $(HEADERS)Option.h
	echo Création de Option.o
	g++ -c $(SOURCES)Option.cpp -I $(HEADERS) -o $(OBJETS)Option.o

$(OBJETS)OptionException.o : $(SOURCES)OptionException.cpp $(HEADERS)OptionException.h
	echo Création de OptionException.o
	g++ -c $(SOURCES)OptionException.cpp -I $(HEADERS) -o $(OBJETS)OptionException.o

$(OBJETS)Exception.o : $(SOURCES)Exception.cpp $(HEADERS)Exception.h
	echo Création de Exception.o
	g++ -c $(SOURCES)Exception.cpp -I $(HEADERS) -o $(OBJETS)Exception.o

$(OBJETS)PasswordException.o : $(SOURCES)PasswordException.cpp $(HEADERS)PasswordException.h
	echo Création de PasswordException.o
	g++ -c $(SOURCES)PasswordException.cpp -I $(HEADERS) -o $(OBJETS)PasswordException.o


$(OBJETS)XmlFileSerializerException.o : $(SOURCES)XmlFileSerializerException.cpp $(HEADERS)XmlFileSerializerException.h
	echo Création de XmlFileSerializerException.o
	g++ -c $(SOURCES)XmlFileSerializerException.cpp -I $(HEADERS) -o $(OBJETS)XmlFileSerializerException.o