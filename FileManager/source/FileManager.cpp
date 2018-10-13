#include "FileManager.hpp"

#include <bits/stdc++.h> 
#include <iostream>
#include <fstream>

bool FileManager::readFile(const std::string& path, const std::string& name, std::string& data_buffer) {
    std::ifstream in;

    if(path != ".")
         this->getHoldOfFile(path, name);

    in.open(name);

    if (!in.is_open())
        return false;

    getline(in, data_buffer);
    in.close();

    if(path != ".")
        this->releaseHoldOfFile(name);

    return true;
}

void FileManager::getHoldOfFile(const std::string& path, const std::string& name) const {
    std::string command = ("cp " + ( *path.end() == '/' ? path : path + "/" ) + name + " .");
    system(command.c_str());
}

void FileManager::releaseHoldOfFile(const std::string& name) const {
    std::string command = "rm " + name;
    system(command.c_str());
}
