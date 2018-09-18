package main
import (
	"../../thrift/gen-go/OpenStars/Platform/ContactStore" //Todo: Fix this
	"../transports"  //Todo: Fix this
	"fmt"
	"context"
)

func main(){
	aClient := transports.GetTContactStoreServiceCompactClient("127.0.0.1", "8813") //Todo: Check port and protocol
	defer aClient.BackToPool();
	fmt.Println("Client: ", aClient);

	res, _ := aClient.Client.(*ContactStore.TContactStoreServiceClient).GetData(context.Background(), (ContactStore.TKey)(1) )
	fmt.Println("get result: ",res)

	//aClient.Client.(*ContactStore.TContactStoreServiceClient).PutData(context.Background(),
	//		 (ContactStore.TKey)(1), &ContactStore.TValue{(ContactStore.TKey)(1),nil} );//Todo: fill structure here
	res2,_ := aClient.Client.(*ContactStore.TContactStoreServiceClient).UnFriend(context.Background(),
			 (ContactStore.TKey)(1), 3 );//Todo: fill structure here
	 fmt.Println("get res2 :", res2)


	res, _ = aClient.Client.(*ContactStore.TContactStoreServiceClient).GetData(context.Background(), (ContactStore.TKey)(1) )
	fmt.Println("get after put :", res)

}