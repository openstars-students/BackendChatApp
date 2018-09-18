namespace cpp OpenStars.Platform.UserConversationService
namespace go OpenStars.Platform.UserConversationService
namespace java OpenStars.Platform.UserConversationService

typedef i64 TKey

enum TErrorCode{
    EGood = 0,
    ENotFound = -1,
    EUnknown = -2 ,
    EDataExisted = -3
}

struct TValue{
    1: TKey uid
    2: list<i64> listcid,
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
    TErrorCode addConversation(1: TKey key, 2: i64 cid),
    TErrorCode removeConversation(1: TKey key, 2: i64 cid)
}

service TUserConversationService extends TDataService{
    
}


