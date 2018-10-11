#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include "Bookkeeper.hpp"
#include "FileManager.hpp"
#include "Parser.hpp"

class Calculator {
    public:
        void startCalculation();
    private:
        Bookkeeper mBookkeeper;
        Parser mParser;
        FileManager mFileManager;
};

#endif
