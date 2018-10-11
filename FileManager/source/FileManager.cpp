#include "FileManager.hpp"

#include <bits/stdc++.h> 
#include <iostream>
#include <fstream>

bool FileManager::readFile(const std::string& path, const std::string& name, std::string& data_buffer) {
    std::ifstream in;

    if(path != ".")
         this->getHoldOfFile(path, name);

    in.open(name);

    if (!in.is_open()) {
        std::cout << "[ERROR] Can't open file to read!" << std::endl;
        return false;
    }

    getline(in, data_buffer);
    in.close();

    return true;
}

bool FileManager::writeFile(const std::string& path, const std::string& name, const std::string& data) const {
    std::ofstream out;

    out.open(name);

    if (!out.is_open()) {
        std::cout << "[ERROR] Can't open file to write!" << std::endl;
        return false;
    }

    out << data;
    out.close();

    if(path != ".")
        this->releaseHoldOfFile(path, name);

    return false;
}

void FileManager::getHoldOfFile(const std::string& path, const std::string& name) const {
    std::string command = ("mv " + ( *path.end() == '/' ? path : path + "/" ) + name + " .");
    system(command.c_str());
}

void FileManager::releaseHoldOfFile(const std::string& path, const std::string& name) const {
    std::string command = ("mv " + name + " " + ( *path.end() == '/' ? path : path + "/" ) + name);
    system(command.c_str());
}
