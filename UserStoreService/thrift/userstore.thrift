namespace cpp OpenStars.Platform.UserStore
namespace go OpenStars.Platform.UserStore
namespace java OpenStars.Platform.UserStore

typedef i64 TKey

enum TErrorCode{
    EGood = 0,
    ENotFound = -1,
    EUnknown = -2 ,
    EDataExisted = -3
}

struct TUserInfo{
    1: TKey uid
    2: string username,
    3: string displayname,
    4: string emails,
    5: string mobiles,
    6: list<i64> listfriend,
    7: list<i64> listconversation,
    8: i64 status,
    9: string publickey, //for using with secp256k1
}

typedef TUserInfo TData


struct TDataResult{
    1: TErrorCode errorCode,
    2: optional TUserInfo data 
}
struct TListDataUsers{
    1: TErrorCode errorCode,
    2: optional map<TKey,TUserInfo> listuser,
    
}

service TDataServiceR{
    TDataResult getData(1: TKey key), 
}

service TDataService{
    TDataResult getData(1: TKey key), 
    TListDataUsers getListUsers(1: list<TKey> keys),
    bool hasUser (1: string pubkey, 2: i64 keys),
    TKey getIDByPublicKey (1: string publickey, 2: i64 lastkey),

    TErrorCode putData(1: TKey key, 2: TUserInfo data),
    //TErrorCode addFriend (1: TKey uid, 2: i64 friendid),
    //TErrorCode unFriend (1: TKey uid, 2: i64 friendid),
    //TErrorCode addConversation (1:TKey uid, 2: i64 cid),
    //TErrorCode deleteConversation (1:TKey uid, 2: i64 cid),
    //TErrorCode removeUser(1: TKey uid),
    TErrorCode deleteUser (1: TKey uid),
    
}

service TUserStoreService extends TDataService{
    
}


