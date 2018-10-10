#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <string>

class FileManager {
    public:
        void readFile(const std::string& path, std::string data_buffer);
        void writeFile(const std::string& path, const std::string& data) const;
    private:
        std::string mLastFile;
};

#endif
