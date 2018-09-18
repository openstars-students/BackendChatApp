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

void ServiceModel::getData(OpenStars::Platform::UserConversationService::TDataResult& _return, const OpenStars::Platform::UserConversationService::TKey key)
{
    class get_value_visitor : public PersistentStorageType::data_visitor {
    public:

        get_value_visitor(OpenStars::Platform::UserConversationService::TDataResult& _output) : output(_output) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            value.assignTo(this->output.data);
            output.__isset.data = true;
            return false;
        }

        OpenStars::Platform::UserConversationService::TDataResult& output;
    };

    
    if (this->m_storage) {
        get_value_visitor visitor(_return);
        this->m_storage->visit(key, &visitor);        
    }    
}

OpenStars::Platform::UserConversationService::TErrorCode::type ServiceModel::putData(OpenStars::Platform::UserConversationService::TKey key, const OpenStars::Platform::UserConversationService::TValue& data)
{
    class putdata_visitor : public PersistentStorageType::data_visitor {
    public:

        putdata_visitor(const OpenStars::Platform::UserConversationService::TData& aData) : data(aData) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            value.assignFrom(data);
            return true;
        }

        const OpenStars::Platform::UserConversationService::TData& data;
    };


    if (this->m_storage) {
        putdata_visitor visitor(data);
        this->m_storage->visit(key, &visitor);
    }    
}

OpenStars::Platform::UserConversationService::TErrorCode::type ServiceModel::addConversation(const OpenStars::Platform::UserConversationService::TKey uid, const int64_t cid)
{
    class addconversation_visitor : public PersistentStorageType::data_visitor {
    public:

        addconversation_visitor(int64_t _cid) : cid(_cid), err() {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            err=value.additem(cid);
            return true;
        }
        int64_t cid;
         OpenStars::Platform::UserConversationService::TErrorCode::type err;
    };


    if (this->m_storage) {
        addconversation_visitor visitor(cid);
        this->m_storage->visit(uid, &visitor);
        return visitor.err;
    }    
}

OpenStars::Platform::UserConversationService::TErrorCode::type ServiceModel::removeConversation(const OpenStars::Platform::UserConversationService::TKey uid, const int64_t cid)
{
    class removeconversation_visitor : public PersistentStorageType::data_visitor {
    public:

        removeconversation_visitor(int64_t _cid) : cid(_cid), err() {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            err=value.removeitem(cid);
            return true;
        }
        int64_t cid;
         OpenStars::Platform::UserConversationService::TErrorCode::type err;
    };


    if (this->m_storage) {
        removeconversation_visitor visitor(cid);
        this->m_storage->visit(uid, &visitor);
        return visitor.err;
    }
    
}
