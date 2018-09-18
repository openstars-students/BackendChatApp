/* 
 * File:   ZServiceModel.h
 * Author: trungthanh
 *
 * Created on February 23, 2012, 6:13 PM
 */

#ifndef ZCACHEMODEL_H
#define ZCACHEMODEL_H

#include <vector>
#include <map>
#include "ServiceFactoryT.h"
#include "storagedef.h"
#include "i64toi64set_shared_types.h"

class ServiceModel {
public:
    ServiceModel(Poco::SharedPtr<PersistentStorageType> aStorage);
    virtual ~ServiceModel(void);

public:
    void getValue(OpenStars::Core::I64ToI64Set::Data::TValue& _return, const OpenStars::Core::I64ToI64Set::Data::TKey key);
    void getValue_random(OpenStars::Core::I64ToI64Set::Data::TValue& _return, const OpenStars::Core::I64ToI64Set::Data::TKey key, const int32_t size);
    void getValue_slice(OpenStars::Core::I64ToI64Set::Data::TValue& _return, const OpenStars::Core::I64ToI64Set::Data::TKey key, const int32_t idxFrom, const int32_t size);
    void getValueMulti(std::map<OpenStars::Core::I64ToI64Set::Data::TKey, OpenStars::Core::I64ToI64Set::Data::TValue>& _return, const std::vector<OpenStars::Core::I64ToI64Set::Data::TKey>& keys);
    bool hasItem(const OpenStars::Core::I64ToI64Set::Data::TKey key, const OpenStars::Core::I64ToI64Set::Data::TItem item);
    int32_t getSize(const OpenStars::Core::I64ToI64Set::Data::TKey key);
    void getSizeMulti(std::map<OpenStars::Core::I64ToI64Set::Data::TKey, int32_t>& _return, const std::vector<OpenStars::Core::I64ToI64Set::Data::TKey>& keys);

    bool setItems(const OpenStars::Core::I64ToI64Set::Data::TKey key, const std::vector<OpenStars::Core::I64ToI64Set::Data::TItem>& items);
    bool clearItems(const OpenStars::Core::I64ToI64Set::Data::TKey key);
    bool addItem(const OpenStars::Core::I64ToI64Set::Data::TKey key, const OpenStars::Core::I64ToI64Set::Data::TItem item);
    bool addItems(const OpenStars::Core::I64ToI64Set::Data::TKey key, const std::vector<OpenStars::Core::I64ToI64Set::Data::TItem>& items);
    bool removeItem(const OpenStars::Core::I64ToI64Set::Data::TKey key, const OpenStars::Core::I64ToI64Set::Data::TItem item);
    bool removeItems(const OpenStars::Core::I64ToI64Set::Data::TKey key, const std::vector<OpenStars::Core::I64ToI64Set::Data::TItem>& items);

private:
    ServiceModel(const ServiceModel& orig);
    Poco::SharedPtr<PersistentStorageType> m_storage;
};

#endif /* ZCACHEMODEL_H */

