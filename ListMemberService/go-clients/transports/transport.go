package transports

import (
	// "github.com/OpenStars/backendclients/go//gen-go/OpenStars/Platform/ListMemberService" //Todo: Fix this
	"../../thrift/gen-go/OpenStars/Platform/ListMemberService" //Todo: Fix this
	"git.apache.org/thrift.git/lib/go/thrift"
	"fmt"
	"github.com/OpenStars/thriftpool"	
	)


var (
	mTListMemberServiceBinaryMapPool = thriftpool.NewMapPool(1000, 3600, 3600, 
		thriftpool.GetThriftClientCreatorFunc( func( c thrift.TClient ) (interface{}) { return  (ListMemberService.NewTListMemberServiceClient(c)) }),
		thriftpool.DefaultClose)

	mTListMemberServiceCommpactMapPool = thriftpool.NewMapPool(1000, 3600, 3600, 
		thriftpool.GetThriftClientCreatorFuncCompactProtocol( func(c thrift.TClient) (interface{}) { return  (ListMemberService.NewTListMemberServiceClient(c)) }),
		thriftpool.DefaultClose)		
	
	)

 


func init(){
	fmt.Println("init thrift TListMemberService client ");
}

//GetTListMemberServiceBinaryClient client by host:port
func GetTListMemberServiceBinaryClient(aHost, aPort string) *thriftpool.ThriftSocketClient{
	client, _ := mTListMemberServiceBinaryMapPool.Get(aHost, aPort).Get()
	return client;
}

//GetTListMemberServiceCompactClient get compact client by host:port
func GetTListMemberServiceCompactClient(aHost, aPort string) *thriftpool.ThriftSocketClient{
	client, _ := mTListMemberServiceCommpactMapPool.Get(aHost, aPort).Get()
	return client;
}