#ifndef BOOKKEEPER_HPP_
#define BOOKKEEPER_HPP_

#include "helper.hpp"
#include <math.h>

class Bookkeeper {
    public:
        double CalculateExpression(const std::string& expression) const;
    private:
        Helper helper_;
};

#endif // BOOKKEEPER_HPP_
