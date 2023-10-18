//
// Created by Howard Colin on 15/08/2023.
//

#include "HashList.h"


/*
 * HashEntry class function definitions.
 */

// TODO: Extract data from xml node hash and return the hash, hash format, action and date in one structure.

MHL::HashData MHL::HashEntry::p_c4(pugi::xml_node hash) {
    return {};
}

MHL::HashData MHL::HashEntry::p_md5(pugi::xml_node hash) {
    return {};
}

MHL::HashData MHL::HashEntry::p_sha1(pugi::xml_node hash) {
    return {};
}

MHL::HashData MHL::HashEntry::p_xxh128(pugi::xml_node hash) {
    return {};
}

MHL::HashData MHL::HashEntry::p_xxh3(pugi::xml_node hash) {
    return {};
}

MHL::HashData MHL::HashEntry::p_xxh64(pugi::xml_node hash) {
    return {};
}
