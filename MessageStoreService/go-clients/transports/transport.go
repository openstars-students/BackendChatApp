package transports

import (
	// "github.com/OpenStars/backendclients/go//gen-go/OpenStars/Platform/MessageStore" //Todo: Fix this
	"../../thrift/gen-go/OpenStars/Platform/MessageStore" //Todo: Fix this
	"git.apache.org/thrift.git/lib/go/thrift"
	"fmt"
	"github.com/OpenStars/thriftpool"	
	)


var (
	mTMessageStoreServiceBinaryMapPool = thriftpool.NewMapPool(1000, 3600, 3600, 
		thriftpool.GetThriftClientCreatorFunc( func( c thrift.TClient ) (interface{}) { return  (MessageStore.NewTMessageStoreServiceClient(c)) }),
		thriftpool.DefaultClose)

	mTMessageStoreServiceCommpactMapPool = thriftpool.NewMapPool(1000, 3600, 3600, 
		thriftpool.GetThriftClientCreatorFuncCompactProtocol( func(c thrift.TClient) (interface{}) { return  (MessageStore.NewTMessageStoreServiceClient(c)) }),
		thriftpool.DefaultClose)		
	
	)

 


func init(){
	fmt.Println("init thrift TMessageStoreService client ");
}

//GetTMessageStoreServiceBinaryClient client by host:port
func GetTMessageStoreServiceBinaryClient(aHost, aPort string) *thriftpool.ThriftSocketClient{
	client, _ := mTMessageStoreServiceBinaryMapPool.Get(aHost, aPort).Get()
	return client;
}

//GetTMessageStoreServiceCompactClient get compact client by host:port
func GetTMessageStoreServiceCompactClient(aHost, aPort string) *thriftpool.ThriftSocketClient{
	client, _ := mTMessageStoreServiceCommpactMapPool.Get(aHost, aPort).Get()
	return client;
}