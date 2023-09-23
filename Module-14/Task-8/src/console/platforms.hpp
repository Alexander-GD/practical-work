#pragma once

/* This file contains all the platform specific code regarding terminal. */

#ifdef _WIN32
// The WIN_VER macro is defined in the project's cmake build file.
#if   (WIN_VER >= 22000) /* Windows 11 */
#elif (WIN_VER >= 10586) /* Windows 10 */
#include <windows.h>

class VirtualTerminalSequences
{
public:
    VirtualTerminalSequences() { EnableVTMode(); }

private:
    // Enable virtual terminal processing mode to use escape sequences.
    bool EnableVTMode()
    {
        // Set output mode to handle virtual terminal sequences.
        DWORD dwOriginalOutMode = 0;
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

        if (hOut == INVALID_HANDLE_VALUE ||
            !GetConsoleMode(hOut, &dwOriginalOutMode) ||
            !SetConsoleMode(hOut, dwOriginalOutMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING))
            return false;

        return true;
    }
};

static VirtualTerminalSequences EnableVTMode;
#else
#error This version of Windows does not support ANSI escape sequences.
#endif
#endif
