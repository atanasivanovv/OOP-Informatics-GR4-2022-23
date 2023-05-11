#include "Vector.h";

class VectorComp {
private:
    Vector vector;
public:
    VectorComp(const Vector& other) : vector(other) {} 
    VectorComp(Vector&& other) : vector(std::move(other)) {} 
};