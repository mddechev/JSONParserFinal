#include "../../includes/utility//Helpers.hpp"

namespace helpers {
    Vector<String> tokenizeLineToStrings(const String& line, char delimiter) {
        Vector<String> result;
        String current;
        for (size_t i = 0; i < line.Length(); i++) {
            if (line[i] == delimiter) {
                if (!current.IsEmpty()) {
                    result.PushBack(current);
                    current.Reuse();
                } 
            } else {
                current += line[i];
            }
        }

        if (!current.IsEmpty()) {
            result.PushBack(current);
        }
    return result;
    }
   
    void getLine(std::istream& inputStream, String& result, size_t length, const char delimiter) {
        result.Reuse();
        char ch;
        size_t count = 0;

        while (count < length && inputStream.get(ch) && ch != delimiter) {
            result += ch;
            ++count;
        }    
    }

    // void printInfo(std::ostream& outputStream) {
    //     outputStream << "...LIST OF COMMANDS..." << "\n\n"
    //     << "validate path/to/file/file_name"     << "     "   
    //     << "open path/file/to/file/file_name"    << "     " << "\n\n"
    //     << "print"                               << "\n\n"
    //     << "set path/to/key value"               << "     "
    //     << "create path/creaton_key  value"      << "     "
    //     << "remove path/to/key"                  << "     " << "\n\n"
    //     << "save"                                << "     "
    //     << "saveas path/to/file/file_name"       << "     " << "\n\n"
    //     << "close"                               << "     "
    //     << "exit"                                << '\n'
    //     << "------------------------------"      << '\n';
    // }
    void printInfo(std::ostream& outputStream) {
        outputStream << "\n╔═════════════════ JSON PARSER COMMANDS ════════════════╗\n"
                     <<   "║                                                       ║\n"
                     <<   "║ validate <path/to/file>  open <path/to/file>          ║\n"
                     <<   "║ print                    set <path/to/value> <value>  ║\n"
                     <<   "║ create <path> <value>    delete <path/to/value>       ║\n"
                     <<   "║ save                     saveas <path/to/file>        ║\n"
                     <<   "║ close                    exit                         ║\n"
                     <<   "╚═══════════════════════════════════════════════════════╝\n\n";
    }
}