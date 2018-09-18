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
#include "TConversationStoreService.h"

class ServiceHandler : public TServiceThriftHandlerBaseT<ServiceModel,
                    OpenStars::Platform::ConversationStore::TConversationStoreServiceIf 
                    , OpenStars::Platform::ConversationStore::TConversationStoreServiceProcessor> {
public:
    typedef TServiceThriftHandlerBaseT<ServiceModel,
            OpenStars::Platform::ConversationStore::TConversationStoreServiceIf ,
            OpenStars::Platform::ConversationStore::TConversationStoreServiceProcessor> _Base;

    ServiceHandler(Poco::SharedPtr<ServiceModel> aModel) : _Base(aModel) {
    };

public:
    void getData(OpenStars::Platform::ConversationStore::TDataResult& _return, 
                const OpenStars::Platform::ConversationStore::TKey key)
    {
        if (this->m_pmodel)
            m_pmodel->getData(_return, key);
    }
    OpenStars::Platform::ConversationStore::TErrorCode::type putData( OpenStars::Platform::ConversationStore::TKey key,
                                const OpenStars::Platform::ConversationStore::TData& data)
    {
        if (this->m_pmodel)
            return m_pmodel->putData(key, data);
        return OpenStars::Platform::ConversationStore::TErrorCode::EUnknown;
    }
    virtual void getListData(OpenStars::Platform::ConversationStore::TListDataResult& _return, const std::vector<int64_t>& keys)
    {
        if (this->m_pmodel)
            m_pmodel->getListData(_return, keys);
    }

};

#endif /* SERVICEHANDLER_H */
