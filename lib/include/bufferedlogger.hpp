/*
 * Setup and Interface for a multifile based, buffered Logger.
 */

#include "string"

namespace Logging
{

    // For example color enum.
    enum class LogLevel
    {
        EMERGENCY = 1,
        ALTERT = 2,
        CRITICAL = 3,
        ERROR = 4,
        WARNING = 5,
        NOTICE = 6,
        INFO = 7,
        DEBUG = 8,
        VERBOSE = 9,
        DEFAULT = 10,

    };

    class BufferedLogger
    {
        public:
        BufferedLogger();

        void SetLogFile(std::string f);
        void PrintAboveLevel(LogLevel l);
        
    };

};