//
// Created by Howard Colin on 10/08/2023.
//

#ifndef LIBMHL_CHAINGENERATION_H
#define LIBMHL_CHAINGENERATION_H

#include <filesystem>

namespace fs = std::filesystem;

namespace MHL {
    class ChainGeneration {
    private:
        int mGenerationNumber; // generation number
        fs::path mASCMHLFileName; // the file name of the linked MHL for the current generation
        std::string mHashFormat;  // the has format used in the chain file
        std::string mHashString;  // the string of the calculated hash
    public:
        ChainGeneration(int mhlGenNumber, std::string &mhlFileName, std::string &mhlHashFormat, std::string &mhlHash)
                : mGenerationNumber(mhlGenNumber), mASCMHLFileName(mhlFileName), mHashFormat(mhlHashFormat),
                  mHashString(mhlHash) {

        }
    };
}
#endif //LIBMHL_CHAINGENERATION_H
