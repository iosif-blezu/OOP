#pragma once
#include "MemoryRepository.h"
#include "fstream"


class FileRepository :
        public MmeoryRepository
{
private:
    std::string filename;
    void loadFromFile();

public:
    FileRepository();
    FileRepository(const std::string& filename) {this->filename = filename; loadFromFile();}
    FileRepository(const FileRepository& otherRepo);
    ~FileRepository();

    void saveToFile();
};