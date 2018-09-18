package main
import (
	"../../thrift/gen-go/OpenStars/Platform/ListMessageService" //Todo: Fix this
	"../transports"  //Todo: Fix this
	"fmt"
	"context"
)

func main(){
	aClient := transports.GetTListMessageServiceCompactClient("127.0.0.1", "8883") //Todo: Check port and protocol
	defer aClient.BackToPool();
	fmt.Println("Client: ", aClient);

	res, _ := aClient.Client.(*ListMessageService.TListMessageServiceClient).GetData(context.Background(), (ListMessageService.TKey)(10) )
	fmt.Println("get result: ",res)

	aClient.Client.(*ListMessageService.TListMessageServiceClient).PutData(context.Background(),
			 (ListMessageService.TKey)(10), &ListMessageService.TValue{} );//Todo: fill structure here

	res, _ = aClient.Client.(*ListMessageService.TListMessageServiceClient).GetData(context.Background(), (ListMessageService.TKey)(10) )
	fmt.Println("get after put :", res)

}