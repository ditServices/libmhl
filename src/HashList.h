//
// Created by Howard Colin on 15/08/2023.
//

#ifndef LIBMHL_HASHLIST_H
#define LIBMHL_HASHLIST_H

#include "Utils.h"
#include "IgnoreSpec.h"
#include "pugixml.hpp"

#include <map>

/*
 * Contains classes that represent the elemets of the MHL file
 */
namespace MHL {

    //class that holds the parsing and data for managing the author element of the MHL file
    class MHLAuthor {
    private:
        std::string mAuthorName;  //required
        std::string mAuthorEmail; //optional
        std::string mAuthorRole;  //optional
        std::string mAuthorPhone; //optional
        pugi::xml_node mXMLAuthor;
    public:
        MHLAuthor(std::string &author_name, std::string &author_email, std::string &author_role, std::string &author_phone) :
            mAuthorName(author_name), mAuthorEmail(author_email), mAuthorRole(author_role), mAuthorPhone(author_phone) {
            // create author node
        };

        explicit MHLAuthor(pugi::xml_node author_node) :
            mXMLAuthor(author_node) {

            this->mAuthorName = mXMLAuthor.select_node("name").node().child_value(); //needs to fail if no author provided?

            if(pugi::xml_node role = mXMLAuthor.select_node("role").node()) {
                this->mAuthorRole = role.child_value();
            } else {
                this->mAuthorRole = "";
            }

            if(pugi::xml_node email = mXMLAuthor.select_node("email").node()) {
                this->mAuthorEmail = email.child_value();
            } else {
                this->mAuthorRole = "";
            }

            if(pugi::xml_node phone = mXMLAuthor.select_node("phone").node()) {
                this->mAuthorPhone = phone.child_value();
            } else {
                this->mAuthorPhone = "";
            }
        }

    };

    //struct that holds the MHL process info
    typedef struct MHLProcess {
        std::string mProccessType;
        std::string mName;
    } MHLProcess;

    //class that manages MHLProcess data structure and the ignore patterns
    class MHLProcessInfo {
    private:
        MHLProcess mProcess;
        IgnoreSpec mIgnoreSpec;
        pugi::xml_node mXMLProcessInfo;
    public:
        MHLProcessInfo(MHLProcess &process, IgnoreSpec &ignore_spec) :
            mProcess(process), mIgnoreSpec(ignore_spec) {
            // create xml node with data
        };

        explicit MHLProcessInfo(pugi::xml_node &process_info) :
            mXMLProcessInfo(process_info) {
            if(pugi::xml_node process = this->mXMLProcessInfo.select_node("process").node()) {
                this->mProcess.mProccessType = process.child_value();
            }
            if(pugi::xml_node ignore = this->mXMLProcessInfo.select_node("ignore").node()) {
                for(const auto& ignore_pat : ignore.child("ignore")) {
                    try {
                    std::string captured_pattern = ignore_pat.child_value();
                    this->mIgnoreSpec.add_pattern(captured_pattern);
                    } catch (std::length_error &e) {
                       throw std::runtime_error("Error parsing ignore list");
                    }
                }
            }
        }
    };

    //class that handles the general metadata of the mhl file. Manages MHLAuthor
    class MHLCreatorInfo {
    private:
        ClientDetails mClientInfo;
        MHLAuthor mAuthor;
        std::string mHostName;
        std::string mTool;
        std::string mToolVersion;
        std::string mDateTime;
        std::string mComment;
        pugi::xml_node mXMLCreatorInfo;
    public:
        explicit MHLCreatorInfo(pugi::xml_node &creator_info) :
            mXMLCreatorInfo(creator_info), mAuthor(creator_info.select_node("author").node()) {
            if(pugi::xml_node creation_date = this->mXMLCreatorInfo.select_node("creationdate").node()) {
                this->mDateTime = creation_date.child_value();
            }

            if(pugi::xml_node host_name = this->mXMLCreatorInfo.select_node("hostname").node()) {
                this->mHostName = host_name.child_value();
            }

            if(pugi::xml_node tool = this->mXMLCreatorInfo.select_node("tool").node()) {
                this->mTool = tool.child_value();
                this->mToolVersion = tool.root().attribute("version").as_string();
            }

            if(pugi::xml_node comment = this->mXMLCreatorInfo.select_node("comment").node()) {
                this->mComment = comment.child_value();
            }
        }
    };

