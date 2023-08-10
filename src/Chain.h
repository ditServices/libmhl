//
// Created by Howard Colin on 09/08/2023.
//

#ifndef LIBMHL_CHAIN_H
#define LIBMHL_CHAIN_H

#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

namespace MHL {
    class ChainGeneration {
    private:
        int mGenerationNumber;
        fs::path mASCMHLFileName;
        std::string mHashFormat;
        std::string mHashString;
    public:
    };

    class Chain {
        private:
            fs::path mFilePath;
            std::vector<ChainGeneration> mGenerations;
        public:
            void append_generation(ChainGeneration *generation);
    };
}

#endif //LIBMHL_CHAIN_H
