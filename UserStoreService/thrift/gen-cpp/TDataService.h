/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef TDataService_H
#define TDataService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "userstore_types.h"

namespace OpenStars { namespace Platform { namespace UserStore {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class TDataServiceIf {
 public:
  virtual ~TDataServiceIf() {}
  virtual void getData(TDataResult& _return, const TKey key) = 0;
  virtual void getListUsers(TListDataUsers& _return, const std::vector<TKey> & keys) = 0;
  virtual TErrorCode::type hasUser(const std::string& username, const std::vector<TKey> & keys) = 0;
  virtual TKey getIDByPublicKey(const std::string& publickey, const int64_t lastkey) = 0;
  virtual TErrorCode::type putData(const TKey key, const TUserInfo& data) = 0;
  virtual TErrorCode::type addConversation(const TKey uid, const int64_t cid) = 0;
  virtual TErrorCode::type deleteConversation(const TKey uid, const int64_t cid) = 0;
  virtual TErrorCode::type deleteUser(const TKey uid) = 0;
};

class TDataServiceIfFactory {
 public:
  typedef TDataServiceIf Handler;

  virtual ~TDataServiceIfFactory() {}

  virtual TDataServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(TDataServiceIf* /* handler */) = 0;
};

class TDataServiceIfSingletonFactory : virtual public TDataServiceIfFactory {
 public:
  TDataServiceIfSingletonFactory(const ::apache::thrift::stdcxx::shared_ptr<TDataServiceIf>& iface) : iface_(iface) {}
  virtual ~TDataServiceIfSingletonFactory() {}

  virtual TDataServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(TDataServiceIf* /* handler */) {}

 protected:
  ::apache::thrift::stdcxx::shared_ptr<TDataServiceIf> iface_;
};

class TDataServiceNull : virtual public TDataServiceIf {
 public:
  virtual ~TDataServiceNull() {}
  void getData(TDataResult& /* _return */, const TKey /* key */) {
    return;
  }
  void getListUsers(TListDataUsers& /* _return */, const std::vector<TKey> & /* keys */) {
    return;
  }
  TErrorCode::type hasUser(const std::string& /* username */, const std::vector<TKey> & /* keys */) {
    TErrorCode::type _return = (TErrorCode::type)0;
    return _return;
  }
  TKey getIDByPublicKey(const std::string& /* publickey */, const int64_t /* lastkey */) {
    TKey _return = 0;
    return _return;
  }
  TErrorCode::type putData(const TKey /* key */, const TUserInfo& /* data */) {
    TErrorCode::type _return = (TErrorCode::type)0;
    return _return;
  }
  TErrorCode::type addConversation(const TKey /* uid */, const int64_t /* cid */) {
    TErrorCode::type _return = (TErrorCode::type)0;
    return _return;
  }
  TErrorCode::type deleteConversation(const TKey /* uid */, const int64_t /* cid */) {
    TErrorCode::type _return = (TErrorCode::type)0;
    return _return;
  }
  TErrorCode::type deleteUser(const TKey /* uid */) {
    TErrorCode::type _return = (TErrorCode::type)0;
    return _return;
  }
};

typedef struct _TDataService_getData_args__isset {
  _TDataService_getData_args__isset() : key(false) {}
  bool key :1;
} _TDataService_getData_args__isset;

class TDataService_getData_args {
 public:

  TDataService_getData_args(const TDataService_getData_args&);
  TDataService_getData_args& operator=(const TDataService_getData_args&);
  TDataService_getData_args() : key(0) {
  }

  virtual ~TDataService_getData_args() throw();
  TKey key;

  _TDataService_getData_args__isset __isset;

  void __set_key(const TKey val);

