package transports

import (
	// "github.com/OpenStars/backendclients/go//gen-go/OpenStars/Platform/UserConversationService" //Todo: Fix this
	"../../thrift/gen-go/OpenStars/Platform/UserConversationService" //Todo: Fix this
	"git.apache.org/thrift.git/lib/go/thrift"
	"fmt"
	"github.com/OpenStars/thriftpool"	
	)


var (
	mTUserConversationServiceBinaryMapPool = thriftpool.NewMapPool(1000, 3600, 3600, 
		thriftpool.GetThriftClientCreatorFunc( func( c thrift.TClient ) (interface{}) { return  (UserConversationService.NewTUserConversationServiceClient(c)) }),
		thriftpool.DefaultClose)

	mTUserConversationServiceCommpactMapPool = thriftpool.NewMapPool(1000, 3600, 3600, 
		thriftpool.GetThriftClientCreatorFuncCompactProtocol( func(c thrift.TClient) (interface{}) { return  (UserConversationService.NewTUserConversationServiceClient(c)) }),
		thriftpool.DefaultClose)		
	
	)

 


func init(){
	fmt.Println("init thrift TUserConversationService client ");
}

//GetTUserConversationServiceBinaryClient client by host:port
func GetTUserConversationServiceBinaryClient(aHost, aPort string) *thriftpool.ThriftSocketClient{
	client, _ := mTUserConversationServiceBinaryMapPool.Get(aHost, aPort).Get()
	return client;
}

//GetTUserConversationServiceCompactClient get compact client by host:port
func GetTUserConversationServiceCompactClient(aHost, aPort string) *thriftpool.ThriftSocketClient{
	client, _ := mTUserConversationServiceCommpactMapPool.Get(aHost, aPort).Get()
	return client;
}