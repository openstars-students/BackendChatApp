package main
import (
	"../../thrift/gen-go/OpenStars/Platform/ListMemberService" //Todo: Fix this
	"../transports"  //Todo: Fix this
	"fmt"
	"context"
)

func main(){
	aClient := transports.GetTListMemberServiceCompactClient("127.0.0.1", "8883") //Todo: Check port and protocol
	defer aClient.BackToPool();
	fmt.Println("Client: ", aClient);

	res, _ := aClient.Client.(*ListMemberService.TListMemberServiceClient).GetData(context.Background(), (ListMemberService.TKey)(10) )
	fmt.Println("get result: ",res)

	aClient.Client.(*ListMemberService.TListMemberServiceClient).PutData(context.Background(),
			 (ListMemberService.TKey)(10), &ListMemberService.TValue{} );//Todo: fill structure here

	res, _ = aClient.Client.(*ListMemberService.TListMemberServiceClient).GetData(context.Background(), (ListMemberService.TKey)(10) )
	fmt.Println("get after put :", res)

}