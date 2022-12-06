#ifndef OBJECT_H
#define OBJECT_H

#include "ventizca.hpp"

class Object
{
public:

    Object();
    virtual ~Object();

    friend std::ostream &operator<<(std::ostream& out, Object o)
    {
        out << "<" << &o << " " << o.id << " " << o.name << ">" << std::endl;
        return out;
    }


protected:

    std::string name;
    unsigned long long id;

private:
};

#endif // OBJECT_H
