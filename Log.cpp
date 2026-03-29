
#include "Log.h"

namespace Violet {

    void Log::warning(bool error_condition, Concern concern, std::string info) {
        std::string message = elaborate(concern);
        std::cerr << "\nWarning: " << message << '\n';
        if (info != "") std::cerr << "Info: " << info << '\n';
        std::terminate();
    }
    
    std::string Log::elaborate(Concern concern) {
        switch (concern) {
            case NO_GLFW_CONTEXT: return "No GLFW context has yet been created!"; break;
            default: return "";
        }
    }
}

