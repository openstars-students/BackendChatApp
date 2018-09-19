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
#include "TListMessageService.h"

class ServiceHandler : public TServiceThriftHandlerBaseT<ServiceModel,
                    OpenStars::Platform::ListMessageService::TListMessageServiceIf 
                    , OpenStars::Platform::ListMessageService::TListMessageServiceProcessor> {
public:
    typedef TServiceThriftHandlerBaseT<ServiceModel,
            OpenStars::Platform::ListMessageService::TListMessageServiceIf ,
            OpenStars::Platform::ListMessageService::TListMessageServiceProcessor> _Base;

    ServiceHandler(Poco::SharedPtr<ServiceModel> aModel) : _Base(aModel) {
    };

public:
    void getData(OpenStars::Platform::ListMessageService::TDataResult& _return, 
                const OpenStars::Platform::ListMessageService::TKey key)
    {
        if (this->m_pmodel)
            m_pmodel->getData(_return, key);
    }
    OpenStars::Platform::ListMessageService::TErrorCode::type putData( OpenStars::Platform::ListMessageService::TKey key,
                                const OpenStars::Platform::ListMessageService::TData& data)
    {
        if (this->m_pmodel)
            return m_pmodel->putData(key, data);
        return OpenStars::Platform::ListMessageService::TErrorCode::EUnknown;
    }
    OpenStars::Platform::ListMessageService::TErrorCode::type addMessage(const OpenStars::Platform::ListMessageService::TKey cid, const int64_t mid)
    {
        if (this->m_pmodel)
            return m_pmodel->addMessage(cid, mid);
        return OpenStars::Platform::ListMessageService::TErrorCode::EUnknown;
    }
    OpenStars::Platform::ListMessageService::TErrorCode::type removeMessage(const OpenStars::Platform::ListMessageService::TKey cid, const int64_t mid)
    {
        if (this->m_pmodel)
            return m_pmodel->removeMessage(cid, mid);
        return OpenStars::Platform::ListMessageService::TErrorCode::EUnknown;
    }
};

#endif /* SERVICEHANDLER_H */
