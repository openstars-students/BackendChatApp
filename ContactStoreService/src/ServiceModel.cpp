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

void ServiceModel::getData(OpenStars::Platform::ContactStore::TDataResult& _return, const OpenStars::Platform::ContactStore::TKey key)
{
    class get_value_visitor : public PersistentStorageType::data_visitor {
    public:

        get_value_visitor(OpenStars::Platform::ContactStore::TDataResult& _output) : output(_output) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            value.assignTo(this->output.data);
            output.__isset.data = true;
            return false;
        }

        OpenStars::Platform::ContactStore::TDataResult& output;
    };

    
    if (this->m_storage) {
        get_value_visitor visitor(_return);
        this->m_storage->visit(key, &visitor);        
    }    
}

OpenStars::Platform::ContactStore::TErrorCode::type ServiceModel::putData(OpenStars::Platform::ContactStore::TKey key, const OpenStars::Platform::ContactStore::TValue& data)
{
    class putdata_visitor : public PersistentStorageType::data_visitor {
    public:

        putdata_visitor(const OpenStars::Platform::ContactStore::TData& aData) : data(aData) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            value.assignFrom(data);
            return true;
        }

        const OpenStars::Platform::ContactStore::TData& data;
    };


    if (this->m_storage) {
        putdata_visitor visitor(data);
        this->m_storage->visit(key, &visitor);
    }    
}

OpenStars::Platform::ContactStore::TErrorCode::type ServiceModel::addFriend(const OpenStars::Platform::ContactStore::TKey uid, const int64_t friendid)
{
    class addfriend_visitor : public PersistentStorageType::data_visitor {
    public:

        addfriend_visitor(int64_t _cid) : cid(_cid), err() {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            err=value.additem(cid);
            return true;
        }
        int64_t cid;
         OpenStars::Platform::ContactStore::TErrorCode::type err;
    };


    if (this->m_storage) {
        addfriend_visitor visitor(friendid);
        this->m_storage->visit(uid, &visitor);
        return visitor.err;
    }    
}

OpenStars::Platform::ContactStore::TErrorCode::type ServiceModel::unFriend(const OpenStars::Platform::ContactStore::TKey uid, const int64_t friendid)
{
    class unfriend_visitor : public PersistentStorageType::data_visitor {
    public:

        unfriend_visitor(int64_t _cid) : cid(_cid), err() {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            err=value.removeitem(cid);
            return true;
        }
        int64_t cid;
         OpenStars::Platform::ContactStore::TErrorCode::type err;
    };


    if (this->m_storage) {
        unfriend_visitor visitor(friendid);
        this->m_storage->visit(uid, &visitor);
        return visitor.err;
    }
    
}
