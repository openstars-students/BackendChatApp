/* 
 * File:   storagedef.h
 * Author: trungthanh
 *
 * Created on February 22, 2012, 4:57 PM
 */

#ifndef STORAGEDEF_H
#define STORAGEDEF_H

#include "ModelData.h"
#include "Storage/CachePersistent.h"
#include "Caching/AbstractCache.h"
#include "Caching/CacheFactory.h"
#include "thriftutil/TSerializer.h"
#include "Hashing/DefaultHasher.h"

//using namespace openstars::storage;

typedef OpenStars::Core::I64ToI64Set::Data::TKey KEYTYPE;
typedef OpenStars::Core::I64ToI64Set::Data::TValue VALUETYPE;

typedef TSerializer<VALUETYPE> DataSerializer;
typedef openstars::storage::ObjectStorage< KEYTYPE
, model::ModelData
, DataSerializer > BackendStorageType;

typedef openstars::storage::CachePersistent<KEYTYPE
, model::ModelData
, BackendStorageType
> PersistentStorageType;


typedef PersistentStorageType::CacheType CacheType;
typedef openstars::hashing::DefaultHasher HasherType;

typedef openstars::caching::BasicCacheFactory< KEYTYPE, model::ModelData, HasherType > CacheFactory;



#endif /* STORAGEDEF_H */

