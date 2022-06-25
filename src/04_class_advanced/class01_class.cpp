#include <iostream>

#define LOG(x) std::cout << x << std::endl


class Log
{
public:
    const int LogLevelError = 0;
    const int LogLevelWarning = 1;
    const int LogLevelInfo = 2;
private:
    int m_LogLevel = LogLevelInfo;

public:

    void SetLevel(int level)
    {
        m_LogLevel = level;
    }

    void Error(const char* message)
    {
        if(m_LogLevel >= LogLevelError)
            std::cout << "[ERROR] " << message << std::endl;
    }

    void Warn(const char* message)
    {
        if(m_LogLevel >= LogLevelWarning)
            std::cout << "[WARNING] " << message << std::endl;
    }
    
    void Info(const char* message)
    {
        if(m_LogLevel >= LogLevelInfo)
            std::cout << "[INFO] "<< message << std::endl;
    }


};

int main()
{
    Log log;

    /*
        A good way to know what your class should have when it comes to functionalities is to firt write what you think you should have
        even before you have implementes them inside your class

        We want a log class. that is able to log messages according to a specific level of importance

        So we want something like this

        log.SetLevel(LogLevelWarning); //sets the priority level to Warning level
        log.Warn("hello!"); //prints the specified message
    */

    log.SetLevel(log.LogLevelWarning);
    log.Warn("hello!");

}