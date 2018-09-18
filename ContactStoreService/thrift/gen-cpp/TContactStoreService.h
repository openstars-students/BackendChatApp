/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef TContactStoreService_H
#define TContactStoreService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "contactstore_types.h"
#include "TDataService.h"

namespace OpenStars { namespace Platform { namespace ContactStore {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class TContactStoreServiceIf : virtual public TDataServiceIf {
 public:
  virtual ~TContactStoreServiceIf() {}
};

class TContactStoreServiceIfFactory : virtual public TDataServiceIfFactory {
 public:
  typedef TContactStoreServiceIf Handler;

  virtual ~TContactStoreServiceIfFactory() {}

  virtual TContactStoreServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(TDataServiceIf* /* handler */) = 0;
};

class TContactStoreServiceIfSingletonFactory : virtual public TContactStoreServiceIfFactory {
 public:
  TContactStoreServiceIfSingletonFactory(const ::apache::thrift::stdcxx::shared_ptr<TContactStoreServiceIf>& iface) : iface_(iface) {}
  virtual ~TContactStoreServiceIfSingletonFactory() {}

  virtual TContactStoreServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(TDataServiceIf* /* handler */) {}

 protected:
  ::apache::thrift::stdcxx::shared_ptr<TContactStoreServiceIf> iface_;
};

class TContactStoreServiceNull : virtual public TContactStoreServiceIf , virtual public TDataServiceNull {
 public:
  virtual ~TContactStoreServiceNull() {}
};

class TContactStoreServiceClient : virtual public TContactStoreServiceIf, public TDataServiceClient {
 public:
  TContactStoreServiceClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    TDataServiceClient(prot, prot) {}
  TContactStoreServiceClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :    TDataServiceClient(iprot, oprot) {}
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
};

class TContactStoreServiceProcessor : public TDataServiceProcessor {
 protected:
  ::apache::thrift::stdcxx::shared_ptr<TContactStoreServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (TContactStoreServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
 public:
  TContactStoreServiceProcessor(::apache::thrift::stdcxx::shared_ptr<TContactStoreServiceIf> iface) :
    TDataServiceProcessor(iface),
    iface_(iface) {
  }

  virtual ~TContactStoreServiceProcessor() {}
};

class TContactStoreServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  TContactStoreServiceProcessorFactory(const ::apache::thrift::stdcxx::shared_ptr< TContactStoreServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::apache::thrift::stdcxx::shared_ptr< TContactStoreServiceIfFactory > handlerFactory_;
};

class TContactStoreServiceMultiface : virtual public TContactStoreServiceIf, public TDataServiceMultiface {
 public:
  TContactStoreServiceMultiface(std::vector<apache::thrift::stdcxx::shared_ptr<TContactStoreServiceIf> >& ifaces) : ifaces_(ifaces) {
    std::vector<apache::thrift::stdcxx::shared_ptr<TContactStoreServiceIf> >::iterator iter;
    for (iter = ifaces.begin(); iter != ifaces.end(); ++iter) {
      TDataServiceMultiface::add(*iter);
    }
  }
  virtual ~TContactStoreServiceMultiface() {}
 protected:
  std::vector<apache::thrift::stdcxx::shared_ptr<TContactStoreServiceIf> > ifaces_;
  TContactStoreServiceMultiface() {}
  void add(::apache::thrift::stdcxx::shared_ptr<TContactStoreServiceIf> iface) {
    TDataServiceMultiface::add(iface);
    ifaces_.push_back(iface);
  }
 public:
};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class TContactStoreServiceConcurrentClient : virtual public TContactStoreServiceIf, public TDataServiceConcurrentClient {
 public:
  TContactStoreServiceConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    TDataServiceConcurrentClient(prot, prot) {}
  TContactStoreServiceConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :    TDataServiceConcurrentClient(iprot, oprot) {}
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif

}}} // namespace

#endif