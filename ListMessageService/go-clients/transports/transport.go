package transports

import (
	// "github.com/OpenStars/backendclients/go//gen-go/OpenStars/Platform/ListMessageService" //Todo: Fix this
	"../../thrift/gen-go/OpenStars/Platform/ListMessageService" //Todo: Fix this
	"git.apache.org/thrift.git/lib/go/thrift"
	"fmt"
	"github.com/OpenStars/thriftpool"	
	)


var (
	mTListMessageServiceBinaryMapPool = thriftpool.NewMapPool(1000, 3600, 3600, 
		thriftpool.GetThriftClientCreatorFunc( func( c thrift.TClient ) (interface{}) { return  (ListMessageService.NewTListMessageServiceClient(c)) }),
		thriftpool.DefaultClose)

	mTListMessageServiceCommpactMapPool = thriftpool.NewMapPool(1000, 3600, 3600, 
		thriftpool.GetThriftClientCreatorFuncCompactProtocol( func(c thrift.TClient) (interface{}) { return  (ListMessageService.NewTListMessageServiceClient(c)) }),
		thriftpool.DefaultClose)		
	
	)

 


func init(){
	fmt.Println("init thrift TListMessageService client ");
}

//GetTListMessageServiceBinaryClient client by host:port
func GetTListMessageServiceBinaryClient(aHost, aPort string) *thriftpool.ThriftSocketClient{
	client, _ := mTListMessageServiceBinaryMapPool.Get(aHost, aPort).Get()
	return client;
}

//GetTListMessageServiceCompactClient get compact client by host:port
func GetTListMessageServiceCompactClient(aHost, aPort string) *thriftpool.ThriftSocketClient{
	client, _ := mTListMessageServiceCommpactMapPool.Get(aHost, aPort).Get()
	return client;
}