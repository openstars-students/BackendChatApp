// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "TI64ToI64SetService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::OpenStars::Core::I64ToI64Set;

class TI64ToI64SetServiceHandler : virtual public TI64ToI64SetServiceIf {
 public:
  TI64ToI64SetServiceHandler() {
    // Your initialization goes here
  }

  bool setItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> & items) {
    // Your implementation goes here
    printf("setItems\n");
  }

  bool clearItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key) {
    // Your implementation goes here
    printf("clearItems\n");
  }

  bool addItem(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const  ::OpenStars::Core::I64ToI64Set::Data::TItem item) {
    // Your implementation goes here
    printf("addItem\n");
  }

  bool addItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> & items) {
    // Your implementation goes here
    printf("addItems\n");
  }

  bool removeItem(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const  ::OpenStars::Core::I64ToI64Set::Data::TItem item) {
    // Your implementation goes here
    printf("removeItem\n");
  }

  bool removeItems(const  ::OpenStars::Core::I64ToI64Set::Data::TKey key, const std::vector< ::OpenStars::Core::I64ToI64Set::Data::TItem> & items) {
    // Your implementation goes here
    printf("removeItems\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::apache::thrift::stdcxx::shared_ptr<TI64ToI64SetServiceHandler> handler(new TI64ToI64SetServiceHandler());
  ::apache::thrift::stdcxx::shared_ptr<TProcessor> processor(new TI64ToI64SetServiceProcessor(handler));
  ::apache::thrift::stdcxx::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::apache::thrift::stdcxx::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::apache::thrift::stdcxx::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}
