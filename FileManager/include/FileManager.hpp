#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <string>

class FileManager {
    public:
        bool readFile(const std::string& path, const std::string& name, std::string& data_buffer);
    private:
        void getHoldOfFile(const std::string& path, const std::string& name) const;
        void releaseHoldOfFile(const std::string& name) const;
};

#endif
