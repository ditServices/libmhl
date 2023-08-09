//
// Created by Howard Colin on 09/08/2023.
//

#ifndef LIBMHL_IGNORESPEC_H
#define LIBMHL_IGNORESPEC_H

#include <string>
#include <vector>

namespace MHL {
    class IgnoreSpec {
    private:
        std::vector<std::string> mIgnoreList;
        static inline int check_pattern_len(std::string *pattern);
    public:
        explicit IgnoreSpec(std::vector<std::string> *pattern_list);
        int add_pattern(std::string *pattern);
    };
}


#endif //LIBMHL_IGNORESPEC_H
