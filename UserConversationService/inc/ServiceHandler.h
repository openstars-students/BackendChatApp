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
#include "TUserConversationService.h"

class ServiceHandler : public TServiceThriftHandlerBaseT<ServiceModel,
                    OpenStars::Platform::UserConversationService::TUserConversationServiceIf 
                    , OpenStars::Platform::UserConversationService::TUserConversationServiceProcessor> {
public:
    typedef TServiceThriftHandlerBaseT<ServiceModel,
            OpenStars::Platform::UserConversationService::TUserConversationServiceIf ,
            OpenStars::Platform::UserConversationService::TUserConversationServiceProcessor> _Base;

    ServiceHandler(Poco::SharedPtr<ServiceModel> aModel) : _Base(aModel) {
    };

public:
    void getData(OpenStars::Platform::UserConversationService::TDataResult& _return, 
                const OpenStars::Platform::UserConversationService::TKey key)
    {
        if (this->m_pmodel)
            m_pmodel->getData(_return, key);
    }
    OpenStars::Platform::UserConversationService::TErrorCode::type putData( OpenStars::Platform::UserConversationService::TKey key,
                                const OpenStars::Platform::UserConversationService::TData& data)
    {
        if (this->m_pmodel)
            return m_pmodel->putData(key, data);
        return OpenStars::Platform::UserConversationService::TErrorCode::EUnknown;
    }
    OpenStars::Platform::UserConversationService::TErrorCode::type addConversation(const OpenStars::Platform::UserConversationService::TKey uid, const int64_t cid)
    {
        if (this->m_pmodel)
            return m_pmodel->addConversation(uid, cid);
        return OpenStars::Platform::UserConversationService::TErrorCode::EUnknown;
    }
    OpenStars::Platform::UserConversationService::TErrorCode::type removeConversation(const OpenStars::Platform::UserConversationService::TKey uid, const int64_t cid)
    {
        if (this->m_pmodel)
            return m_pmodel->removeConversation(uid, cid);
        return OpenStars::Platform::UserConversationService::TErrorCode::EUnknown;
    }

};

#endif /* SERVICEHANDLER_H */
