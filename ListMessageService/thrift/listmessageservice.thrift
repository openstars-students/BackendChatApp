namespace cpp OpenStars.Platform.ListMessageService
namespace go OpenStars.Platform.ListMessageService
namespace java OpenStars.Platform.ListMessageService

typedef i64 TKey

enum TErrorCode{
    EGood = 0,
    ENotFound = -1,
    EUnknown = -2 ,
    EDataExisted = -3
}

struct TValue{
    1: TKey uid
     2: list<i64> listmid,

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
    TErrorCode addMessage(1: TKey key, 2: i64 mid),
    TErrorCode removeMessage(1: TKey key, 2: i64 mid)
}

service TListMessageService extends TDataService{
    
}


