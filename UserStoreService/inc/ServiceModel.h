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
  void getData( OpenStars::Platform::UserStore::TDataResult& _return, const OpenStars::Platform::UserStore ::TKey key);
  void getListUsers(OpenStars::Platform::UserStore::TListDataUsers& _return, const std::vector<OpenStars::Platform::UserStore::TKey>& keys);
  bool hasUser(const std::string& username, const int64_t keys);
  OpenStars::Platform::UserStore::TKey getIDByPublicKey(const std::string& publickey, const int64_t lastkey);
  
  OpenStars::Platform::UserStore::TErrorCode::type putData( OpenStars::Platform::UserStore::TKey key, 
                const OpenStars::Platform::UserStore::TUserInfo& data);
  OpenStars::Platform::UserStore::TErrorCode::type deleteUser( OpenStars::Platform::UserStore::TKey key);
  //OpenStars::Platform::UserStore::TErrorCode::type addConversation(const OpenStars::Platform::UserStore::TKey uid, const int64_t cid);
  //OpenStars::Platform::UserStore::TErrorCode::type deleteConversation(const OpenStars::Platform::UserStore::TKey uid, const int64_t cid);

private:
    ServiceModel(const ServiceModel& orig);
    Poco::SharedPtr<PersistentStorageType> m_storage;
};

#endif /* _SERVICEMODEL_H */

