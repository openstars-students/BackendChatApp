/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef TDataServiceR_H
#define TDataServiceR_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "userstore_types.h"

namespace OpenStars { namespace Platform { namespace UserStore {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class TDataServiceRIf {
 public:
  virtual ~TDataServiceRIf() {}
  virtual void getData(TDataResult& _return, const TKey key) = 0;
};

class TDataServiceRIfFactory {
 public:
  typedef TDataServiceRIf Handler;

  virtual ~TDataServiceRIfFactory() {}

  virtual TDataServiceRIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(TDataServiceRIf* /* handler */) = 0;
};

class TDataServiceRIfSingletonFactory : virtual public TDataServiceRIfFactory {
 public:
  TDataServiceRIfSingletonFactory(const ::apache::thrift::stdcxx::shared_ptr<TDataServiceRIf>& iface) : iface_(iface) {}
  virtual ~TDataServiceRIfSingletonFactory() {}

  virtual TDataServiceRIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(TDataServiceRIf* /* handler */) {}

 protected:
  ::apache::thrift::stdcxx::shared_ptr<TDataServiceRIf> iface_;
};

class TDataServiceRNull : virtual public TDataServiceRIf {
 public:
  virtual ~TDataServiceRNull() {}
  void getData(TDataResult& /* _return */, const TKey /* key */) {
    return;
  }
};

typedef struct _TDataServiceR_getData_args__isset {
  _TDataServiceR_getData_args__isset() : key(false) {}
  bool key :1;
} _TDataServiceR_getData_args__isset;

class TDataServiceR_getData_args {
 public:

  TDataServiceR_getData_args(const TDataServiceR_getData_args&);
  TDataServiceR_getData_args& operator=(const TDataServiceR_getData_args&);
  TDataServiceR_getData_args() : key(0) {
  }

  virtual ~TDataServiceR_getData_args() throw();
  TKey key;

  _TDataServiceR_getData_args__isset __isset;

  void __set_key(const TKey val);

  bool operator == (const TDataServiceR_getData_args & rhs) const
  {
    if (!(key == rhs.key))
      return false;
    return true;
  }
  bool operator != (const TDataServiceR_getData_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDataServiceR_getData_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class TDataServiceR_getData_pargs {
 public:


  virtual ~TDataServiceR_getData_pargs() throw();
  const TKey* key;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TDataServiceR_getData_result__isset {
  _TDataServiceR_getData_result__isset() : success(false) {}
  bool success :1;
} _TDataServiceR_getData_result__isset;

class TDataServiceR_getData_result {
 public:

  TDataServiceR_getData_result(const TDataServiceR_getData_result&);
  TDataServiceR_getData_result& operator=(const TDataServiceR_getData_result&);
  TDataServiceR_getData_result() {
  }

  virtual ~TDataServiceR_getData_result() throw();
  TDataResult success;

  _TDataServiceR_getData_result__isset __isset;

  void __set_success(const TDataResult& val);

  bool operator == (const TDataServiceR_getData_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const TDataServiceR_getData_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TDataServiceR_getData_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _TDataServiceR_getData_presult__isset {
  _TDataServiceR_getData_presult__isset() : success(false) {}
  bool success :1;
} _TDataServiceR_getData_presult__isset;

class TDataServiceR_getData_presult {
 public:


  virtual ~TDataServiceR_getData_presult() throw();
  TDataResult* success;

  _TDataServiceR_getData_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class TDataServiceRClient : virtual public TDataServiceRIf {
 public:
  TDataServiceRClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  TDataServiceRClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
 protected:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class TDataServiceRProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::apache::thrift::stdcxx::shared_ptr<TDataServiceRIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (TDataServiceRProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getData(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  TDataServiceRProcessor(::apache::thrift::stdcxx::shared_ptr<TDataServiceRIf> iface) :
    iface_(iface) {
    processMap_["getData"] = &TDataServiceRProcessor::process_getData;
  }

  virtual ~TDataServiceRProcessor() {}
};

class TDataServiceRProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  TDataServiceRProcessorFactory(const ::apache::thrift::stdcxx::shared_ptr< TDataServiceRIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::apache::thrift::stdcxx::shared_ptr< TDataServiceRIfFactory > handlerFactory_;
};

class TDataServiceRMultiface : virtual public TDataServiceRIf {
 public:
  TDataServiceRMultiface(std::vector<apache::thrift::stdcxx::shared_ptr<TDataServiceRIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~TDataServiceRMultiface() {}
 protected:
  std::vector<apache::thrift::stdcxx::shared_ptr<TDataServiceRIf> > ifaces_;
  TDataServiceRMultiface() {}
  void add(::apache::thrift::stdcxx::shared_ptr<TDataServiceRIf> iface) {
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

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class TDataServiceRConcurrentClient : virtual public TDataServiceRIf {
 public:
  TDataServiceRConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  TDataServiceRConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
