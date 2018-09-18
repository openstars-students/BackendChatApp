package transports

import (
	// "github.com/OpenStars/backendclients/go//gen-go/OpenStars/Platform/ConversationStore" //Todo: Fix this
	"../../thrift/gen-go/OpenStars/Platform/ConversationStore" //Todo: Fix this
	"git.apache.org/thrift.git/lib/go/thrift"
	"fmt"
	"github.com/OpenStars/thriftpool"	
	)


var (
	mTConversationStoreServiceBinaryMapPool = thriftpool.NewMapPool(1000, 3600, 3600, 
		thriftpool.GetThriftClientCreatorFunc( func( c thrift.TClient ) (interface{}) { return  (ConversationStore.NewTConversationStoreServiceClient(c)) }),
		thriftpool.DefaultClose)

	mTConversationStoreServiceCommpactMapPool = thriftpool.NewMapPool(1000, 3600, 3600, 
		thriftpool.GetThriftClientCreatorFuncCompactProtocol( func(c thrift.TClient) (interface{}) { return  (ConversationStore.NewTConversationStoreServiceClient(c)) }),
		thriftpool.DefaultClose)		
	
	)

 


func init(){
	fmt.Println("init thrift TConversationStoreService client ");
}

//GetTConversationStoreServiceBinaryClient client by host:port
func GetTConversationStoreServiceBinaryClient(aHost, aPort string) *thriftpool.ThriftSocketClient{
	client, _ := mTConversationStoreServiceBinaryMapPool.Get(aHost, aPort).Get()
	return client;
}

//GetTConversationStoreServiceCompactClient get compact client by host:port
func GetTConversationStoreServiceCompactClient(aHost, aPort string) *thriftpool.ThriftSocketClient{
	client, _ := mTConversationStoreServiceCommpactMapPool.Get(aHost, aPort).Get()
	return client;
}