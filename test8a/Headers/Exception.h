#ifndef EXCEPTION
#define EXCEPTION   

#include <cstring>
#include <iostream>

using namespace std;

namespace carconfig
{
    class Exception
    {
        protected:
            string message;

        public:
            Exception();
            Exception(string m);
            Exception(Exception& e);
            virtual ~Exception();

            void setMessage(const string m);
            string getMessage() const;
    };
   
}

#endif