package main

import (
	"context"
	"fmt"

	"../../thrift/gen-go/OpenStars/Platform/ListMessageService" //Todo: Fix this
	"../transports"                                             //Todo: Fix this
)

func main() {
	aClient := transports.GetTListMessageServiceCompactClient("127.0.0.1", "8843") //Todo: Check port and protocol
	defer aClient.BackToPool()
	fmt.Println("Client: ", aClient)

	res, _ := aClient.Client.(*ListMessageService.TListMessageServiceClient).GetData(context.Background(), (ListMessageService.TKey)(10))
	fmt.Println("get result: ", res)

	//aClient.Client.(*ListMessageService.TListMessageServiceClient).PutData(context.Background(),
	//	(ListMessageService.TKey)(10), &ListMessageService.TValue{(ListMessageService.TKey)(10), []int64{83}}) //Todo: fill structure here
	aClient.Client.(*ListMessageService.TListMessageServiceClient).AddMessage(context.Background(),
		(ListMessageService.TKey)(10), 10) //Todo: fill structure here

	res3, _ := aClient.Client.(*ListMessageService.TListMessageServiceClient).RemoveMessage(context.Background(),
		(ListMessageService.TKey)(10), 83) //Todo: fill structure here
	fmt.Println("res: ", res3)

	res, _ = aClient.Client.(*ListMessageService.TListMessageServiceClient).GetData(context.Background(), (ListMessageService.TKey)(10))
	fmt.Println("get after put :", res)

}
