/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef TI64ToI64SetService_H
#define TI64ToI64SetService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "i64toi64setservice_types.h"
#include "TI64ToI64SetServiceR.h"

namespace OpenStars { namespace Core { namespace I64ToI64Set {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class TI64ToI64SetServiceIf : virtual public TI64ToI64SetServiceRIf {
 public:
  virtual ~TI64ToI64SetServiceIf() {}
  virtual bool setItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> & items) = 0;
  virtual bool clearItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key) = 0;
  virtual bool addItem(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const  ::OpenStars::Core::I64ToI64Set::Data::TItem item) = 0;
  virtual bool addItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> & items) = 0;
  virtual bool removeItem(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const  ::OpenStars::Core::I64ToI64Set::Data::TItem item) = 0;
  virtual bool removeItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> & items) = 0;
};

class TI64ToI64SetServiceIfFactory : virtual public TI64ToI64SetServiceRIfFactory {
 public:
  typedef TI64ToI64SetServiceIf Handler;

  virtual ~TI64ToI64SetServiceIfFactory() {}

  virtual TI64ToI64SetServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(TI64ToI64SetServiceRIf* /* handler */) = 0;
};

class TI64ToI64SetServiceIfSingletonFactory : virtual public TI64ToI64SetServiceIfFactory {
 public:
  TI64ToI64SetServiceIfSingletonFactory(const ::apache::thrift::stdcxx::shared_ptr<TI64ToI64SetServiceIf>& iface) : iface_(iface) {}
  virtual ~TI64ToI64SetServiceIfSingletonFactory() {}

  virtual TI64ToI64SetServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(TI64ToI64SetServiceRIf* /* handler */) {}

 protected:
  ::apache::thrift::stdcxx::shared_ptr<TI64ToI64SetServiceIf> iface_;
};

class TI64ToI64SetServiceNull : virtual public TI64ToI64SetServiceIf , virtual public TI64ToI64SetServiceRNull {
 public:
  virtual ~TI64ToI64SetServiceNull() {}
  bool setItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey /* key */, const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> & /* items */) {
    bool _return = false;
    return _return;
  }
  bool clearItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey /* key */) {
    bool _return = false;
    return _return;
  }
  bool addItem(const  ::OpenStars::Core::I64ToI64Set::Data::TKey /* key */, const  ::OpenStars::Core::I64ToI64Set::Data::TItem /* item */) {
    bool _return = false;
    return _return;
  }
  bool addItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey /* key */, const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> & /* items */) {
    bool _return = false;
    return _return;
  }
  bool removeItem(const  ::OpenStars::Core::I64ToI64Set::Data::TKey /* key */, const  ::OpenStars::Core::I64ToI64Set::Data::TItem /* item */) {
    bool _return = false;
    return _return;
  }
  bool removeItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey /* key */, const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> & /* items */) {
    bool _return = false;
    return _return;
  }
};

typedef struct _TI64ToI64SetService_setItems_args__isset {
  _TI64ToI64SetService_setItems_args__isset() : key(false), items(false) {}
  bool key :1;
  bool items :1;
} _TI64ToI64SetService_setItems_args__isset;

class TI64ToI64SetService_setItems_args {
 public:

  TI64ToI64SetService_setItems_args(const TI64ToI64SetService_setItems_args&);
  TI64ToI64SetService_setItems_args& operator=(const TI64ToI64SetService_setItems_args&);
  TI64ToI64SetService_setItems_args() : key(0) {
  }

  virtual ~TI64ToI64SetService_setItems_args() throw();
   ::OpenStars::Core::I64ToI64Set::Data::TKey key;
  std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem>  items;

  _TI64ToI64SetService_setItems_args__isset __isset;

  void __set_key(const  ::OpenStars::Core::I64ToI64Set::Data::TKey val);

  void __set_items(const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> & val);

