namespace cpp OpenStars.Platform.ListMemberService
namespace go OpenStars.Platform.ListMemberService
namespace java OpenStars.Platform.ListMemberService

typedef i64 TKey

enum TErrorCode{
    EGood = 0,
    ENotFound = -1,
    EUnknown = -2 ,
    EDataExisted = -3
}

struct TValue{
    1: TKey uid
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
    TErrorCode addMember(1: TKey key, 2: i64 uid),
    TErrorCode removeMember(1: TKey key, 2: i64 uid)
}

service TListMemberService extends TDataService{
    
}


