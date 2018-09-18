namespace cpp OpenStars.Platform.MessageStore
namespace go OpenStars.Platform.MessageStore
namespace java OpenStars.Platform.MessageStore

typedef i64 TKey

enum TErrorCode{
    EGood = 0,
    ENotFound = -1,
    EUnknown = -2 ,
    EDataExisted = -3
}

struct TMessageInfo{
    1: TKey mid,
    2: string content,
    3: string sender,
    4: i64 cid,
    5: i64 timesend,
    6: i64 status, //for using with secp256k1
}

typedef TMessageInfo TData


struct TDataResult{
    1: TErrorCode errorCode,
    2: optional TMessageInfo data
    
}
struct TListDataResult{
    1: TErrorCode errorCode,
    2: optional map<TKey,TMessageInfo> listdata
}
service TDataServiceR{
    TDataResult getData(1: TKey key), 
}

service TDataService{
    TDataResult getData(1: TKey key), 
    TListDataResult getListMessages(1: list<TKey> listKey),
    TErrorCode putData(1: TKey key, 2: TMessageInfo data),
    TErrorCode removeData(1: TKey key),
    TErrorCode deleteLogicData(1: TKey key),
    
    
}

service TMessageStoreService extends TDataService{
    
}


