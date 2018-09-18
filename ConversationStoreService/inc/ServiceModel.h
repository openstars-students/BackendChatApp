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
  void getData( OpenStars::Platform::ConversationStore::TDataResult& _return, const OpenStars::Platform::ConversationStore ::TKey key);

  OpenStars::Platform::ConversationStore::TErrorCode::type putData( OpenStars::Platform::ConversationStore::TKey key, 
                const OpenStars::Platform::ConversationStore::TConversationInfo& data);
   
  void getListData(OpenStars::Platform::ConversationStore::TListDataResult& _return, const std::vector<int64_t>& keys);
private:
    ServiceModel(const ServiceModel& orig);
    Poco::SharedPtr<PersistentStorageType> m_storage;
};

#endif /* _SERVICEMODEL_H */

