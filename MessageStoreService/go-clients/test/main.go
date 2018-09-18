package main
import (
	"../../thrift/gen-go/OpenStars/Platform/MessageStore" //Todo: Fix this
	"../transports"  //Todo: Fix this
	"fmt"
	"context"
	"strconv"
)

func main(){
	aClient := transports.GetTMessageStoreServiceCompactClient("127.0.0.1", "8883") //Todo: Check port and protocol
	defer aClient.BackToPool();
	fmt.Println("Client: ", aClient);

	res, _ := aClient.Client.(*MessageStore.TMessageStoreServiceClient).GetData(context.Background(), (MessageStore.TKey)(1) )
	fmt.Println("get result: ",res)
 x := make([]MessageStore.TKey, 10)

 aClient.Client.(*MessageStore.TMessageStoreServiceClient).PutData(context.Background(),
	(MessageStore.TKey)(10), &MessageStore.TMessageInfo{(MessageStore.TKey)(10),"tin nhắ thứ  ","người gửi ",1,1562000000,1 });//Todo: fill structure here
// for i:=1;i<=10;i++{
// 	x[i-1]=(MessageStore.TKey)(i)
// 	re,err:=aClient.Client.(*MessageStore.TMessageStoreServiceClient).PutData(context.Background(),
// 	(MessageStore.TKey)(i), &MessageStore.TMessageInfo{(MessageStore.TKey)(i),"tin nhắ thứ  "+strconv.Itoa(i),"người gửi "+strconv.Itoa(i),1,1562000000,1 });//Todo: fill structure here
// 	fmt.Println(re,err);
// }

//res2,_:=aClient.Client.(*MessageStore.TMessageStoreServiceClient).GetListMessages( context.Background(),x)
//fmt.Println("get after getlist :", res2)
for i:=1;i<=10;i++{
	x[i-1]=(MessageStore.TKey)(i)
	aClient.Client.(*MessageStore.TMessageStoreServiceClient).PutData(context.Background(),
	(MessageStore.TKey)(i), &MessageStore.TMessageInfo{(MessageStore.TKey)(i),"tin nhắ thứ  "+strconv.Itoa(i),"người gửi "+strconv.Itoa(i),1,1562000000,1 });//Todo: fill structure here
	res, _ = aClient.Client.(*MessageStore.TMessageStoreServiceClient).GetData(context.Background(), (MessageStore.TKey)(i) )
	 fmt.Println("get after put :", res)
	//fmt.Println("get after put :", res.GetData)
}	
// 
	fmt.Println(x)
	// res2, _ := aClient.Client.(*MessageStore.TMessageStoreServiceClient).RemoveData( context.Background(),(MessageStore.TKey)(10) )
	//var k MessageStore.TKey
	//k=(MessageStore.TKey)(1)
	res3, _:= aClient.Client.(*MessageStore.TMessageStoreServiceClient).GetListMessages(context.Background(), x)

	for i:=1;i<=10;i++{
		//res3, _ := aClient.Client.(*MessageStore.TMessageStoreServiceClient).GetData(context.Background(), (MessageStore.TKey)(i) )
	 fmt.Println("get after getlist :", res3.Listdata[(MessageStore.TKey)(i)])
	}
	//fmt.Println("get after remove :", res.GetDataontent)

}