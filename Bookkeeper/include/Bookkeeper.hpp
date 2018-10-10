#ifndef BOOKKEEPER_HPP
#define BOOKKEEPER_HPP

#include "Helper.hpp"
#include <math.h>

class Bookkeeper {
    public:
        double calculateExpression(const std::string& expression) const;
    private:
        Helper mHelper;
};

#endif
