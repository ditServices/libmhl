//
// Created by Howard Colin on 09/08/2023.
//

#include "ChainFile.h"

int MHL::ChainFile::parse() {
    pugi::xml_parse_result result = this->mChainXMLFile.load_file(this->mChainFilePath.c_str());
    if(!result) throw std::runtime_error("Error opening file");

//    for(const auto& child : result.child("root-element")) {
//        cout << child.child_value() << std::endl;
//    }

    return 0;
}

int MHL::ChainFile::write(const fs::path *file_name) {
    return 0;
}




