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

void ServiceModel::getData(OpenStars::Platform::ListMemberService::TDataResult& _return, const OpenStars::Platform::ListMemberService::TKey key)
{
    class get_value_visitor : public PersistentStorageType::data_visitor {
    public:

        get_value_visitor(OpenStars::Platform::ListMemberService::TDataResult& _output) : output(_output) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            value.assignTo(this->output.data);
            output.__isset.data = true;
            return false;
        }

        OpenStars::Platform::ListMemberService::TDataResult& output;
    };

    
    if (this->m_storage) {
        get_value_visitor visitor(_return);
        this->m_storage->visit(key, &visitor);        
    }    
}

OpenStars::Platform::ListMemberService::TErrorCode::type ServiceModel::putData(OpenStars::Platform::ListMemberService::TKey key, const OpenStars::Platform::ListMemberService::TValue& data)
{
    class putdata_visitor : public PersistentStorageType::data_visitor {
    public:

        putdata_visitor(const OpenStars::Platform::ListMemberService::TData& aData) : data(aData) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            value.assignFrom(data);
            return true;
        }

        const OpenStars::Platform::ListMemberService::TData& data;
    };


    if (this->m_storage) {
        putdata_visitor visitor(data);
        this->m_storage->visit(key, &visitor);
    }    
}

OpenStars::Platform::ListMemberService::TErrorCode::type ServiceModel::addMember(const OpenStars::Platform::ListMemberService::TKey cid, const int64_t uid)
{
    class addmember_visitor : public PersistentStorageType::data_visitor {
    public:

        addmember_visitor(int64_t _uid) : uid(_uid), err() {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            err=value.additem(uid);
            return true;
        }
        int64_t uid;
         OpenStars::Platform::ListMemberService::TErrorCode::type err;
    };


    if (this->m_storage) {
        addmember_visitor visitor(uid);
        this->m_storage->visit(cid, &visitor);
        return visitor.err;
    }    
}

OpenStars::Platform::ListMemberService::TErrorCode::type ServiceModel::removeMember(const OpenStars::Platform::ListMemberService::TKey cid, const int64_t uid)
{
    class removemember_visitor : public PersistentStorageType::data_visitor {
    public:

        removemember_visitor(int64_t _uid) : uid(_uid), err() {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            err=value.removeitem(uid);
            return true;
        }
        int64_t uid;
         OpenStars::Platform::ListMemberService::TErrorCode::type err;
    };


    if (this->m_storage) {
        removemember_visitor visitor(uid);
        this->m_storage->visit(cid, &visitor);
        return visitor.err;
    }
    
}