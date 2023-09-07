//
// Created by Howard Colin on 15/08/2023.
//

#ifndef LIBMHL_HASHLIST_H
#define LIBMHL_HASHLIST_H

#include "Utils.h"
#include "IgnoreSpec.h"
#include "pugixml.hpp"

/*
 * Contains classes that represent the elemets of the MHL file
 */
namespace MHL {

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

    typedef struct MHLProcess {
        std::string mProccessType;
        std::string mName;
    } MHLProcess;

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
    class HashEntry {
    private:
        std::string mHashFormat;
        std::string mHash;
        std::string mAction;
        std::string mDateTime;
        std::string mFileSize;
        pugi::xml_node mXMLHash;
    public:
        explicit HashEntry(pugi::xml_node &hash_node)
            : mXMLHash(hash_node) { }

//        HashEntry(std::string &hash_format, std::string &hash, std::string &action, std::string &datetime, std::string &file_size) :
//                mHashFormat(hash_format), mHash(hash), mAction(action), mDateTime(datetime), mFileSize(file_size) {
//            // conditional to create new date time entry
//        }
    };

    // each mhl chain generation references a MHL file that is parsed into this class. This process, that involves to primary classes is managed by the MHLHistory object.
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
