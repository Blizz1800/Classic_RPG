#include "Object.h"

#include <random>

using namespace std;

Object::Object()
{
    this->name = "Object";
    this->id = rand();
}

Object::~Object()
{
    //dtor
}
