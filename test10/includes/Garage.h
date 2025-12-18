#include <iostream>
#include <set>
#include <list>
#include <sstream>

#include "Client.h"
#include "Employee.h"
#include "Model.h"
#include "Option.h"
#include "Car.h"

using namespace std;
using namespace carconfig;
class Garage
{
    private:
        set<Employee> employees;
        set<Client> clients;
        list<Model> models;
        list<Option> options;

        Garage() = default;
        static Garage instance;
        static Car currentProject; /////

        int nombreModelsCsv;
        int nombreOptionsCsv;

    public:
        
        Garage(const Garage& g) = delete;
        ~Garage() = default;

        void addModel(const Model& m);
        void displayAllModels() const;
        Model getModel(int index) const;
        
        void addOption(const Option& o);
        void displayAllOptions() const;
        Option getOption(int index) const;

        int addClient(string lastName, string firstName, string gsm);
        void displayClients() const;
        void deleteClientByIndex(int index);
        void deleteClientById(int id);
        Client findClientByIndex(int index) const;
        Client findClientById(int id) const;

        int addEmployee(string lastName, string firstName, string login, string role);
        void displayEmployees() const;
        void deleteEmployeeByIndex(int index);
        void deleteEmployeeById(int id);
        Employee findEmployeeByIndex(int index) const;
        Employee findEmployeeById(int id) const;

        Garage& operator=(const Garage& g) = delete;

        static Garage& getInstance(); /////
        static Car& getCurrentProject();
        static void resetCurrentProject();

        void importModelsFromCsv(string filename);
        void importOptionsFromCsv(string filename);

        void setNbrModelsCsv(int i);
        int getNbrModelsCsv() const;
        void setNbrOptionsCsv(int i);
        int getNbrOptionsCsv() const;

};   

