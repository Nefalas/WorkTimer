//
// Created by nefalas on 2019-10-08.
//

#ifndef WORKTIMER_FILEHELPER_H
#define WORKTIMER_FILEHELPER_H

#include <string>

class FileHelper {
public:
    FileHelper();

private:
    static const char* ROOT_DIR_NAME;
    static const char* LOG_FILE_NAME;
    std::string ROOT_DIR_PATH;
    std::string LOG_FILE_PATH;
    void setupRootDirPath();
    void setupFilePaths();
    void initLogDir();
    void initFiles();
    static bool directoryExists(std::string path);
    static bool fileExists(std::string path);
};


#endif //WORKTIMER_FILEHELPER_H
