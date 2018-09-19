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

void ServiceModel::getData(OpenStars::Platform::ListMessageService::TDataResult& _return, const OpenStars::Platform::ListMessageService::TKey key)
{
    class get_value_visitor : public PersistentStorageType::data_visitor {
    public:

        get_value_visitor(OpenStars::Platform::ListMessageService::TDataResult& _output) : output(_output) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            value.assignTo(this->output.data);
            output.__isset.data = true;
            return false;
        }

        OpenStars::Platform::ListMessageService::TDataResult& output;
    };

    
    if (this->m_storage) {
        get_value_visitor visitor(_return);
        this->m_storage->visit(key, &visitor);        
    }    
}

OpenStars::Platform::ListMessageService::TErrorCode::type ServiceModel::putData(OpenStars::Platform::ListMessageService::TKey key, const OpenStars::Platform::ListMessageService::TValue& data)
{
    class putdata_visitor : public PersistentStorageType::data_visitor {
    public:

        putdata_visitor(const OpenStars::Platform::ListMessageService::TData& aData) : data(aData) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            value.assignFrom(data);
            return true;
        }

        const OpenStars::Platform::ListMessageService::TData& data;
    };


    if (this->m_storage) {
        putdata_visitor visitor(data);
        this->m_storage->visit(key, &visitor);
    }    
}

OpenStars::Platform::ListMessageService::TErrorCode::type ServiceModel::addMessage(const OpenStars::Platform::ListMessageService::TKey cid, const int64_t mid)
{
    class addmessage_visitor : public PersistentStorageType::data_visitor {
    public:

        addmessage_visitor(int64_t _mid) : mid(_mid), err() {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            err=value.additem(mid);
            return true;
        }
        int64_t mid;
         OpenStars::Platform::ListMessageService::TErrorCode::type err;
    };


    if (this->m_storage) {
        addmessage_visitor visitor(mid);
        this->m_storage->visit(cid, &visitor);
        return visitor.err;
    }    
}

OpenStars::Platform::ListMessageService::TErrorCode::type ServiceModel::removeMessage(const OpenStars::Platform::ListMessageService::TKey cid, const int64_t mid)
{
    class removemessage_visitor : public PersistentStorageType::data_visitor {
    public:

        removemessage_visitor(int64_t _mid) : mid(_mid), err() {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            err=value.removeitem(mid);
            return true;
        }
        int64_t mid;
         OpenStars::Platform::ListMessageService::TErrorCode::type err;
    };


    if (this->m_storage) {
        removemessage_visitor visitor(mid);
        this->m_storage->visit(cid, &visitor);
        return visitor.err;
    }
    
}
