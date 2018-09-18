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
#include "TListMemberService.h"

class ServiceHandler : public TServiceThriftHandlerBaseT<ServiceModel,
                    OpenStars::Platform::ListMemberService::TListMemberServiceIf 
                    , OpenStars::Platform::ListMemberService::TListMemberServiceProcessor> {
public:
    typedef TServiceThriftHandlerBaseT<ServiceModel,
            OpenStars::Platform::ListMemberService::TListMemberServiceIf ,
            OpenStars::Platform::ListMemberService::TListMemberServiceProcessor> _Base;

    ServiceHandler(Poco::SharedPtr<ServiceModel> aModel) : _Base(aModel) {
    };

public:
    void getData(OpenStars::Platform::ListMemberService::TDataResult& _return, 
                const OpenStars::Platform::ListMemberService::TKey key)
    {
        if (this->m_pmodel)
            m_pmodel->getData(_return, key);
    }
    OpenStars::Platform::ListMemberService::TErrorCode::type putData( OpenStars::Platform::ListMemberService::TKey key,
                                const OpenStars::Platform::ListMemberService::TData& data)
    {
        if (this->m_pmodel)
            return m_pmodel->putData(key, data);
        return OpenStars::Platform::ListMemberService::TErrorCode::EUnknown;
    }

};

#endif /* SERVICEHANDLER_H */
