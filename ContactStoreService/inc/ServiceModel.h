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
  void getData( OpenStars::Platform::ContactStore::TDataResult& _return, const OpenStars::Platform::ContactStore ::TKey key);

  OpenStars::Platform::ContactStore::TErrorCode::type putData( OpenStars::Platform::ContactStore::TKey key, 
                const OpenStars::Platform::ContactStore::TValue& data);
   
  OpenStars::Platform::ContactStore::TErrorCode::type addFriend(const OpenStars::Platform::ContactStore::TKey uid, const int64_t friendid);
  
  OpenStars::Platform::ContactStore::TErrorCode::type unFriend(const OpenStars::Platform::ContactStore::TKey uid, const int64_t friendid);
private:
    ServiceModel(const ServiceModel& orig);
    Poco::SharedPtr<PersistentStorageType> m_storage;
};

#endif /* _SERVICEMODEL_H */

