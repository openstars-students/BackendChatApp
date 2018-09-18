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
  void getData( OpenStars::Platform::ListMemberService::TDataResult& _return, const OpenStars::Platform::ListMemberService ::TKey key);

  OpenStars::Platform::ListMemberService::TErrorCode::type putData( OpenStars::Platform::ListMemberService::TKey key, 
                const OpenStars::Platform::ListMemberService::TValue& data);
   
private:
    ServiceModel(const ServiceModel& orig);
    Poco::SharedPtr<PersistentStorageType> m_storage;
};

#endif /* _SERVICEMODEL_H */

