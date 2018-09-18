package main
import (
	"../../thrift/gen-go/OpenStars/Platform/UserConversationService" //Todo: Fix this
	"../transports"  //Todo: Fix this
	"fmt"
	"context"
)

func main(){
	aClient := transports.GetTUserConversationServiceCompactClient("127.0.0.1", "8823") //Todo: Check port and protocol
	defer aClient.BackToPool();
	fmt.Println("Client: ", aClient);

	res, _ := aClient.Client.(*UserConversationService.TUserConversationServiceClient).GetData(context.Background(), (UserConversationService.TKey)(10) )
	fmt.Println("get result: ",res)

	//aClient.Client.(*UserConversationService.TUserConversationServiceClient).PutData(context.Background(),
	//		 (UserConversationService.TKey)(10), &UserConversationService.TValue{(UserConversationService.TKey)(10),nil} );//Todo: fill structure here
	res2,_:= aClient.Client.(*UserConversationService.TUserConversationServiceClient).RemoveConversation(context.Background(),
	(UserConversationService.TKey)(10), 1 );//Todo: fill structure here
	fmt.Println("get result: ",res2)

	res, _ = aClient.Client.(*UserConversationService.TUserConversationServiceClient).GetData(context.Background(), (UserConversationService.TKey)(10) )
	fmt.Println("get after put :", res)

}