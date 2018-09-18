package main

import (
	"context"
	"fmt"

	"../../thrift/gen-go/OpenStars/Platform/ConversationStore" //Todo: Fix this
	"../transports"                                            //Todo: Fix this
)

func main() {
	aClient := transports.GetTConversationStoreServiceCompactClient("127.0.0.1", "8833") //Todo: Check port and protocol
	defer aClient.BackToPool()
	fmt.Println("Client: ", aClient)

	res, _ := aClient.Client.(*ConversationStore.TConversationStoreServiceClient).GetData(context.Background(), (ConversationStore.TKey)(10))
	fmt.Println("get result: ", res)

	aClient.Client.(*ConversationStore.TConversationStoreServiceClient).PutData(context.Background(),
		(ConversationStore.TKey)(1), &ConversationStore.TConversationInfo{(ConversationStore.TKey)(1), "bụng mỡ 1", 11, 11236458, 2}) //Todo: fill structure here
	aClient.Client.(*ConversationStore.TConversationStoreServiceClient).PutData(context.Background(),
		(ConversationStore.TKey)(2), &ConversationStore.TConversationInfo{(ConversationStore.TKey)(2), "bụng mỡ 2", 11, 11236458, 2}) //Todo: fill structure here
	aClient.Client.(*ConversationStore.TConversationStoreServiceClient).PutData(context.Background(),
		(ConversationStore.TKey)(3), &ConversationStore.TConversationInfo{(ConversationStore.TKey)(3), "bụng mỡ 3", 11, 11236458, 2}) //Todo: fill structure here
	a := make([]int64, 4)
	a[1] = 1
	a[2] = 2
	a[0] = 10
	a[3] = 3
	res2, _ := aClient.Client.(*ConversationStore.TConversationStoreServiceClient).GetListData(context.Background(), a) //Todo: fill structure here

	//res, _ = aClient.Client.(*ConversationStore.TConversationStoreServiceClient).GetData(context.Background(), (ConversationStore.TKey)(10))
	fmt.Println("get after put :", res2)

}