  bool operator == (const TDataService_getData_args & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    return true;
  }
  bool operator != (const TDataService_getData_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDataService_getData_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class TDataService_getData_pargs {
 public:


  virtual ~TDataService_getData_pargs() throw();
  const TKey* key;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TDataService_getData_result__isset {
  _TDataService_getData_result__isset() : success(false) {}
  bool success :1;
} _TDataService_getData_result__isset;

class TDataService_getData_result {
 public:

  TDataService_getData_result(const TDataService_getData_result&);
  TDataService_getData_result& operator=(const TDataService_getData_result&);
  TDataService_getData_result() {
  }

  virtual ~TDataService_getData_result() throw();
  TDataResult success;

  _TDataService_getData_result__isset __isset;

  void __set_success(const TDataResult& val);

  bool operator == (const TDataService_getData_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const TDataService_getData_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDataService_getData_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TDataService_getData_presult__isset {
  _TDataService_getData_presult__isset() : success(false) {}
  bool success :1;
} _TDataService_getData_presult__isset;

class TDataService_getData_presult {
 public:


  virtual ~TDataService_getData_presult() throw();
  TDataResult* success;

  _TDataService_getData_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _TDataService_getListUsers_args__isset {
  _TDataService_getListUsers_args__isset() : keys(false) {}
  bool keys :1;
} _TDataService_getListUsers_args__isset;

class TDataService_getListUsers_args {
 public:

  TDataService_getListUsers_args(const TDataService_getListUsers_args&);
  TDataService_getListUsers_args& operator=(const TDataService_getListUsers_args&);
  TDataService_getListUsers_args() {
  }

  virtual ~TDataService_getListUsers_args() throw();
  std::vector<TKey>  keys;

  _TDataService_getListUsers_args__isset __isset;

  void __set_keys(const std::vector<TKey> & val);

  bool operator == (const TDataService_getListUsers_args & rhs) const
  {
    if (!(keys == rhs.keys))
      return false;
    return true;
  }
  bool operator != (const TDataService_getListUsers_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDataService_getListUsers_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class TDataService_getListUsers_pargs {
 public:


  virtual ~TDataService_getListUsers_pargs() throw();
  const std::vector<TKey> * keys;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TDataService_getListUsers_result__isset {
  _TDataService_getListUsers_result__isset() : success(false) {}
  bool success :1;
} _TDataService_getListUsers_result__isset;

class TDataService_getListUsers_result {
 public:

  TDataService_getListUsers_result(const TDataService_getListUsers_result&);
  TDataService_getListUsers_result& operator=(const TDataService_getListUsers_result&);
  TDataService_getListUsers_result() {
  }

  virtual ~TDataService_getListUsers_result() throw();
  TListDataUsers success;

  _TDataService_getListUsers_result__isset __isset;

  void __set_success(const TListDataUsers& val);

  bool operator == (const TDataService_getListUsers_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const TDataService_getListUsers_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDataService_getListUsers_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TDataService_getListUsers_presult__isset {
  _TDataService_getListUsers_presult__isset() : success(false) {}
  bool success :1;
} _TDataService_getListUsers_presult__isset;

class TDataService_getListUsers_presult {
 public:


  virtual ~TDataService_getListUsers_presult() throw();
  TListDataUsers* success;

  _TDataService_getListUsers_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _TDataService_hasUser_args__isset {
  _TDataService_hasUser_args__isset() : username(false), keys(false) {}
  bool username :1;
  bool keys :1;
} _TDataService_hasUser_args__isset;

class TDataService_hasUser_args {
 public:

  TDataService_hasUser_args(const TDataService_hasUser_args&);
  TDataService_hasUser_args& operator=(const TDataService_hasUser_args&);
  TDataService_hasUser_args() : username() {
  }

  virtual ~TDataService_hasUser_args() throw();
  std::string username;
  std::vector<TKey>  keys;

  _TDataService_hasUser_args__isset __isset;

  void __set_username(const std::string& val);

  void __set_keys(const std::vector<TKey> & val);

  bool operator == (const TDataService_hasUser_args & rhs) const
  {
    if (!(username == rhs.username))
      return false;
    if (!(keys == rhs.keys))
      return false;
    return true;
  }
  bool operator != (const TDataService_hasUser_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDataService_hasUser_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class TDataService_hasUser_pargs {
 public:


  virtual ~TDataService_hasUser_pargs() throw();
  const std::string* username;
  const std::vector<TKey> * keys;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TDataService_hasUser_result__isset {
  _TDataService_hasUser_result__isset() : success(false) {}
  bool success :1;
} _TDataService_hasUser_result__isset;

class TDataService_hasUser_result {
 public:

  TDataService_hasUser_result(const TDataService_hasUser_result&);
  TDataService_hasUser_result& operator=(const TDataService_hasUser_result&);
  TDataService_hasUser_result() : success((TErrorCode::type)0) {
  }

  virtual ~TDataService_hasUser_result() throw();
  TErrorCode::type success;

  _TDataService_hasUser_result__isset __isset;

  void __set_success(const TErrorCode::type val);

  bool operator == (const TDataService_hasUser_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const TDataService_hasUser_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDataService_hasUser_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TDataService_hasUser_presult__isset {
  _TDataService_hasUser_presult__isset() : success(false) {}
  bool success :1;
} _TDataService_hasUser_presult__isset;

class TDataService_hasUser_presult {
 public:


  virtual ~TDataService_hasUser_presult() throw();
  TErrorCode::type* success;

  _TDataService_hasUser_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _TDataService_getIDByPublicKey_args__isset {
  _TDataService_getIDByPublicKey_args__isset() : publickey(false), lastkey(false) {}
  bool publickey :1;
  bool lastkey :1;
} _TDataService_getIDByPublicKey_args__isset;

class TDataService_getIDByPublicKey_args {
 public:

  TDataService_getIDByPublicKey_args(const TDataService_getIDByPublicKey_args&);
  TDataService_getIDByPublicKey_args& operator=(const TDataService_getIDByPublicKey_args&);
  TDataService_getIDByPublicKey_args() : publickey(), lastkey(0) {
  }

  virtual ~TDataService_getIDByPublicKey_args() throw();
  std::string publickey;
  int64_t lastkey;

  _TDataService_getIDByPublicKey_args__isset __isset;

  void __set_publickey(const std::string& val);

  void __set_lastkey(const int64_t val);

  bool operator == (const TDataService_getIDByPublicKey_args & rhs) const
  {
    if (!(publickey == rhs.publickey))
      return false;
    if (!(lastkey == rhs.lastkey))
      return false;
    return true;
  }
  bool operator != (const TDataService_getIDByPublicKey_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDataService_getIDByPublicKey_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class TDataService_getIDByPublicKey_pargs {
 public:


  virtual ~TDataService_getIDByPublicKey_pargs() throw();
  const std::string* publickey;
  const int64_t* lastkey;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TDataService_getIDByPublicKey_result__isset {
  _TDataService_getIDByPublicKey_result__isset() : success(false) {}
  bool success :1;
} _TDataService_getIDByPublicKey_result__isset;

class TDataService_getIDByPublicKey_result {
 public:

  TDataService_getIDByPublicKey_result(const TDataService_getIDByPublicKey_result&);
  TDataService_getIDByPublicKey_result& operator=(const TDataService_getIDByPublicKey_result&);
  TDataService_getIDByPublicKey_result() : success(0) {
  }

  virtual ~TDataService_getIDByPublicKey_result() throw();
  TKey success;

  _TDataService_getIDByPublicKey_result__isset __isset;

  void __set_success(const TKey val);

  bool operator == (const TDataService_getIDByPublicKey_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const TDataService_getIDByPublicKey_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDataService_getIDByPublicKey_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TDataService_getIDByPublicKey_presult__isset {
  _TDataService_getIDByPublicKey_presult__isset() : success(false) {}
  bool success :1;
} _TDataService_getIDByPublicKey_presult__isset;

class TDataService_getIDByPublicKey_presult {
 public:


  virtual ~TDataService_getIDByPublicKey_presult() throw();
  TKey* success;

  _TDataService_getIDByPublicKey_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _TDataService_putData_args__isset {
  _TDataService_putData_args__isset() : key(false), data(false) {}
  bool key :1;
  bool data :1;
} _TDataService_putData_args__isset;

class TDataService_putData_args {
 public:

  TDataService_putData_args(const TDataService_putData_args&);
  TDataService_putData_args& operator=(const TDataService_putData_args&);
  TDataService_putData_args() : key(0) {
  }

  virtual ~TDataService_putData_args() throw();
  TKey key;
  TUserInfo data;

  _TDataService_putData_args__isset __isset;

  void __set_key(const TKey val);

  void __set_data(const TUserInfo& val);

  bool operator == (const TDataService_putData_args & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    if (!(data == rhs.data))
      return false;
    return true;
  }
  bool operator != (const TDataService_putData_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDataService_putData_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class TDataService_putData_pargs {
 public:


  virtual ~TDataService_putData_pargs() throw();
  const TKey* key;
  const TUserInfo* data;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TDataService_putData_result__isset {
  _TDataService_putData_result__isset() : success(false) {}
  bool success :1;
} _TDataService_putData_result__isset;

class TDataService_putData_result {
 public:

  TDataService_putData_result(const TDataService_putData_result&);
  TDataService_putData_result& operator=(const TDataService_putData_result&);
  TDataService_putData_result() : success((TErrorCode::type)0) {
  }

  virtual ~TDataService_putData_result() throw();
  TErrorCode::type success;

  _TDataService_putData_result__isset __isset;

  void __set_success(const TErrorCode::type val);

  bool operator == (const TDataService_putData_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const TDataService_putData_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDataService_putData_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TDataService_putData_presult__isset {
  _TDataService_putData_presult__isset() : success(false) {}
  bool success :1;
} _TDataService_putData_presult__isset;

class TDataService_putData_presult {
 public:


  virtual ~TDataService_putData_presult() throw();
  TErrorCode::type* success;

  _TDataService_putData_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _TDataService_addConversation_args__isset {
  _TDataService_addConversation_args__isset() : uid(false), cid(false) {}
  bool uid :1;
  bool cid :1;
} _TDataService_addConversation_args__isset;

class TDataService_addConversation_args {
 public:

  TDataService_addConversation_args(const TDataService_addConversation_args&);
  TDataService_addConversation_args& operator=(const TDataService_addConversation_args&);
  TDataService_addConversation_args() : uid(0), cid(0) {
  }

  virtual ~TDataService_addConversation_args() throw();
  TKey uid;
  int64_t cid;

  _TDataService_addConversation_args__isset __isset;

  void __set_uid(const TKey val);

  void __set_cid(const int64_t val);

  bool operator == (const TDataService_addConversation_args & rhs) const
  {
    if (!(uid == rhs.uid))
      return false;
    if (!(cid == rhs.cid))
      return false;
    return true;
  }
  bool operator != (const TDataService_addConversation_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDataService_addConversation_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class TDataService_addConversation_pargs {
 public:


  virtual ~TDataService_addConversation_pargs() throw();
  const TKey* uid;
  const int64_t* cid;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TDataService_addConversation_result__isset {
  _TDataService_addConversation_result__isset() : success(false) {}
  bool success :1;
} _TDataService_addConversation_result__isset;

class TDataService_addConversation_result {
 public:

  TDataService_addConversation_result(const TDataService_addConversation_result&);
  TDataService_addConversation_result& operator=(const TDataService_addConversation_result&);
  TDataService_addConversation_result() : success((TErrorCode::type)0) {
  }

  virtual ~TDataService_addConversation_result() throw();
  TErrorCode::type success;

  _TDataService_addConversation_result__isset __isset;

  void __set_success(const TErrorCode::type val);

  bool operator == (const TDataService_addConversation_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const TDataService_addConversation_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDataService_addConversation_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TDataService_addConversation_presult__isset {
  _TDataService_addConversation_presult__isset() : success(false) {}
  bool success :1;
} _TDataService_addConversation_presult__isset;

class TDataService_addConversation_presult {
 public:


  virtual ~TDataService_addConversation_presult() throw();
  TErrorCode::type* success;

  _TDataService_addConversation_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _TDataService_deleteConversation_args__isset {
  _TDataService_deleteConversation_args__isset() : uid(false), cid(false) {}
  bool uid :1;
  bool cid :1;
} _TDataService_deleteConversation_args__isset;

class TDataService_deleteConversation_args {
 public:

  TDataService_deleteConversation_args(const TDataService_deleteConversation_args&);
  TDataService_deleteConversation_args& operator=(const TDataService_deleteConversation_args&);
  TDataService_deleteConversation_args() : uid(0), cid(0) {
  }

  virtual ~TDataService_deleteConversation_args() throw();
  TKey uid;
  int64_t cid;

  _TDataService_deleteConversation_args__isset __isset;

  void __set_uid(const TKey val);

  void __set_cid(const int64_t val);

  bool operator == (const TDataService_deleteConversation_args & rhs) const
  {
    if (!(uid == rhs.uid))
      return false;
    if (!(cid == rhs.cid))
      return false;
    return true;
  }
  bool operator != (const TDataService_deleteConversation_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDataService_deleteConversation_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class TDataService_deleteConversation_pargs {
 public:


  virtual ~TDataService_deleteConversation_pargs() throw();
  const TKey* uid;
  const int64_t* cid;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TDataService_deleteConversation_result__isset {
  _TDataService_deleteConversation_result__isset() : success(false) {}
  bool success :1;
} _TDataService_deleteConversation_result__isset;

class TDataService_deleteConversation_result {
 public:

  TDataService_deleteConversation_result(const TDataService_deleteConversation_result&);
  TDataService_deleteConversation_result& operator=(const TDataService_deleteConversation_result&);
  TDataService_deleteConversation_result() : success((TErrorCode::type)0) {
  }

  virtual ~TDataService_deleteConversation_result() throw();
  TErrorCode::type success;

  _TDataService_deleteConversation_result__isset __isset;

  void __set_success(const TErrorCode::type val);

  bool operator == (const TDataService_deleteConversation_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const TDataService_deleteConversation_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDataService_deleteConversation_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TDataService_deleteConversation_presult__isset {
  _TDataService_deleteConversation_presult__isset() : success(false) {}
  bool success :1;
} _TDataService_deleteConversation_presult__isset;

class TDataService_deleteConversation_presult {
 public:


  virtual ~TDataService_deleteConversation_presult() throw();
  TErrorCode::type* success;

  _TDataService_deleteConversation_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _TDataService_deleteUser_args__isset {
  _TDataService_deleteUser_args__isset() : uid(false) {}
  bool uid :1;
} _TDataService_deleteUser_args__isset;

class TDataService_deleteUser_args {
 public:

  TDataService_deleteUser_args(const TDataService_deleteUser_args&);
  TDataService_deleteUser_args& operator=(const TDataService_deleteUser_args&);
  TDataService_deleteUser_args() : uid(0) {
  }

  virtual ~TDataService_deleteUser_args() throw();
  TKey uid;

  _TDataService_deleteUser_args__isset __isset;

  void __set_uid(const TKey val);

  bool operator == (const TDataService_deleteUser_args & rhs) const
  {
    if (!(uid == rhs.uid))
      return false;
    return true;
  }
  bool operator != (const TDataService_deleteUser_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDataService_deleteUser_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class TDataService_deleteUser_pargs {
 public:


  virtual ~TDataService_deleteUser_pargs() throw();
  const TKey* uid;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TDataService_deleteUser_result__isset {
  _TDataService_deleteUser_result__isset() : success(false) {}
  bool success :1;
} _TDataService_deleteUser_result__isset;

class TDataService_deleteUser_result {
 public:

  TDataService_deleteUser_result(const TDataService_deleteUser_result&);
  TDataService_deleteUser_result& operator=(const TDataService_deleteUser_result&);
  TDataService_deleteUser_result() : success((TErrorCode::type)0) {
  }

  virtual ~TDataService_deleteUser_result() throw();
  TErrorCode::type success;

  _TDataService_deleteUser_result__isset __isset;

  void __set_success(const TErrorCode::type val);

  bool operator == (const TDataService_deleteUser_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const TDataService_deleteUser_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDataService_deleteUser_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TDataService_deleteUser_presult__isset {
  _TDataService_deleteUser_presult__isset() : success(false) {}
  bool success :1;
} _TDataService_deleteUser_presult__isset;

class TDataService_deleteUser_presult {
 public:


  virtual ~TDataService_deleteUser_presult() throw();
  TErrorCode::type* success;

  _TDataService_deleteUser_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class TDataServiceClient : virtual public TDataServiceIf {
 public:
  TDataServiceClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  TDataServiceClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void getData(TDataResult& _return, const TKey key);
  void send_getData(const TKey key);
  void recv_getData(TDataResult& _return);
  void getListUsers(TListDataUsers& _return, const std::vector<TKey> & keys);
  void send_getListUsers(const std::vector<TKey> & keys);
  void recv_getListUsers(TListDataUsers& _return);
  TErrorCode::type hasUser(const std::string& username, const std::vector<TKey> & keys);
  void send_hasUser(const std::string& username, const std::vector<TKey> & keys);
  TErrorCode::type recv_hasUser();
  TKey getIDByPublicKey(const std::string& publickey, const int64_t lastkey);
  void send_getIDByPublicKey(const std::string& publickey, const int64_t lastkey);
  TKey recv_getIDByPublicKey();
  TErrorCode::type putData(const TKey key, const TUserInfo& data);
  void send_putData(const TKey key, const TUserInfo& data);
  TErrorCode::type recv_putData();
  TErrorCode::type addConversation(const TKey uid, const int64_t cid);
  void send_addConversation(const TKey uid, const int64_t cid);
  TErrorCode::type recv_addConversation();
  TErrorCode::type deleteConversation(const TKey uid, const int64_t cid);
  void send_deleteConversation(const TKey uid, const int64_t cid);
  TErrorCode::type recv_deleteConversation();
  TErrorCode::type deleteUser(const TKey uid);
  void send_deleteUser(const TKey uid);
  TErrorCode::type recv_deleteUser();
 protected:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class TDataServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::apache::thrift::stdcxx::shared_ptr<TDataServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (TDataServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getData(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getListUsers(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_hasUser(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getIDByPublicKey(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_putData(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_addConversation(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_deleteConversation(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_deleteUser(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  TDataServiceProcessor(::apache::thrift::stdcxx::shared_ptr<TDataServiceIf> iface) :
    iface_(iface) {
    processMap_["getData"] = &TDataServiceProcessor::process_getData;
    processMap_["getListUsers"] = &TDataServiceProcessor::process_getListUsers;
    processMap_["hasUser"] = &TDataServiceProcessor::process_hasUser;
    processMap_["getIDByPublicKey"] = &TDataServiceProcessor::process_getIDByPublicKey;
    processMap_["putData"] = &TDataServiceProcessor::process_putData;
    processMap_["addConversation"] = &TDataServiceProcessor::process_addConversation;
    processMap_["deleteConversation"] = &TDataServiceProcessor::process_deleteConversation;
    processMap_["deleteUser"] = &TDataServiceProcessor::process_deleteUser;
  }

  virtual ~TDataServiceProcessor() {}
};

class TDataServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  TDataServiceProcessorFactory(const ::apache::thrift::stdcxx::shared_ptr< TDataServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::apache::thrift::stdcxx::shared_ptr< TDataServiceIfFactory > handlerFactory_;
};

class TDataServiceMultiface : virtual public TDataServiceIf {
 public:
  TDataServiceMultiface(std::vector<apache::thrift::stdcxx::shared_ptr<TDataServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~TDataServiceMultiface() {}
 protected:
  std::vector<apache::thrift::stdcxx::shared_ptr<TDataServiceIf> > ifaces_;
  TDataServiceMultiface() {}
  void add(::apache::thrift::stdcxx::shared_ptr<TDataServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void getData(TDataResult& _return, const TKey key) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getData(_return, key);
    }
    ifaces_[i]->getData(_return, key);
    return;
  }

  void getListUsers(TListDataUsers& _return, const std::vector<TKey> & keys) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getListUsers(_return, keys);
    }
    ifaces_[i]->getListUsers(_return, keys);
    return;
  }

  TErrorCode::type hasUser(const std::string& username, const std::vector<TKey> & keys) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->hasUser(username, keys);
    }
    return ifaces_[i]->hasUser(username, keys);
  }

  TKey getIDByPublicKey(const std::string& publickey, const int64_t lastkey) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getIDByPublicKey(publickey, lastkey);
    }
    return ifaces_[i]->getIDByPublicKey(publickey, lastkey);
  }

  TErrorCode::type putData(const TKey key, const TUserInfo& data) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->putData(key, data);
    }
    return ifaces_[i]->putData(key, data);
  }

  TErrorCode::type addConversation(const TKey uid, const int64_t cid) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->addConversation(uid, cid);
    }
    return ifaces_[i]->addConversation(uid, cid);
  }

  TErrorCode::type deleteConversation(const TKey uid, const int64_t cid) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->deleteConversation(uid, cid);
    }
    return ifaces_[i]->deleteConversation(uid, cid);
  }

  TErrorCode::type deleteUser(const TKey uid) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->deleteUser(uid);
    }
    return ifaces_[i]->deleteUser(uid);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class TDataServiceConcurrentClient : virtual public TDataServiceIf {
 public:
  TDataServiceConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  TDataServiceConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void getData(TDataResult& _return, const TKey key);
  int32_t send_getData(const TKey key);
  void recv_getData(TDataResult& _return, const int32_t seqid);
  void getListUsers(TListDataUsers& _return, const std::vector<TKey> & keys);
  int32_t send_getListUsers(const std::vector<TKey> & keys);
  void recv_getListUsers(TListDataUsers& _return, const int32_t seqid);
  TErrorCode::type hasUser(const std::string& username, const std::vector<TKey> & keys);
  int32_t send_hasUser(const std::string& username, const std::vector<TKey> & keys);
  TErrorCode::type recv_hasUser(const int32_t seqid);
  TKey getIDByPublicKey(const std::string& publickey, const int64_t lastkey);
  int32_t send_getIDByPublicKey(const std::string& publickey, const int64_t lastkey);
  TKey recv_getIDByPublicKey(const int32_t seqid);
  TErrorCode::type putData(const TKey key, const TUserInfo& data);
  int32_t send_putData(const TKey key, const TUserInfo& data);
  TErrorCode::type recv_putData(const int32_t seqid);
  TErrorCode::type addConversation(const TKey uid, const int64_t cid);
  int32_t send_addConversation(const TKey uid, const int64_t cid);
  TErrorCode::type recv_addConversation(const int32_t seqid);
  TErrorCode::type deleteConversation(const TKey uid, const int64_t cid);
  int32_t send_deleteConversation(const TKey uid, const int64_t cid);
  TErrorCode::type recv_deleteConversation(const int32_t seqid);
  TErrorCode::type deleteUser(const TKey uid);
  int32_t send_deleteUser(const TKey uid);
  TErrorCode::type recv_deleteUser(const int32_t seqid);
 protected:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif

}}} // namespace

#endif