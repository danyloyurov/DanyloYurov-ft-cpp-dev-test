#ifndef BOOKKEEPER_HPP
#define BOOKKEEPER_HPP

class Bookkeeper {
    public:
        double calculateExpression(const std::string& expression) const;
    private:
        std::string mLastExpression;
};

#endif
