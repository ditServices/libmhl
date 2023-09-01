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

        }
    };

    class MHLCreatorInfo {
    private:
        ClientDetails mClientInfo;
        MHLAuthor mAuthor;
        std::string mHostName;
        std::string mTool;
        std::string mDateTime;
        std::string mComment;
        pugi::xml_node mXMLCreatorInfo;
    public:
        explicit MHLCreatorInfo(pugi::xml_node &creator_info) :
            mXMLCreatorInfo(creator_info), mAuthor(creator_info.select_node("author").node()) {
            //parse other vars
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
    private:
        HashEntry(std::string &hash_format, std::string &hash, std::string &action, std::string &datetime, std::string &file_size) :
            mHashFormat(hash_format), mHash(hash), mAction(action), mDateTime(datetime), mFileSize(file_size) {
            // conditional to create new date time entry
        }
    };

    // each mhl chain generation references a MHL file that is parsed into this class. This process, that involves to primary classes is managed by the MHLHistory object.
    class HashList {
    private:
        MHLCreatorInfo mCreatorInfo;
        MHLProcessInfo mProcessInfo;
        std::vector<std::shared_ptr<HashEntry>> mHashes;
    public:
    };
}


#endif //LIBMHL_HASHLIST_H