  bool operator == (const TI64ToI64SetService_setItems_args & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    if (!(items == rhs.items))
      return false;
    return true;
  }
  bool operator != (const TI64ToI64SetService_setItems_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TI64ToI64SetService_setItems_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class TI64ToI64SetService_setItems_pargs {
 public:


  virtual ~TI64ToI64SetService_setItems_pargs() throw();
  const  ::OpenStars::Core::I64ToI64Set::Data::TKey* key;
  const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> * items;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TI64ToI64SetService_setItems_result__isset {
  _TI64ToI64SetService_setItems_result__isset() : success(false) {}
  bool success :1;
} _TI64ToI64SetService_setItems_result__isset;

class TI64ToI64SetService_setItems_result {
 public:

  TI64ToI64SetService_setItems_result(const TI64ToI64SetService_setItems_result&);
  TI64ToI64SetService_setItems_result& operator=(const TI64ToI64SetService_setItems_result&);
  TI64ToI64SetService_setItems_result() : success(0) {
  }

  virtual ~TI64ToI64SetService_setItems_result() throw();
  bool success;

  _TI64ToI64SetService_setItems_result__isset __isset;

  void __set_success(const bool val);

  bool operator == (const TI64ToI64SetService_setItems_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const TI64ToI64SetService_setItems_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TI64ToI64SetService_setItems_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TI64ToI64SetService_setItems_presult__isset {
  _TI64ToI64SetService_setItems_presult__isset() : success(false) {}
  bool success :1;
} _TI64ToI64SetService_setItems_presult__isset;

class TI64ToI64SetService_setItems_presult {
 public:


  virtual ~TI64ToI64SetService_setItems_presult() throw();
  bool* success;

  _TI64ToI64SetService_setItems_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _TI64ToI64SetService_clearItems_args__isset {
  _TI64ToI64SetService_clearItems_args__isset() : key(false) {}
  bool key :1;
} _TI64ToI64SetService_clearItems_args__isset;

class TI64ToI64SetService_clearItems_args {
 public:

  TI64ToI64SetService_clearItems_args(const TI64ToI64SetService_clearItems_args&);
  TI64ToI64SetService_clearItems_args& operator=(const TI64ToI64SetService_clearItems_args&);
  TI64ToI64SetService_clearItems_args() : key(0) {
  }

  virtual ~TI64ToI64SetService_clearItems_args() throw();
   ::OpenStars::Core::I64ToI64Set::Data::TKey key;

  _TI64ToI64SetService_clearItems_args__isset __isset;

  void __set_key(const  ::OpenStars::Core::I64ToI64Set::Data::TKey val);

  bool operator == (const TI64ToI64SetService_clearItems_args & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    return true;
  }
  bool operator != (const TI64ToI64SetService_clearItems_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TI64ToI64SetService_clearItems_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class TI64ToI64SetService_clearItems_pargs {
 public:


  virtual ~TI64ToI64SetService_clearItems_pargs() throw();
  const  ::OpenStars::Core::I64ToI64Set::Data::TKey* key;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TI64ToI64SetService_clearItems_result__isset {
  _TI64ToI64SetService_clearItems_result__isset() : success(false) {}
  bool success :1;
} _TI64ToI64SetService_clearItems_result__isset;

class TI64ToI64SetService_clearItems_result {
 public:

  TI64ToI64SetService_clearItems_result(const TI64ToI64SetService_clearItems_result&);
  TI64ToI64SetService_clearItems_result& operator=(const TI64ToI64SetService_clearItems_result&);
  TI64ToI64SetService_clearItems_result() : success(0) {
  }

  virtual ~TI64ToI64SetService_clearItems_result() throw();
  bool success;

  _TI64ToI64SetService_clearItems_result__isset __isset;

  void __set_success(const bool val);

  bool operator == (const TI64ToI64SetService_clearItems_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const TI64ToI64SetService_clearItems_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TI64ToI64SetService_clearItems_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TI64ToI64SetService_clearItems_presult__isset {
  _TI64ToI64SetService_clearItems_presult__isset() : success(false) {}
  bool success :1;
} _TI64ToI64SetService_clearItems_presult__isset;

class TI64ToI64SetService_clearItems_presult {
 public:


  virtual ~TI64ToI64SetService_clearItems_presult() throw();
  bool* success;

  _TI64ToI64SetService_clearItems_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _TI64ToI64SetService_addItem_args__isset {
  _TI64ToI64SetService_addItem_args__isset() : key(false), item(false) {}
  bool key :1;
  bool item :1;
} _TI64ToI64SetService_addItem_args__isset;

class TI64ToI64SetService_addItem_args {
 public:

  TI64ToI64SetService_addItem_args(const TI64ToI64SetService_addItem_args&);
  TI64ToI64SetService_addItem_args& operator=(const TI64ToI64SetService_addItem_args&);
  TI64ToI64SetService_addItem_args() : key(0), item(0) {
  }

  virtual ~TI64ToI64SetService_addItem_args() throw();
   ::OpenStars::Core::I64ToI64Set::Data::TKey key;
   ::OpenStars::Core::I64ToI64Set::Data::TItem item;

  _TI64ToI64SetService_addItem_args__isset __isset;

  void __set_key(const  ::OpenStars::Core::I64ToI64Set::Data::TKey val);

  void __set_item(const  ::OpenStars::Core::I64ToI64Set::Data::TItem val);

  bool operator == (const TI64ToI64SetService_addItem_args & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    if (!(item == rhs.item))
      return false;
    return true;
  }
  bool operator != (const TI64ToI64SetService_addItem_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TI64ToI64SetService_addItem_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class TI64ToI64SetService_addItem_pargs {
 public:


  virtual ~TI64ToI64SetService_addItem_pargs() throw();
  const  ::OpenStars::Core::I64ToI64Set::Data::TKey* key;
  const  ::OpenStars::Core::I64ToI64Set::Data::TItem* item;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TI64ToI64SetService_addItem_result__isset {
  _TI64ToI64SetService_addItem_result__isset() : success(false) {}
  bool success :1;
} _TI64ToI64SetService_addItem_result__isset;

class TI64ToI64SetService_addItem_result {
 public:

  TI64ToI64SetService_addItem_result(const TI64ToI64SetService_addItem_result&);
  TI64ToI64SetService_addItem_result& operator=(const TI64ToI64SetService_addItem_result&);
  TI64ToI64SetService_addItem_result() : success(0) {
  }

  virtual ~TI64ToI64SetService_addItem_result() throw();
  bool success;

  _TI64ToI64SetService_addItem_result__isset __isset;

  void __set_success(const bool val);

  bool operator == (const TI64ToI64SetService_addItem_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const TI64ToI64SetService_addItem_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TI64ToI64SetService_addItem_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TI64ToI64SetService_addItem_presult__isset {
  _TI64ToI64SetService_addItem_presult__isset() : success(false) {}
  bool success :1;
} _TI64ToI64SetService_addItem_presult__isset;

class TI64ToI64SetService_addItem_presult {
 public:


  virtual ~TI64ToI64SetService_addItem_presult() throw();
  bool* success;

  _TI64ToI64SetService_addItem_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _TI64ToI64SetService_addItems_args__isset {
  _TI64ToI64SetService_addItems_args__isset() : key(false), items(false) {}
  bool key :1;
  bool items :1;
} _TI64ToI64SetService_addItems_args__isset;

class TI64ToI64SetService_addItems_args {
 public:

  TI64ToI64SetService_addItems_args(const TI64ToI64SetService_addItems_args&);
  TI64ToI64SetService_addItems_args& operator=(const TI64ToI64SetService_addItems_args&);
  TI64ToI64SetService_addItems_args() : key(0) {
  }

  virtual ~TI64ToI64SetService_addItems_args() throw();
   ::OpenStars::Core::I64ToI64Set::Data::TKey key;
  std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem>  items;

  _TI64ToI64SetService_addItems_args__isset __isset;

  void __set_key(const  ::OpenStars::Core::I64ToI64Set::Data::TKey val);

  void __set_items(const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> & val);

  bool operator == (const TI64ToI64SetService_addItems_args & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    if (!(items == rhs.items))
      return false;
    return true;
  }
  bool operator != (const TI64ToI64SetService_addItems_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TI64ToI64SetService_addItems_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class TI64ToI64SetService_addItems_pargs {
 public:


  virtual ~TI64ToI64SetService_addItems_pargs() throw();
  const  ::OpenStars::Core::I64ToI64Set::Data::TKey* key;
  const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> * items;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TI64ToI64SetService_addItems_result__isset {
  _TI64ToI64SetService_addItems_result__isset() : success(false) {}
  bool success :1;
} _TI64ToI64SetService_addItems_result__isset;

class TI64ToI64SetService_addItems_result {
 public:

  TI64ToI64SetService_addItems_result(const TI64ToI64SetService_addItems_result&);
  TI64ToI64SetService_addItems_result& operator=(const TI64ToI64SetService_addItems_result&);
  TI64ToI64SetService_addItems_result() : success(0) {
  }

  virtual ~TI64ToI64SetService_addItems_result() throw();
  bool success;

  _TI64ToI64SetService_addItems_result__isset __isset;

  void __set_success(const bool val);

  bool operator == (const TI64ToI64SetService_addItems_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const TI64ToI64SetService_addItems_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TI64ToI64SetService_addItems_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TI64ToI64SetService_addItems_presult__isset {
  _TI64ToI64SetService_addItems_presult__isset() : success(false) {}
  bool success :1;
} _TI64ToI64SetService_addItems_presult__isset;

class TI64ToI64SetService_addItems_presult {
 public:


  virtual ~TI64ToI64SetService_addItems_presult() throw();
  bool* success;

  _TI64ToI64SetService_addItems_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _TI64ToI64SetService_removeItem_args__isset {
  _TI64ToI64SetService_removeItem_args__isset() : key(false), item(false) {}
  bool key :1;
  bool item :1;
} _TI64ToI64SetService_removeItem_args__isset;

class TI64ToI64SetService_removeItem_args {
 public:

  TI64ToI64SetService_removeItem_args(const TI64ToI64SetService_removeItem_args&);
  TI64ToI64SetService_removeItem_args& operator=(const TI64ToI64SetService_removeItem_args&);
  TI64ToI64SetService_removeItem_args() : key(0), item(0) {
  }

  virtual ~TI64ToI64SetService_removeItem_args() throw();
   ::OpenStars::Core::I64ToI64Set::Data::TKey key;
   ::OpenStars::Core::I64ToI64Set::Data::TItem item;

  _TI64ToI64SetService_removeItem_args__isset __isset;

  void __set_key(const  ::OpenStars::Core::I64ToI64Set::Data::TKey val);

  void __set_item(const  ::OpenStars::Core::I64ToI64Set::Data::TItem val);

  bool operator == (const TI64ToI64SetService_removeItem_args & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    if (!(item == rhs.item))
      return false;
    return true;
  }
  bool operator != (const TI64ToI64SetService_removeItem_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TI64ToI64SetService_removeItem_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class TI64ToI64SetService_removeItem_pargs {
 public:


  virtual ~TI64ToI64SetService_removeItem_pargs() throw();
  const  ::OpenStars::Core::I64ToI64Set::Data::TKey* key;
  const  ::OpenStars::Core::I64ToI64Set::Data::TItem* item;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TI64ToI64SetService_removeItem_result__isset {
  _TI64ToI64SetService_removeItem_result__isset() : success(false) {}
  bool success :1;
} _TI64ToI64SetService_removeItem_result__isset;

class TI64ToI64SetService_removeItem_result {
 public:

  TI64ToI64SetService_removeItem_result(const TI64ToI64SetService_removeItem_result&);
  TI64ToI64SetService_removeItem_result& operator=(const TI64ToI64SetService_removeItem_result&);
  TI64ToI64SetService_removeItem_result() : success(0) {
  }

  virtual ~TI64ToI64SetService_removeItem_result() throw();
  bool success;

  _TI64ToI64SetService_removeItem_result__isset __isset;

  void __set_success(const bool val);

  bool operator == (const TI64ToI64SetService_removeItem_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const TI64ToI64SetService_removeItem_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TI64ToI64SetService_removeItem_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TI64ToI64SetService_removeItem_presult__isset {
  _TI64ToI64SetService_removeItem_presult__isset() : success(false) {}
  bool success :1;
} _TI64ToI64SetService_removeItem_presult__isset;

class TI64ToI64SetService_removeItem_presult {
 public:


  virtual ~TI64ToI64SetService_removeItem_presult() throw();
  bool* success;

  _TI64ToI64SetService_removeItem_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _TI64ToI64SetService_removeItems_args__isset {
  _TI64ToI64SetService_removeItems_args__isset() : key(false), items(false) {}
  bool key :1;
  bool items :1;
} _TI64ToI64SetService_removeItems_args__isset;

class TI64ToI64SetService_removeItems_args {
 public:

  TI64ToI64SetService_removeItems_args(const TI64ToI64SetService_removeItems_args&);
  TI64ToI64SetService_removeItems_args& operator=(const TI64ToI64SetService_removeItems_args&);
  TI64ToI64SetService_removeItems_args() : key(0) {
  }

  virtual ~TI64ToI64SetService_removeItems_args() throw();
   ::OpenStars::Core::I64ToI64Set::Data::TKey key;
  std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem>  items;

  _TI64ToI64SetService_removeItems_args__isset __isset;

  void __set_key(const  ::OpenStars::Core::I64ToI64Set::Data::TKey val);

  void __set_items(const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> & val);

  bool operator == (const TI64ToI64SetService_removeItems_args & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    if (!(items == rhs.items))
      return false;
    return true;
  }
  bool operator != (const TI64ToI64SetService_removeItems_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TI64ToI64SetService_removeItems_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class TI64ToI64SetService_removeItems_pargs {
 public:


  virtual ~TI64ToI64SetService_removeItems_pargs() throw();
  const  ::OpenStars::Core::I64ToI64Set::Data::TKey* key;
  const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> * items;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TI64ToI64SetService_removeItems_result__isset {
  _TI64ToI64SetService_removeItems_result__isset() : success(false) {}
  bool success :1;
} _TI64ToI64SetService_removeItems_result__isset;

class TI64ToI64SetService_removeItems_result {
 public:

  TI64ToI64SetService_removeItems_result(const TI64ToI64SetService_removeItems_result&);
  TI64ToI64SetService_removeItems_result& operator=(const TI64ToI64SetService_removeItems_result&);
  TI64ToI64SetService_removeItems_result() : success(0) {
  }

  virtual ~TI64ToI64SetService_removeItems_result() throw();
  bool success;

  _TI64ToI64SetService_removeItems_result__isset __isset;

  void __set_success(const bool val);

  bool operator == (const TI64ToI64SetService_removeItems_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const TI64ToI64SetService_removeItems_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TI64ToI64SetService_removeItems_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TI64ToI64SetService_removeItems_presult__isset {
  _TI64ToI64SetService_removeItems_presult__isset() : success(false) {}
  bool success :1;
} _TI64ToI64SetService_removeItems_presult__isset;

class TI64ToI64SetService_removeItems_presult {
 public:


  virtual ~TI64ToI64SetService_removeItems_presult() throw();
  bool* success;

  _TI64ToI64SetService_removeItems_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class TI64ToI64SetServiceClient : virtual public TI64ToI64SetServiceIf, public TI64ToI64SetServiceRClient {
 public:
  TI64ToI64SetServiceClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    TI64ToI64SetServiceRClient(prot, prot) {}
  TI64ToI64SetServiceClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :    TI64ToI64SetServiceRClient(iprot, oprot) {}
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  bool setItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> & items);
  void send_setItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> & items);
  bool recv_setItems();
  bool clearItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key);
  void send_clearItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key);
  bool recv_clearItems();
  bool addItem(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const  ::OpenStars::Core::I64ToI64Set::Data::TItem item);
  void send_addItem(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const  ::OpenStars::Core::I64ToI64Set::Data::TItem item);
  bool recv_addItem();
  bool addItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> & items);
  void send_addItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> & items);
  bool recv_addItems();
  bool removeItem(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const  ::OpenStars::Core::I64ToI64Set::Data::TItem item);
  void send_removeItem(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const  ::OpenStars::Core::I64ToI64Set::Data::TItem item);
  bool recv_removeItem();
  bool removeItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> & items);
  void send_removeItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> & items);
  bool recv_removeItems();
};

class TI64ToI64SetServiceProcessor : public TI64ToI64SetServiceRProcessor {
 protected:
  ::apache::thrift::stdcxx::shared_ptr<TI64ToI64SetServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (TI64ToI64SetServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_setItems(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_clearItems(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_addItem(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_addItems(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_removeItem(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_removeItems(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  TI64ToI64SetServiceProcessor(::apache::thrift::stdcxx::shared_ptr<TI64ToI64SetServiceIf> iface) :
    TI64ToI64SetServiceRProcessor(iface),
    iface_(iface) {
    processMap_["setItems"] = &TI64ToI64SetServiceProcessor::process_setItems;
    processMap_["clearItems"] = &TI64ToI64SetServiceProcessor::process_clearItems;
    processMap_["addItem"] = &TI64ToI64SetServiceProcessor::process_addItem;
    processMap_["addItems"] = &TI64ToI64SetServiceProcessor::process_addItems;
    processMap_["removeItem"] = &TI64ToI64SetServiceProcessor::process_removeItem;
    processMap_["removeItems"] = &TI64ToI64SetServiceProcessor::process_removeItems;
  }

  virtual ~TI64ToI64SetServiceProcessor() {}
};

class TI64ToI64SetServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  TI64ToI64SetServiceProcessorFactory(const ::apache::thrift::stdcxx::shared_ptr< TI64ToI64SetServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::apache::thrift::stdcxx::shared_ptr< TI64ToI64SetServiceIfFactory > handlerFactory_;
};

class TI64ToI64SetServiceMultiface : virtual public TI64ToI64SetServiceIf, public TI64ToI64SetServiceRMultiface {
 public:
  TI64ToI64SetServiceMultiface(std::vector<apache::thrift::stdcxx::shared_ptr<TI64ToI64SetServiceIf> >& ifaces) : ifaces_(ifaces) {
    std::vector<apache::thrift::stdcxx::shared_ptr<TI64ToI64SetServiceIf> >::iterator iter;
    for (iter = ifaces.begin(); iter != ifaces.end(); ++iter) {
      TI64ToI64SetServiceRMultiface::add(*iter);
    }
  }
  virtual ~TI64ToI64SetServiceMultiface() {}
 protected:
  std::vector<apache::thrift::stdcxx::shared_ptr<TI64ToI64SetServiceIf> > ifaces_;
  TI64ToI64SetServiceMultiface() {}
  void add(::apache::thrift::stdcxx::shared_ptr<TI64ToI64SetServiceIf> iface) {
    TI64ToI64SetServiceRMultiface::add(iface);
    ifaces_.push_back(iface);
  }
 public:
  bool setItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> & items) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setItems(key, items);
    }
    return ifaces_[i]->setItems(key, items);
  }

  bool clearItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->clearItems(key);
    }
    return ifaces_[i]->clearItems(key);
  }

  bool addItem(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const  ::OpenStars::Core::I64ToI64Set::Data::TItem item) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->addItem(key, item);
    }
    return ifaces_[i]->addItem(key, item);
  }

  bool addItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> & items) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->addItems(key, items);
    }
    return ifaces_[i]->addItems(key, items);
  }

  bool removeItem(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const  ::OpenStars::Core::I64ToI64Set::Data::TItem item) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->removeItem(key, item);
    }
    return ifaces_[i]->removeItem(key, item);
  }

  bool removeItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> & items) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->removeItems(key, items);
    }
    return ifaces_[i]->removeItems(key, items);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class TI64ToI64SetServiceConcurrentClient : virtual public TI64ToI64SetServiceIf, public TI64ToI64SetServiceRConcurrentClient {
 public:
  TI64ToI64SetServiceConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    TI64ToI64SetServiceRConcurrentClient(prot, prot) {}
  TI64ToI64SetServiceConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :    TI64ToI64SetServiceRConcurrentClient(iprot, oprot) {}
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  bool setItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> & items);
  int32_t send_setItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> & items);
  bool recv_setItems(const int32_t seqid);
  bool clearItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key);
  int32_t send_clearItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key);
  bool recv_clearItems(const int32_t seqid);
  bool addItem(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const  ::OpenStars::Core::I64ToI64Set::Data::TItem item);
  int32_t send_addItem(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const  ::OpenStars::Core::I64ToI64Set::Data::TItem item);
  bool recv_addItem(const int32_t seqid);
  bool addItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> & items);
  int32_t send_addItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> & items);
  bool recv_addItems(const int32_t seqid);
  bool removeItem(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const  ::OpenStars::Core::I64ToI64Set::Data::TItem item);
  int32_t send_removeItem(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const  ::OpenStars::Core::I64ToI64Set::Data::TItem item);
  bool recv_removeItem(const int32_t seqid);
  bool removeItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> & items);
  int32_t send_removeItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> & items);
  bool recv_removeItems(const int32_t seqid);
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif

}}} // namespace

#endif