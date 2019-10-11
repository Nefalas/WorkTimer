#include <cstdlib>
#include <exception>
#include <sys/stat.h>
#include <fstream>
#include <iostream>
#include "FileHelper.h"

using namespace std;

struct HomeNotFoundException : public exception {
    const char* what() const noexcept override {
        return "Could not find HOME directory";
    }
};

const char* FileHelper::ROOT_DIR_NAME = "WorkTimer";
const char* FileHelper::LOG_FILE_NAME = "times.log";

FileHelper::FileHelper() {
    this->setupRootDirPath();
    this->setupFilePaths();
    this->initLogDir();
    this->initFiles();
}

void FileHelper::setupRootDirPath() {
    char* home = getenv("HOME");
    if (home == nullptr) {
        throw HomeNotFoundException();
    }
    string path;
    path += home;
    path += '/';
    path += FileHelper::ROOT_DIR_NAME;
    this->ROOT_DIR_PATH = path;
}

void FileHelper::setupFilePaths() {
    string logFilePath;
    logFilePath += this->ROOT_DIR_PATH;
    logFilePath += '/';
    logFilePath += FileHelper::LOG_FILE_NAME;
    this->LOG_FILE_PATH = logFilePath;
}

void FileHelper::initLogDir() {
    if (!FileHelper::directoryExists(this->ROOT_DIR_PATH)) {
        mkdir(this->ROOT_DIR_PATH.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    }
}

void FileHelper::initFiles() {
    if (!FileHelper::fileExists(this->LOG_FILE_PATH)) {
        ofstream file { this->LOG_FILE_PATH };
    }
}

bool FileHelper::directoryExists(string path) {
    struct stat statBuffer;
    if (stat(path.c_str(), &statBuffer) != -1) {
        if (S_ISDIR(statBuffer.st_mode)) {
            return true;
        }
    }
    return false;
}

bool FileHelper::fileExists(string path) {
    struct stat statBuffer;
    return stat(path.c_str(), &statBuffer) == 0;
}
