/* 
 * File:   ServiceHandler.h
 * Author: trungthanh
 *
 * Created on June 08, 2018, 6:40 PM
 */

#ifndef SERVICEHANDLER_H
#define SERVICEHANDLER_H

#include "ServiceModel.h"
#include "ServiceThriftHandlerBaseT.h"
#include "TUserStoreService.h"

class ServiceHandler : public TServiceThriftHandlerBaseT<ServiceModel,
                    OpenStars::Platform::UserStore::TUserStoreServiceIf 
                    , OpenStars::Platform::UserStore::TUserStoreServiceProcessor> {
public:
    typedef TServiceThriftHandlerBaseT<ServiceModel,
            OpenStars::Platform::UserStore::TUserStoreServiceIf ,
            OpenStars::Platform::UserStore::TUserStoreServiceProcessor> _Base;

    ServiceHandler(Poco::SharedPtr<ServiceModel> aModel) : _Base(aModel) {
    };

public:
    virtual void getData(OpenStars::Platform::UserStore::TDataResult& _return, 
                const OpenStars::Platform::UserStore::TKey key)
    {
        if (this->m_pmodel)
            m_pmodel->getData(_return, key);
    }
    virtual void getListUsers(OpenStars::Platform::UserStore::TListDataUsers& _return, const std::vector<OpenStars::Platform::UserStore::TKey>& keys)
    {
        if (this->m_pmodel)
            m_pmodel->getListUsers(_return, keys);
    }
    virtual bool hasUser(const std::string& username,const int64_t keys)
    {
        if (this->m_pmodel)
            return m_pmodel->hasUser(username,keys);
        return OpenStars::Platform::UserStore::TErrorCode::EUnknown;
    }
    virtual OpenStars::Platform::UserStore::TKey getIDByPublicKey(const std::string& publickey, const int64_t lastkey)
    {
        if (this->m_pmodel)
            return m_pmodel->getIDByPublicKey(publickey,lastkey);
        return (OpenStars::Platform::UserStore::TKey)0;
    }
    
    
    virtual OpenStars::Platform::UserStore::TErrorCode::type putData( OpenStars::Platform::UserStore::TKey key,
                                const OpenStars::Platform::UserStore::TData& data)
    {
        if (this->m_pmodel)
            return m_pmodel->putData(key, data);
        return OpenStars::Platform::UserStore::TErrorCode::EUnknown;
    }
    
    virtual OpenStars::Platform::UserStore::TErrorCode::type deleteUser( OpenStars::Platform::UserStore::TKey key)
    {
        if (this->m_pmodel)
            return m_pmodel->deleteUser(key);
        return OpenStars::Platform::UserStore::TErrorCode::EUnknown;
    }
    /*
    virtual OpenStars::Platform::UserStore::TErrorCode::type addConversation(const OpenStars::Platform::UserStore::TKey uid, const int64_t cid)
    {
        if (this->m_pmodel)
            return m_pmodel->addConversation(uid,cid);
        return OpenStars::Platform::UserStore::TErrorCode::EUnknown;
    }
    
    virtual OpenStars::Platform::UserStore::TErrorCode::type deleteConversation(const OpenStars::Platform::UserStore::TKey uid, const int64_t cid)
    {
        if (this->m_pmodel)
            return m_pmodel->deleteConversation(uid,cid);
        return OpenStars::Platform::UserStore::TErrorCode::EUnknown;
    }*/

};

#endif /* SERVICEHANDLER_H */
