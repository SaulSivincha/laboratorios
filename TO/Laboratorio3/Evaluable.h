#ifndef EVALUABLE_H
#define EVALUABLE_H

class Evaluable
{
public:
    virtual ~Evaluable() = default;
    virtual double calcularNota() const = 0;
};

#endif
