#include <cstdlib>
#include <exception>
#include <cstdio>
#include "FileHelper.h"

using namespace std;

struct HomeNotFoundException : public exception {
    const char* what() const noexcept override {
        return "Could not find HOME directory";
    }
};

const char* FileHelper::ROOT_DIR_NAME = "WorkTimer";

FileHelper::FileHelper() {

    char* home = getenv("HOME");
    if (home == nullptr) {
        throw HomeNotFoundException();
    }
    char path[150];
    snprintf(path, sizeof(path), "%s/%s", home, FileHelper::ROOT_DIR_NAME);

    FileHelper::ROOT_DIR_PATH = path;
}

void FileHelper::initLogDir() {

}