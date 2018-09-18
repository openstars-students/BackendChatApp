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
  void getData( OpenStars::Platform::MessageStore::TDataResult& _return, const OpenStars::Platform::MessageStore ::TKey key);

  OpenStars::Platform::MessageStore::TErrorCode::type putData( OpenStars::Platform::MessageStore::TKey key, 
                const OpenStars::Platform::MessageStore::TMessageInfo& data);
  OpenStars::Platform::MessageStore::TErrorCode::type removeData( OpenStars::Platform::MessageStore::TKey key);
  OpenStars::Platform::MessageStore::TErrorCode::type deleteLogicData( OpenStars::Platform::MessageStore::TKey key);
  void getListMessages(OpenStars::Platform::MessageStore::TListDataResult& _return, const std::vector<OpenStars::Platform::MessageStore::TKey>& keys);
private:
    ServiceModel(const ServiceModel& orig);
    Poco::SharedPtr<PersistentStorageType> m_storage;
};

#endif /* _SERVICEMODEL_H */

