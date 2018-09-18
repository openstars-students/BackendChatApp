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

void ServiceModel::getData(OpenStars::Platform::MessageStore::TDataResult& _return, const OpenStars::Platform::MessageStore::TKey key)
{
    class get_value_visitor : public PersistentStorageType::data_visitor {
    public:

        get_value_visitor(OpenStars::Platform::MessageStore::TDataResult& _output) : output(_output) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            value.assignTo(this->output.data);
            output.__isset.data = true;
            return false;
        }

        OpenStars::Platform::MessageStore::TDataResult& output;
    };

    OpenStars::Platform::MessageStore::TErrorCode err;
    if (this->m_storage) {
        
        get_value_visitor visitor(_return);
        this->m_storage->visit(key, &visitor);
        _return.errorCode=err.EGood;
    } else{
        _return.errorCode=err.EUnknown;
    }    
}
void ServiceModel::getListMessages(OpenStars::Platform::MessageStore::TListDataResult& _return, const std::vector<OpenStars::Platform::MessageStore::TKey>& keys)
{
    class getListMessages_visitor : public PersistentStorageType::data_visitor {
    public:

        getListMessages_visitor(OpenStars::Platform::MessageStore::TMessageInfo& _output) : output(_output) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            value.assignTo(this->output);
            //cout<<"output la: "<<output<<endl;
            return false;
        }

        OpenStars::Platform::MessageStore::TMessageInfo& output;
    };
    //cout<<"getlistmessages"<<endl;
    _return.listdata.clear();
    OpenStars::Platform::MessageStore::TErrorCode err;
    if (this->m_storage) {
        OpenStars::Platform::MessageStore::TMessageInfo value;
        getListMessages_visitor visitor(value);
        for(vector<OpenStars::Platform::MessageStore::TKey>::const_iterator pos = keys.begin(); pos != keys.end(); pos++) {
            this->m_storage->visit(*pos, &visitor);
            //cout<<"pos : "<<*pos<<endl;
            //cout<<"output visitor"<<visitor.output<<endl;
            _return.listdata.insert(pair<OpenStars::Platform::MessageStore::TKey, OpenStars::Platform::MessageStore::TMessageInfo>(*pos, visitor.output));
            //cout<<"return: "<<_return.listdata[*pos]<<endl;
            _return.__isset.listdata = true;
        }
    }
    else{
        _return.errorCode=err.EUnknown;
    }
         
}
OpenStars::Platform::MessageStore::TErrorCode::type ServiceModel::putData(OpenStars::Platform::MessageStore::TKey key, const OpenStars::Platform::MessageStore::TMessageInfo& data)
{
    class putdata_visitor : public PersistentStorageType::data_visitor {
    public:

        putdata_visitor(const OpenStars::Platform::MessageStore::TData& aData) : data(aData) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            value.assignFrom(data);
            return true;
        }

        const OpenStars::Platform::MessageStore::TData& data;
    };


    if (this->m_storage) {
        putdata_visitor visitor(data);
        this->m_storage->visit(key, &visitor);
    }    
}

OpenStars::Platform::MessageStore::TErrorCode::type ServiceModel::removeData(OpenStars::Platform::MessageStore::TKey key)
{
    class removedata_visitor : public PersistentStorageType::data_visitor {
    public:

        removedata_visitor(void) : err() {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            err=value.deleteLogicData();
            return true;
        }

         OpenStars::Platform::MessageStore::TErrorCode::type err;
    };


    if (this->m_storage) {
        removedata_visitor visitor;
        this->m_storage->visit(key, &visitor);
        return visitor.err;
    }    
}

OpenStars::Platform::MessageStore::TErrorCode::type ServiceModel::deleteLogicData(OpenStars::Platform::MessageStore::TKey key)
{
    class deletelogicdata_visitor : public PersistentStorageType::data_visitor {
    public:

        deletelogicdata_visitor(void) : err() {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            err=value.deleteLogicData();
            return true;
        }

         OpenStars::Platform::MessageStore::TErrorCode::type err;
    };


    if (this->m_storage) {
        deletelogicdata_visitor visitor;
        this->m_storage->visit(key, &visitor);
        return visitor.err;
    }    
}