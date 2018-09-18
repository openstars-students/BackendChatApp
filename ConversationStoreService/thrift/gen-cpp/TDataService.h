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
#include "conversationstore_types.h"

namespace OpenStars { namespace Platform { namespace ConversationStore {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class TDataServiceIf {
 public:
  virtual ~TDataServiceIf() {}
  virtual void getData(TDataResult& _return, const TKey key) = 0;
  virtual TErrorCode::type putData(const TKey key, const TConversationInfo& data) = 0;
  virtual void getListData(TListDataResult& _return, const std::vector<int64_t> & keys) = 0;
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
  TErrorCode::type putData(const TKey /* key */, const TConversationInfo& /* data */) {
    TErrorCode::type _return = (TErrorCode::type)0;
    return _return;
  }
  void getListData(TListDataResult& /* _return */, const std::vector<int64_t> & /* keys */) {
    return;
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
  TConversationInfo data;

  _TDataService_putData_args__isset __isset;

  void __set_key(const TKey val);

  void __set_data(const TConversationInfo& val);

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
  const TConversationInfo* data;

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

typedef struct _TDataService_getListData_args__isset {
  _TDataService_getListData_args__isset() : keys(false) {}
  bool keys :1;
} _TDataService_getListData_args__isset;

class TDataService_getListData_args {
 public:

  TDataService_getListData_args(const TDataService_getListData_args&);
  TDataService_getListData_args& operator=(const TDataService_getListData_args&);
  TDataService_getListData_args() {
  }

  virtual ~TDataService_getListData_args() throw();
  std::vector<int64_t>  keys;

  _TDataService_getListData_args__isset __isset;

  void __set_keys(const std::vector<int64_t> & val);

  bool operator == (const TDataService_getListData_args & rhs) const
  {
    if (!(keys == rhs.keys))
      return false;
    return true;
  }
  bool operator != (const TDataService_getListData_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDataService_getListData_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class TDataService_getListData_pargs {
 public:


  virtual ~TDataService_getListData_pargs() throw();
  const std::vector<int64_t> * keys;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TDataService_getListData_result__isset {
  _TDataService_getListData_result__isset() : success(false) {}
  bool success :1;
} _TDataService_getListData_result__isset;

class TDataService_getListData_result {
 public:

  TDataService_getListData_result(const TDataService_getListData_result&);
  TDataService_getListData_result& operator=(const TDataService_getListData_result&);
  TDataService_getListData_result() {
  }

  virtual ~TDataService_getListData_result() throw();
  TListDataResult success;

  _TDataService_getListData_result__isset __isset;

  void __set_success(const TListDataResult& val);

  bool operator == (const TDataService_getListData_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const TDataService_getListData_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDataService_getListData_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TDataService_getListData_presult__isset {
  _TDataService_getListData_presult__isset() : success(false) {}
  bool success :1;
} _TDataService_getListData_presult__isset;

class TDataService_getListData_presult {
 public:


  virtual ~TDataService_getListData_presult() throw();
  TListDataResult* success;

  _TDataService_getListData_presult__isset __isset;

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
  TErrorCode::type putData(const TKey key, const TConversationInfo& data);
  void send_putData(const TKey key, const TConversationInfo& data);
  TErrorCode::type recv_putData();
  void getListData(TListDataResult& _return, const std::vector<int64_t> & keys);
  void send_getListData(const std::vector<int64_t> & keys);
  void recv_getListData(TListDataResult& _return);
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
  void process_putData(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getListData(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  TDataServiceProcessor(::apache::thrift::stdcxx::shared_ptr<TDataServiceIf> iface) :
    iface_(iface) {
    processMap_["getData"] = &TDataServiceProcessor::process_getData;
    processMap_["putData"] = &TDataServiceProcessor::process_putData;
    processMap_["getListData"] = &TDataServiceProcessor::process_getListData;
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

  TErrorCode::type putData(const TKey key, const TConversationInfo& data) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->putData(key, data);
    }
    return ifaces_[i]->putData(key, data);
  }

  void getListData(TListDataResult& _return, const std::vector<int64_t> & keys) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getListData(_return, keys);
    }
    ifaces_[i]->getListData(_return, keys);
    return;
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
  TErrorCode::type putData(const TKey key, const TConversationInfo& data);
  int32_t send_putData(const TKey key, const TConversationInfo& data);
  TErrorCode::type recv_putData(const int32_t seqid);
  void getListData(TListDataResult& _return, const std::vector<int64_t> & keys);
  int32_t send_getListData(const std::vector<int64_t> & keys);
  void recv_getListData(TListDataResult& _return, const int32_t seqid);
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
