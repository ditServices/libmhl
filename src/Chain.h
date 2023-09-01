//
// Created by Howard Colin on 09/08/2023.
//

#ifndef LIBMHL_CHAIN_H
#define LIBMHL_CHAIN_H

/*
 * MHL CHAIN
 * This class is responsible for managing the chain file contents.
 * Data that is parsed in ChainFile is stored in the Chain class. Each Generation
 * then stored in the ChainGeneration class.
 *
 */

#include <filesystem>
#include <vector>
#include "ChainGeneration.h"

namespace fs = std::filesystem;

namespace MHL {
    class Chain {
        private:
            fs::path mFileName; // file name of the chain file taken from full path, via constructor.
            std::vector<std::shared_ptr<ChainGeneration>> mGenerations; // our vector that manages parsed generation data.
        public:
            explicit Chain(fs::path &mhlChainFilePath)
                : mFileName(mhlChainFilePath.filename()) {}
            void append_generation(std::shared_ptr<ChainGeneration> &generation);
    };
}

#endif //LIBMHL_CHAIN_H
