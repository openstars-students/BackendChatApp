package main
import (
	"../../thrift/gen-go/OpenStars/Platform/UserStore" //Todo: Fix this
	"../transports"  //Todo: Fix this
	"fmt"
	"context"
	//"strconv"
)

func main(){
	aClient := transports.GetTUserStoreServiceCompactClient("127.0.0.1", "8803") //Todo: Check port and protocol
	defer aClient.BackToPool();
	fmt.Println("Client: ", aClient);

	res, _ := aClient.Client.(*UserStore.TUserStoreServiceClient).GetData(context.Background(), (UserStore.TKey)(1) )
	fmt.Println("get result: ",res)
	// x := make([]int64, 3)
	// x[0]=1
	// x[1]=2
	// x[2]=3

	  aClient.Client.(*UserStore.TUserStoreServiceClient).PutData(context.Background(),
	  		 (UserStore.TKey)(1), &UserStore.TUserInfo{(UserStore.TKey)(1),"hiepbn","shindo","bachngochieph2@gmail.com","0917099113",nil,nil,1,"qwertyuio"} );//Todo: fill structure here

	 res3, _ := aClient.Client.(*UserStore.TUserStoreServiceClient).AddConversation(context.Background(), (UserStore.TKey)(1),2 )
	 fmt.Println("get result addconversation: ",res3)
	 res, _ = aClient.Client.(*UserStore.TUserStoreServiceClient).GetData(context.Background(), (UserStore.TKey)(1) )
	 fmt.Println("get after add :", res)

// 	//GET LIST
// 	x2 := make([]UserStore.TKey, 10)

// for i:=1;i<=10;i++{
// 	x2[i-1]=(UserStore.TKey)(i)
// 	aClient.Client.(*UserStore.TUserStoreServiceClient).PutData(context.Background(),
// 	(UserStore.TKey)(i), &UserStore.TUserInfo{(UserStore.TKey)(i),"hiepbn"+strconv.Itoa(i),"shindo "+strconv.Itoa(i),"bachngochieph2@gmail.com","0917099113",x,nil,1,nil} );//Todo: fill structure here
// 	//res, _ = aClient.Client.(*UserStore.TUserStoreServiceClient).GetData(context.Background(), (UserStore.TKey)(i) )
// 	 //fmt.Println("get after put :", res)

// }
// 	fmt.Println(x2)
// 	res3, _:= aClient.Client.(*UserStore.TUserStoreServiceClient).GetListUsers(context.Background(), x2)

// 	for i:=1;i<=10;i++{
// 		//res3, _ := aClient.Client.(*UserStore.TUserStoreServiceClient).GetData(context.Background(), (UserStore.TKey)(i) )
// 	 fmt.Println("get after getlist :", res3.Listuser[(UserStore.TKey)(i)].Username)
// 	}
// 	//fmt.Println("get after remove :", res.GetDataontent)
// 	res4, _:= aClient.Client.(*UserStore.TUserStoreServiceClient).HasUser(context.Background(),"hiepbn20", x2)
// 	fmt.Println("hasuser: ", res4)

	// res4, _:= aClient.Client.(*UserStore.TUserStoreServiceClient).GetIDByPublicKey(context.Background(),"qwertyuio",10)
	// fmt.Println("hasuser: ", res4)


}