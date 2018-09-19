package main

import (
	"context"
	"fmt"

	"../../thrift/gen-go/OpenStars/Platform/ListMemberService" //Todo: Fix this
	"../transports"                                            //Todo: Fix this
)

func main() {
	aClient := transports.GetTListMemberServiceCompactClient("127.0.0.1", "8853") //Todo: Check port and protocol
	defer aClient.BackToPool()
	fmt.Println("Client: ", aClient)

	res, _ := aClient.Client.(*ListMemberService.TListMemberServiceClient).GetData(context.Background(), (ListMemberService.TKey)(10))
	fmt.Println("get result: ", res)

	//aClient.Client.(*ListMemberService.TListMemberServiceClient).PutData(context.Background(),
	//	(ListMemberService.TKey)(10), &ListMemberService.TValue{(ListMemberService.TKey)(10), []int64{98, 93, 77, 82, 83}}) //Todo: fill structure here
	res3, _ := aClient.Client.(*ListMemberService.TListMemberServiceClient).AddMember(context.Background(),
		(ListMemberService.TKey)(10), 10) //Todo: fill structure here
	fmt.Println("res3 :", res3)
	res, _ = aClient.Client.(*ListMemberService.TListMemberServiceClient).GetData(context.Background(), (ListMemberService.TKey)(10))
	fmt.Println("get after put :", res)
	res4, _ := aClient.Client.(*ListMemberService.TListMemberServiceClient).RemoveMember(context.Background(),
		(ListMemberService.TKey)(10), 83) //Todo: fill structure here
	fmt.Println("res4 :", res4)
	res, _ = aClient.Client.(*ListMemberService.TListMemberServiceClient).GetData(context.Background(), (ListMemberService.TKey)(10))
	fmt.Println("get after put :", res)

}
