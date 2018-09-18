namespace cpp OpenStars.Platform.ConversationStore
namespace go OpenStars.Platform.ConversationStore
namespace java OpenStars.Platform.ConversationStore

typedef i64 TKey

enum TErrorCode{
    EGood = 0,
    ENotFound = -1,
    EUnknown = -2 ,
    EDataExisted = -3
}

struct TConversationInfo{
    1: TKey cid,
    2: string cname,
    3: i64 lastmessage,
    4: i64 lasttime,
    5: i64 status
    
}

typedef TConversationInfo TData


struct TDataResult{
    1: TErrorCode errorCode,
    2: optional TConversationInfo data
}
struct TListDataResult{
    1: TErrorCode errorCode,
    2: optional map<TKey,TConversationInfo> listconversation,
    
}



service TDataService{
    TDataResult getData(1: TKey key), 
    TErrorCode putData(1: TKey key, 2: TConversationInfo data),
    TListDataResult getListData(1: list<i64> keys),
    

}

service TConversationStoreService extends TDataService{
    
}


