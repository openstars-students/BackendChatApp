/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "TContactStoreService.h"

namespace OpenStars { namespace Platform { namespace ContactStore {

bool TContactStoreServiceProcessor::dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext) {
  ProcessMap::iterator pfn;
  pfn = processMap_.find(fname);
  if (pfn == processMap_.end()) {
    return TDataServiceProcessor::dispatchCall(iprot, oprot, fname, seqid, callContext);
  }
  (this->*(pfn->second))(seqid, iprot, oprot, callContext);
  return true;
}

::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::TProcessor > TContactStoreServiceProcessorFactory::getProcessor(const ::apache::thrift::TConnectionInfo& connInfo) {
  ::apache::thrift::ReleaseHandler< TContactStoreServiceIfFactory > cleanup(handlerFactory_);
  ::apache::thrift::stdcxx::shared_ptr< TContactStoreServiceIf > handler(handlerFactory_->getHandler(connInfo), cleanup);
  ::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::TProcessor > processor(new TContactStoreServiceProcessor(handler));
  return processor;
}

}}} // namespace