    // date and time issue here
    // class that manages a single hash entry and it's associated data elements

    typedef struct HashData {
        std::string mHashFormat;
        std::string mHash;
        std::string mAction;
        std::string mHashDate;
    } HashData;

    class HashEntry {
    private:
        HashData mHash;
        std::string mDateTime;
        std::string mFileSize;
        std::string mFileName;
        pugi::xml_node mXMLHash;

        static HashData p_c4(pugi::xml_node hash);
        static HashData p_md5(pugi::xml_node hash);
        static HashData p_sha1(pugi::xml_node hash);
        static HashData p_xxh128(pugi::xml_node hash);
        static HashData p_xxh3(pugi::xml_node hash);
        static HashData p_xxh64(pugi::xml_node hash);

    public:

        explicit HashEntry(pugi::xml_node &hash_node)
            : mXMLHash(hash_node) {

            // DATA TO BE PARSED from hash_node:
            //<path size="603456065" lastmodificationdate="2023-08-17T11:09:32+01:00">B003C001_230312_R18H.mxf</path>
            //<xxh64 action="original" hashdate="2023-08-17T11:09:38.999606+01:00">5ad36ccc60f6f669</xxh64>
            // Hashtype element can change.

            // use std::map to call processing functions when a hash type node is found.

            using hash_id = std::function<HashData(pugi::xml_node)>;
            std::map<std::string, hash_id> hash_parse {
                    { "c4", &HashEntry::p_c4},
                    { "md5", &HashEntry::p_md5 },
                    { "sha1", &HashEntry::p_sha1 },
                    { "xxh128", &HashEntry::p_xxh128},
                    { "xxh3", &HashEntry::p_xxh3},
                    { "xxh64", &HashEntry::p_xxh64}
            };

            for(auto hash_node_data: mXMLHash.first_child()) {

                if(strcmp(hash_node_data.name(), "path") == 0) {
                    this->mFileSize = hash_node_data.root().attribute("size").as_string();
                    this->mDateTime = hash_node_data.root().attribute("lastmodificationdate").as_string();
                    this->mFileName = hash_node_data.child_value();
                }

                this->mHash = hash_parse[hash_node_data.name()](hash_node_data);
            }
        }

//        blank constructor needs adapting due to addition of HashData struct...
//        HashEntry(std::string &hash_format, std::string &hash, std::string &action, std::string &datetime, std::string &file_size) :
//                mHashFormat(hash_format), mHash(hash), mAction(action), mDateTime(datetime), mFileSize(file_size) {
//            // conditional to create new date time entry
//        }
    };

    // each mhl chain generation references a MHL file that is parsed into this class. This process, that involves to primary classes is managed by the MHLHistory object.
    //the full mhlHashList with it's creator and process info sections managed here.
    class HashList {
    private:
        MHLCreatorInfo mCreatorInfo;
        MHLProcessInfo mProcessInfo;
        std::vector<std::shared_ptr<HashEntry>> mHashes;
    public:
        HashList(pugi::xml_node &creator_info, pugi::xml_node &process_info, pugi::xml_node &hash_list) :
                mCreatorInfo(creator_info), mProcessInfo(process_info) {

            for(auto &hash : hash_list.child("hashes")) {
                std::shared_ptr<HashEntry> hash_entry = std::make_shared<HashEntry>(hash);
            }

        }
    };
}

#endif //LIBMHL_HASHLIST_H
