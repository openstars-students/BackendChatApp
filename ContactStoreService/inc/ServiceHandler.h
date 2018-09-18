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
#include "TContactStoreService.h"

class ServiceHandler : public TServiceThriftHandlerBaseT<ServiceModel,
                    OpenStars::Platform::ContactStore::TContactStoreServiceIf 
                    , OpenStars::Platform::ContactStore::TContactStoreServiceProcessor> {
public:
    typedef TServiceThriftHandlerBaseT<ServiceModel,
            OpenStars::Platform::ContactStore::TContactStoreServiceIf ,
            OpenStars::Platform::ContactStore::TContactStoreServiceProcessor> _Base;

    ServiceHandler(Poco::SharedPtr<ServiceModel> aModel) : _Base(aModel) {
    };

public:
    void getData(OpenStars::Platform::ContactStore::TDataResult& _return, 
                const OpenStars::Platform::ContactStore::TKey key)
    {
        if (this->m_pmodel)
            m_pmodel->getData(_return, key);
    }
    OpenStars::Platform::ContactStore::TErrorCode::type putData( OpenStars::Platform::ContactStore::TKey key,
                                const OpenStars::Platform::ContactStore::TData& data)
    {
        if (this->m_pmodel)
            return m_pmodel->putData(key, data);
        return OpenStars::Platform::ContactStore::TErrorCode::EUnknown;
    }
    OpenStars::Platform::ContactStore::TErrorCode::type addFriend(const OpenStars::Platform::ContactStore::TKey uid, const int64_t friendid)
    {
        if (this->m_pmodel)
            return m_pmodel->addFriend(uid, friendid);
        return OpenStars::Platform::ContactStore::TErrorCode::EUnknown;
    }
    OpenStars::Platform::ContactStore::TErrorCode::type unFriend(const OpenStars::Platform::ContactStore::TKey uid, const int64_t friendid)
    {
        if (this->m_pmodel)
            return m_pmodel->unFriend(uid, friendid);
        return OpenStars::Platform::ContactStore::TErrorCode::EUnknown;
    }

};

#endif /* SERVICEHANDLER_H */
