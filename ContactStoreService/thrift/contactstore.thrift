namespace cpp OpenStars.Platform.ContactStore
namespace go OpenStars.Platform.ContactStore
namespace java OpenStars.Platform.ContactStore

typedef i64 TKey

enum TErrorCode{
    EGood = 0,
    ENotFound = -1,
    EUnknown = -2 ,
    EDataExisted = -3
}

struct TValue{
    1: TKey uid,
    2: list<i64> listuid
}

typedef TValue TData


struct TDataResult{
    1: TErrorCode errorCode,
    2: optional TValue data
    
}

service TDataServiceR{
    TDataResult getData(1: TKey key), 
}

service TDataService{
    TDataResult getData(1: TKey key), 
    TErrorCode putData(1: TKey key, 2: TValue data),
    TErrorCode addFriend (1: TKey uid, 2: i64 friendid),
    TErrorCode unFriend (1: TKey uid, 2: i64 friendid),
}

service TContactStoreService extends TDataService{
    
}


