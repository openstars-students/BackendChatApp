package transports

import (
	// "github.com/OpenStars/backendclients/go//gen-go/OpenStars/Platform/UserStore" //Todo: Fix this
	"../../thrift/gen-go/OpenStars/Platform/UserStore" //Todo: Fix this
	"git.apache.org/thrift.git/lib/go/thrift"
	"fmt"
	"github.com/OpenStars/thriftpool"	
	)


var (
	mTUserStoreServiceBinaryMapPool = thriftpool.NewMapPool(1000, 3600, 3600, 
		thriftpool.GetThriftClientCreatorFunc( func( c thrift.TClient ) (interface{}) { return  (UserStore.NewTUserStoreServiceClient(c)) }),
		thriftpool.DefaultClose)

	mTUserStoreServiceCommpactMapPool = thriftpool.NewMapPool(1000, 3600, 3600, 
		thriftpool.GetThriftClientCreatorFuncCompactProtocol( func(c thrift.TClient) (interface{}) { return  (UserStore.NewTUserStoreServiceClient(c)) }),
		thriftpool.DefaultClose)		
	
	)

 


func init(){
	fmt.Println("init thrift TUserStoreService client ");
}

//GetTUserStoreServiceBinaryClient client by host:port
func GetTUserStoreServiceBinaryClient(aHost, aPort string) *thriftpool.ThriftSocketClient{
	client, _ := mTUserStoreServiceBinaryMapPool.Get(aHost, aPort).Get()
	return client;
}

//GetTUserStoreServiceCompactClient get compact client by host:port
func GetTUserStoreServiceCompactClient(aHost, aPort string) *thriftpool.ThriftSocketClient{
	client, _ := mTUserStoreServiceCommpactMapPool.Get(aHost, aPort).Get()
	return client;
}