//
// Created by Howard Colin on 15/08/2023.
//

#ifndef LIBMHL_HASHLIST_H
#define LIBMHL_HASHLIST_H

#include "Utils.h"
#include "IgnoreSpec.h"


/*
 * Contains classes that represent the elemets of the MHL file
 */
namespace MHL {

    class MHLAuthor {
    private:
        std::string mAuthorName;
        std::string mAuthorEmail;
    public:
        MHLAuthor(std::string &author_name, std::string &author_email) :
            mAuthorName(author_name), mAuthorEmail(author_email) {};
    };

    typedef struct MHLProcess {
        std::string mProccessType;
        std::string mName;
    } MHLProcess;

    class MHLProcessInfo {
    private:
        MHLProcess mProcess;
        IgnoreSpec mIgnoreSpec;
    };

    class MHLCreatorInfo {
    private:
        ClientDetails mClientInfo;
        std::vector<std::shared_ptr<MHLAuthor>> mAuthors;
        std::string mTool;
        std::string mDateTime;
        std::string mComment;
    public:
    };

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

    class HashList {
    private:
        MHLCreatorInfo mCreatorInfo;
        MHLProcessInfo mProcessInfo;
        std::vector<std::shared_ptr<HashEntry>> mHashes;
    public:
        HashList() = default;
    };
}


#endif //LIBMHL_HASHLIST_H
