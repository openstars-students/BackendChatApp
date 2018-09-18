/* 
 * File:   ServiceModel.cpp
 * Author: trungthanh
 * 
 * Created on June 08, 2018, 6:13 PM
 */

#include "ServiceModel.h"

using namespace std;

ServiceModel::ServiceModel(Poco::SharedPtr<PersistentStorageType> aStorage) : m_storage(aStorage) {
}

ServiceModel::~ServiceModel(void) {
}

void ServiceModel::getData(OpenStars::Platform::ConversationStore::TDataResult& _return, const OpenStars::Platform::ConversationStore::TKey key)
{
    class get_value_visitor : public PersistentStorageType::data_visitor {
    public:

        get_value_visitor(OpenStars::Platform::ConversationStore::TDataResult& _output) : output(_output) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            value.assignTo(this->output.data);
            output.__isset.data = true;
            return false;
        }

        OpenStars::Platform::ConversationStore::TDataResult& output;
    };

    
    if (this->m_storage) {
        get_value_visitor visitor(_return);
        this->m_storage->visit(key, &visitor);        
    }    
}

OpenStars::Platform::ConversationStore::TErrorCode::type ServiceModel::putData(OpenStars::Platform::ConversationStore::TKey key, const OpenStars::Platform::ConversationStore::TConversationInfo& data)
{
    class putdata_visitor : public PersistentStorageType::data_visitor {
    public:

        putdata_visitor(const OpenStars::Platform::ConversationStore::TData& aData) : data(aData) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            value.assignFrom(data);
            return true;
        }

        const OpenStars::Platform::ConversationStore::TData& data;
    };


    if (this->m_storage) {
        putdata_visitor visitor(data);
        this->m_storage->visit(key, &visitor);
    }    
}

void ServiceModel::getListData(OpenStars::Platform::ConversationStore::TListDataResult& _return, const std::vector<int64_t>& keys)
{
    class getlist_visitor : public PersistentStorageType::data_visitor {
    public:

        getlist_visitor(OpenStars::Platform::ConversationStore::TConversationInfo& _output) : output(_output) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            value.assignTo(this->output);
            return false;
        }

        OpenStars::Platform::ConversationStore::TConversationInfo& output;
    };
_return.listconversation.clear();
    OpenStars::Platform::ConversationStore::TErrorCode err;
    if (this->m_storage) {
        OpenStars::Platform::ConversationStore::TConversationInfo value;
        getlist_visitor visitor(value);
        for(vector<OpenStars::Platform::ConversationStore::TKey>::const_iterator pos = keys.begin(); pos != keys.end(); pos++) {
            this->m_storage->visit(*pos, &visitor);
            _return.listconversation.insert(pair<OpenStars::Platform::ConversationStore::TKey, OpenStars::Platform::ConversationStore::TConversationInfo>(*pos, visitor.output));
            //cout<<"return: "<<_return.listuser[pos]<<endl;
            _return.__isset.listconversation = true;
        }
        _return.errorCode=err.EGood;
    }
    else{
        _return.errorCode=err.EUnknown;
    }
    _return.__isset.errorCode=true;
}
