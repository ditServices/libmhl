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

    for(const auto& hashlist_entry : this->mChainXMLFile.child("ascmhldirectory")) {
        int generation = hashlist_entry.attribute("sequencenr").as_int();
        std::cout << generation << std::endl;
        for(const auto& entry : hashlist_entry) {
            std::cout << entry.name() << ": " << entry.child_value() << std::endl;
        }
    }


    return 0;
}

pugi::xml_node MHL::ChainFile::get_first_node() {
    return this->mChainXMLFile.first_child();
}




