//
// Created by Howard Colin on 09/08/2023.
//

#include "ChainFile.h"
#include <iostream>

int MHL::ChainFile::parse(const fs::path &file_name) {
    pugi::xml_parse_result result = this->mChainXMLFile.load_file(file_name.c_str());
    if(!result) {
        return 1;
    }

    /*
     * Iterate over the Chainfile hashlist elements and populate our Chain object with append_element().
     * Each generation is stored in a vector within the Chain object.
     */

    try {
        std::string hashtype = "c4"; // TODO unsure if need to account for different hash types in mhl chain

        for (const auto &hashlist_entry: this->mChainXMLFile.child("ascmhldirectory")) {
            int generation = hashlist_entry.attribute("sequencenr").as_int();

            pugi::xml_node chPath = hashlist_entry.select_node("path").node();
            std::string path = chPath.child_value();

            pugi::xml_node chHash = hashlist_entry.select_node("c4").node();
            std::string hash = chHash.child_value();

            std::shared_ptr<ChainGeneration> mhlGeneration = std::make_shared<ChainGeneration>(generation, path,
                                                                                               hashtype, hash);
            this->mChain.append_generation(mhlGeneration);
        }
    } catch(pugi::xpath_exception &e) {
        return 1;
    }

    return 0;
}



