#include "common.h"
#include "fmt/format.h"

namespace example {
    std::string ToString(const int &t) {
        return fmt::format("{}", t);
    }
}
