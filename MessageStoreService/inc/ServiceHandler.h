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
#include "TMessageStoreService.h"

class ServiceHandler : public TServiceThriftHandlerBaseT<ServiceModel,
                    OpenStars::Platform::MessageStore::TMessageStoreServiceIf 
                    , OpenStars::Platform::MessageStore::TMessageStoreServiceProcessor> {
public:
    typedef TServiceThriftHandlerBaseT<ServiceModel,
            OpenStars::Platform::MessageStore::TMessageStoreServiceIf ,
            OpenStars::Platform::MessageStore::TMessageStoreServiceProcessor> _Base;

    ServiceHandler(Poco::SharedPtr<ServiceModel> aModel) : _Base(aModel) {
    };

public:
    void getData(OpenStars::Platform::MessageStore::TDataResult& _return, 
                const OpenStars::Platform::MessageStore::TKey key)
    {
        if (this->m_pmodel)
            m_pmodel->getData(_return, key);
    }
    void getListMessages(OpenStars::Platform::MessageStore::TListDataResult& _return, const std::vector<OpenStars::Platform::MessageStore::TKey>& keys)
    {
        if (this->m_pmodel)
            m_pmodel->getListMessages(_return, keys);
    }
    OpenStars::Platform::MessageStore::TErrorCode::type putData( OpenStars::Platform::MessageStore::TKey key,
                                const OpenStars::Platform::MessageStore::TData& data)
    {
        if (this->m_pmodel)
            return m_pmodel->putData(key, data);
        return OpenStars::Platform::MessageStore::TErrorCode::EUnknown;
    }
    OpenStars::Platform::MessageStore::TErrorCode::type removeData( OpenStars::Platform::MessageStore::TKey key)
    {
        if (this->m_pmodel)
            return m_pmodel->removeData(key);
        return OpenStars::Platform::MessageStore::TErrorCode::EUnknown;
    }
    OpenStars::Platform::MessageStore::TErrorCode::type deleteLogicData( OpenStars::Platform::MessageStore::TKey key)
    {
        if (this->m_pmodel)
            return m_pmodel->deleteLogicData(key);
        return OpenStars::Platform::MessageStore::TErrorCode::EUnknown;
    }

};

#endif /* SERVICEHANDLER_H */
