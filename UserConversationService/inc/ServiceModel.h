/* 
 * File:   ServiceModel.h
 * Author: trungthanh
 *
 * Created on June 08, 2018, 6:13 PM
 */

#ifndef _SERVICEMODEL_H
#define _SERVICEMODEL_H

#include <vector>
#include <map>
#include "storagedef.h"

class ServiceModel {
public:
    ServiceModel(Poco::SharedPtr<PersistentStorageType> aStorage);
    virtual ~ServiceModel(void);

public:
  void getData( OpenStars::Platform::UserConversationService::TDataResult& _return, const OpenStars::Platform::UserConversationService ::TKey key);

  OpenStars::Platform::UserConversationService::TErrorCode::type putData( OpenStars::Platform::UserConversationService::TKey key, 
                const OpenStars::Platform::UserConversationService::TValue& data);
  OpenStars::Platform::UserConversationService::TErrorCode::type addConversation(const OpenStars::Platform::UserConversationService::TKey uid, const int64_t cid);
  OpenStars::Platform::UserConversationService::TErrorCode::type removeConversation(const OpenStars::Platform::UserConversationService::TKey uid, const int64_t cid);
private:
    ServiceModel(const ServiceModel& orig);
    Poco::SharedPtr<PersistentStorageType> m_storage;
};

#endif /* _SERVICEMODEL_H */

