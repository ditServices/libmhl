//
// Created by Howard Colin on 09/08/2023.
//

#ifndef LIBMHL_CHAINFILE_H
#define LIBMHL_CHAINFILE_H

/*
 * MHL CHAIN FILE
 * This class is the root class that manages the ChainFile.
 * It contains Chain object which handles the main body of the chain file
 * and a further subclass that handles each element of generations within
 * the chain file.
 *
 * This class will be managed by an MHL History class.
 */

#include "Chain.h"
#include <pugixml.hpp>

namespace MHL {
    class ChainFile {
    private:
        fs::path mChainFilePath; // the full path to the chain file that we are parsing
        MHL::Chain mChain; // our object that will hold our parsed data
        pugi::xml_document mChainXMLFile; // our XML processing instance
    public:
        ChainFile(fs::path &mhlSourceChainFilePath)
            : mChainFilePath(mhlSourceChainFilePath), mChain(mhlSourceChainFilePath) {

        }

        // the individual chain object manages each generation. Generations are a stored within a vector of ChainGeneration objects.
        int parse(const fs::path &file_name);
    };
}

#endif //LIBMHL_CHAINFILE_H
