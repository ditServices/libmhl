//
// Created by Howard Colin on 09/08/2023.
//

#include "Chain.h"

void MHL::Chain::append_generation(std::shared_ptr<ChainGeneration> &generation) {
    this->mGenerations.push_back(generation);
}
