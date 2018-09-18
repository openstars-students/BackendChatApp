package main

//Server C++ can get at github.com/openstars/binary/bigset

import (
//	"thriftpool"
	bs "i64toi64setservice"
	"git.apache.org/thrift.git/lib/go/thrift"
	"time"
	"fmt"
	"thriftpool"
	typee "i64toi64set_shared"
	//"strconv"
)

//type ThriftCreator func(ip, port string, connTimeout time.Duration, forPool* ThriftPool) (*ThriftSocketClient, error)

//type ThriftClientClose func(c *ThriftSocketClient) error

func i64toi64ClientCreator(host, port string, connTimeout time.Duration, forPool* thriftpool.ThriftPool) (*thriftpool.ThriftSocketClient, error){
	socket, err := thrift.NewTSocketTimeout(fmt.Sprintf("%s:%s", host, port), connTimeout)
	if err != nil {
		return nil, err
	}
	transportFactory := thrift.NewTFramedTransportFactory(thrift.NewTTransportFactory())
	protocolFactory := thrift.NewTCompactProtocolFactory()
	client := bs.NewTI64ToI64SetServiceClientFactory(transportFactory.GetTransport(socket), protocolFactory)

	err = client.Transport.Open()
	if err != nil {
		return nil, err
	}

	return &thriftpool.ThriftSocketClient{
		Client: client,
		Socket: socket,
		Parent: forPool,
	}, nil
}

func Close(c *thriftpool.ThriftSocketClient) error {
	err := c.Socket.Close()
	//err = c.Client.(*tutorial.PlusServiceClient).Transport.Close()
	return err
}

//GlobalRpcPool = thriftPool.NewThriftPool("10.5.20.3", "23455", 100, 32, 600, Dial, Close)

var (mp=thriftpool.NewMapPool(100, 3600, 3600, i64toi64ClientCreator, Close))

func testPoolWrite(num int){
	client, _ := mp.Get("127.0.0.1", "8883").Get()
	if (client == nil ) {
		
		return
	}
	va:=num*num
	defer client.BackToPool();
	fmt.Println(num,va)
	res,err:=client.Client.(*bs.TI64ToI64SetServiceClient).AddItem( typee.TKey(num) , typee.TItem(num)  )
	fmt.Println(res,err)
	fmt.Println(mp.Get("127.0.0.1", "8883").GetConnCount(), mp.Get("127.0.0.1", "8883").GetIdleCount() )
}

func testPoolRead(num int){
	client, _ := mp.Get("127.0.0.1", "8883").Get()
	if (client == nil ){
		fmt.Println("k ket noi duoc server");
		return;
	}

	defer client.BackToPool();
	//client.Client.(*bs.TStringBigSetKVServiceClient).BsPutItem("testBigSet", &bs.TItem{[]byte("key_" + strconv.Itoa(num)), []byte("Value_"+ strconv.Itoa(num))  } )
	//res, _:=client.Client.(*bs.TStringBigSetKVServiceClient).BsGetItem("myBigSet", []byte("Hello"))
	//fmt.Println((string)(res.Item.Value[:]) )
	res, err:=client.Client.(*bs.TI64ToI64SetServiceClient).GetValue(  typee.TKey(num))
	if (res !=nil) {
		fmt.Println(num,res.Items[:])
	}else {
		fmt.Println("khong co du lieu, loi",err);
	}
}

func main(){
	mp:=thriftpool.NewMapPool(100, 3600, 3600, i64toi64ClientCreator, Close)
	client, _ := mp.Get("127.0.0.1", "888").Get()
	if (client == nil ){
		fmt.Println("k ket noi duoc server");
		return;
	}

	var x typee.TItem
	var  a typee.TKey
	x=100
	a= 100
	
	defer client.BackToPool();
	re,err1:=client.Client.(*bs.TI64ToI64SetServiceClient).AddItem(a , x )
	fmt.Println(re,err1);
	//time.Sleep(time.Second * 10)
	res, err:=client.Client.(*bs.TI64ToI64SetServiceClient).GetValue(a)
	if (res !=nil) {
		fmt.Println(res.Items[:])
	}else {
		fmt.Println("khong co du lieu, loi",err);
	}
	// for i:=0; i<10; i++ {
	// 	go testPoolWrite(i);
	// 	time.Sleep(time.Second * 1)
	// 	//go testPoolRead(i);
	// }
	// // i:=50
	// // go testPoolWrite(i);
	// // time.Sleep(time.Second * 1)
	// // go testPoolRead(i);
	// time.Sleep(2000);
	// time.Sleep(time.Second * 1)
	// //push client back to pool
	// for i:=40; i<50; i++ {
	// 	//go testPoolRead(i);
	// }
	// time.Sleep(time.Second * 5)

}
