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

void ServiceModel::getData(OpenStars::Platform::UserStore::TDataResult& _return, const OpenStars::Platform::UserStore::TKey key)
{
    class get_value_visitor : public PersistentStorageType::data_visitor {
    public:

        get_value_visitor(OpenStars::Platform::UserStore::TDataResult& _output) : output(_output) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            value.assignTo(this->output.data);
            output.__isset.data = true;
            return false;
        }

        OpenStars::Platform::UserStore::TDataResult& output;
    };

    
    if (this->m_storage) {
        get_value_visitor visitor(_return);
        this->m_storage->visit(key, &visitor);        
    }    
}

void ServiceModel::getListUsers(OpenStars::Platform::UserStore::TListDataUsers& _return, const std::vector<OpenStars::Platform::UserStore::TKey>& keys)
{
    class getListUsers_visitor : public PersistentStorageType::data_visitor {
    public:

        getListUsers_visitor(OpenStars::Platform::UserStore::TUserInfo& _output) : output(_output) {
        }
        //cout<<"out put: "<<output<<endl;
        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            value.assignTo(this->output);
            return false;
        }

        OpenStars::Platform::UserStore::TUserInfo& output;
    };
    _return.listuser.clear();
    OpenStars::Platform::UserStore::TErrorCode err;
    if (this->m_storage) {
        OpenStars::Platform::UserStore::TUserInfo value;
        getListUsers_visitor visitor(value);
        for(vector<OpenStars::Platform::UserStore::TKey>::const_iterator pos = keys.begin(); pos != keys.end(); pos++) {
            this->m_storage->visit(*pos, &visitor);
            _return.listuser.insert(pair<OpenStars::Platform::UserStore::TKey, OpenStars::Platform::UserStore::TUserInfo>(*pos, visitor.output));
            //cout<<"return: "<<_return.listuser[pos]<<endl;
            _return.__isset.listuser = true;
        }
        _return.errorCode=err.EGood;
    }
    else{
        _return.errorCode=err.EUnknown;
    }
    _return.__isset.errorCode=true;
         
}

OpenStars::Platform::UserStore::TErrorCode::type  ServiceModel::hasUser(const string& username,const std::vector<OpenStars::Platform::UserStore::TKey>& keys)
    {
        class hasUser_visitor : public PersistentStorageType::data_visitor {
    public:

        hasUser_visitor(std::string _uname) : username(_uname), check(false) {
        }
        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            check=value.hasUser(username);
            return false;
        }
        std::string username;
        bool check;
    };
    OpenStars::Platform::UserStore::TErrorCode err;
    if (this->m_storage) {
        hasUser_visitor visitor(username);
        for(vector<OpenStars::Platform::UserStore::TKey>::const_iterator pos = keys.begin(); pos != keys.end(); pos++) {
            this->m_storage->visit(*pos, &visitor);
            if(visitor.check)
                return err.EDataExisted;
            //cout<<"return: "<<_return.listuser[pos]<<endl;
        }
        return err.EGood;
    }
    else{
        return err.EUnknown;
    }
}

OpenStars::Platform::UserStore::TKey  ServiceModel::getIDByPublicKey(const std::string& publickey, const int64_t lastkey)
    {
     cout<<" get here : "<<endl;
        class getIDByPublicKey_visitor : public PersistentStorageType::data_visitor {
    public:

        getIDByPublicKey_visitor(std::string _uname) : publickey(_uname), check(false) {
        }
        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            check=value.hasPublicKey(publickey);
            return false;
        }
        std::string publickey;
        bool check;
    };
    if (this->m_storage) {
        cout<<" get here : "<<endl;
        getIDByPublicKey_visitor visitor(publickey);
        for(OpenStars::Platform::UserStore::TKey pos = 1; pos <=lastkey; pos++) {
            cout<<" pos : "<<endl;
            this->m_storage->visit(pos, &visitor);
            if(visitor.check)
                return pos;
            //cout<<"return: "<<_return.listuser[pos]<<endl;
        }
        return 0;
    }
    else{
        return 0;
    }
}

OpenStars::Platform::UserStore::TErrorCode::type ServiceModel::putData(OpenStars::Platform::UserStore::TKey key, const OpenStars::Platform::UserStore::TUserInfo& data)
{
    class putdata_visitor : public PersistentStorageType::data_visitor {
    public:

        putdata_visitor(const OpenStars::Platform::UserStore::TData& aData) : data(aData) {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            value.assignFrom(data);
            return true;
        }

        const OpenStars::Platform::UserStore::TData& data;
    };


    if (this->m_storage) {
        putdata_visitor visitor(data);
        this->m_storage->visit(key, &visitor);
    }    
}
OpenStars::Platform::UserStore::TErrorCode::type ServiceModel::deleteUser(OpenStars::Platform::UserStore::TKey key)
{
    class deletedata_visitor : public PersistentStorageType::data_visitor {
    public:

        deletedata_visitor(void) : err() {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            err=value.deleteLogicData();
            return true;
        }

         OpenStars::Platform::UserStore::TErrorCode::type err;
    };


    if (this->m_storage) {
        deletedata_visitor visitor;
        this->m_storage->visit(key, &visitor);
        return visitor.err;
    }    
}

OpenStars::Platform::UserStore::TErrorCode::type ServiceModel::addConversation(const OpenStars::Platform::UserStore::TKey uid, const int64_t cid)
{
    class addconversation_visitor : public PersistentStorageType::data_visitor {
    public:

        addconversation_visitor(int64_t _cid) : cid(_cid), err() {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            err=value.addConversation(cid);
            return true;
        }
        int64_t cid;
         OpenStars::Platform::UserStore::TErrorCode::type err;
    };


    if (this->m_storage) {
        addconversation_visitor visitor(cid);
        this->m_storage->visit(uid, &visitor);
        return visitor.err;
    }    
}

OpenStars::Platform::UserStore::TErrorCode::type ServiceModel::deleteConversation(const OpenStars::Platform::UserStore::TKey uid, const int64_t cid)
{
    class deleteconversation_visitor : public PersistentStorageType::data_visitor {
    public:

        deleteconversation_visitor(int64_t _cid) : cid(_cid), err() {
        }

        virtual bool visit(const PersistentStorageType::TKey& key, PersistentStorageType::TValue& value) {
            err=value.deleteConversation(cid);
            return true;
        }
        int64_t cid;
         OpenStars::Platform::UserStore::TErrorCode::type err;
    };

    if (this->m_storage) {
        deleteconversation_visitor visitor(cid);
        this->m_storage->visit(uid, &visitor);
        return visitor.err;
    }    
}

