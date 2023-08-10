//
// Created by Howard Colin on 09/08/2023.
//

#ifndef LIBMHL_CHAIN_H
#define LIBMHL_CHAIN_H

#include <filesystem>
#include <vector>
#include "ChainGeneration.h"

namespace fs = std::filesystem;

namespace MHL {

    class Chain {
        private:
            fs::path mFilePath;
            std::vector<ChainGeneration> mGenerations;
        public:
            void append_generation(ChainGeneration *generation);
    };
}

#endif //LIBMHL_CHAIN_H
