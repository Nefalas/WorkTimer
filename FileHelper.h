//
// Created by nefalas on 2019-10-08.
//

#ifndef WORKTIMER_FILEHELPER_H
#define WORKTIMER_FILEHELPER_H

class FileHelper {
public:
    FileHelper();
    void initLogDir();

private:
    static const char* ROOT_DIR_NAME;
    const char* ROOT_DIR_PATH{};
};


#endif //WORKTIMER_FILEHELPER_H
