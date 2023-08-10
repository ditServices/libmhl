//
// Created by Howard Colin on 09/08/2023.
//

#ifndef LIBMHL_CHAINFILE_H
#define LIBMHL_CHAINFILE_H

#include "Chain.h"
#include <pugixml.hpp>

namespace MHL {
    class ChainFile {
    private:
        fs::path mChainFilePath;
        MHL::Chain mChain;
        pugi::xml_document mChainXMLFile;
        int parse();
    public:
        int write(const fs::path *file_name);
    };
}

#endif //LIBMHL_CHAINFILE_H
