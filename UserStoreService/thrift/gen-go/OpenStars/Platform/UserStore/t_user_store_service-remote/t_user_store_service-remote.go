// Autogenerated by Thrift Compiler (0.11.0)
// DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING

package main

import (
        "context"
        "flag"
        "fmt"
        "math"
        "net"
        "net/url"
        "os"
        "strconv"
        "strings"
        "git.apache.org/thrift.git/lib/go/thrift"
        "OpenStars/Platform/UserStore"
)


func Usage() {
  fmt.Fprintln(os.Stderr, "Usage of ", os.Args[0], " [-h host:port] [-u url] [-f[ramed]] function [arg1 [arg2...]]:")
  flag.PrintDefaults()
  fmt.Fprintln(os.Stderr, "\nFunctions:")
  fmt.Fprintln(os.Stderr, "  TDataResult getData(TKey key)")
  fmt.Fprintln(os.Stderr, "  TListDataUsers getListUsers( keys)")
  fmt.Fprintln(os.Stderr, "  TErrorCode hasUser(string username,  keys)")
  fmt.Fprintln(os.Stderr, "  TKey getIDByPublicKey(string publickey, i64 lastkey)")
  fmt.Fprintln(os.Stderr, "  TErrorCode putData(TKey key, TUserInfo data)")
  fmt.Fprintln(os.Stderr, "  TErrorCode addConversation(TKey uid, i64 cid)")
  fmt.Fprintln(os.Stderr, "  TErrorCode deleteConversation(TKey uid, i64 cid)")
  fmt.Fprintln(os.Stderr, "  TErrorCode deleteUser(TKey uid)")
  fmt.Fprintln(os.Stderr)
  os.Exit(0)
}

func main() {
  flag.Usage = Usage
  var host string
  var port int
  var protocol string
  var urlString string
  var framed bool
  var useHttp bool
  var parsedUrl *url.URL
  var trans thrift.TTransport
  _ = strconv.Atoi
  _ = math.Abs
  flag.Usage = Usage
  flag.StringVar(&host, "h", "localhost", "Specify host and port")
  flag.IntVar(&port, "p", 9090, "Specify port")
  flag.StringVar(&protocol, "P", "binary", "Specify the protocol (binary, compact, simplejson, json)")
  flag.StringVar(&urlString, "u", "", "Specify the url")
  flag.BoolVar(&framed, "framed", false, "Use framed transport")
  flag.BoolVar(&useHttp, "http", false, "Use http")
  flag.Parse()
  
  if len(urlString) > 0 {
    var err error
    parsedUrl, err = url.Parse(urlString)
    if err != nil {
      fmt.Fprintln(os.Stderr, "Error parsing URL: ", err)
      flag.Usage()
    }
    host = parsedUrl.Host
    useHttp = len(parsedUrl.Scheme) <= 0 || parsedUrl.Scheme == "http"
  } else if useHttp {
    _, err := url.Parse(fmt.Sprint("http://", host, ":", port))
    if err != nil {
      fmt.Fprintln(os.Stderr, "Error parsing URL: ", err)
      flag.Usage()
    }
  }
  
  cmd := flag.Arg(0)
  var err error
  if useHttp {
    trans, err = thrift.NewTHttpClient(parsedUrl.String())
  } else {
    portStr := fmt.Sprint(port)
    if strings.Contains(host, ":") {
           host, portStr, err = net.SplitHostPort(host)
           if err != nil {
                   fmt.Fprintln(os.Stderr, "error with host:", err)
                   os.Exit(1)
           }
    }
    trans, err = thrift.NewTSocket(net.JoinHostPort(host, portStr))
    if err != nil {
      fmt.Fprintln(os.Stderr, "error resolving address:", err)
      os.Exit(1)
    }
    if framed {
      trans = thrift.NewTFramedTransport(trans)
    }
  }
  if err != nil {
    fmt.Fprintln(os.Stderr, "Error creating transport", err)
    os.Exit(1)
  }
  defer trans.Close()
  var protocolFactory thrift.TProtocolFactory
  switch protocol {
  case "compact":
    protocolFactory = thrift.NewTCompactProtocolFactory()
    break
  case "simplejson":
    protocolFactory = thrift.NewTSimpleJSONProtocolFactory()
    break
  case "json":
    protocolFactory = thrift.NewTJSONProtocolFactory()
    break
  case "binary", "":
    protocolFactory = thrift.NewTBinaryProtocolFactoryDefault()
    break
  default:
    fmt.Fprintln(os.Stderr, "Invalid protocol specified: ", protocol)
    Usage()
    os.Exit(1)
  }
  iprot := protocolFactory.GetProtocol(trans)
  oprot := protocolFactory.GetProtocol(trans)
  client := UserStore.NewTUserStoreServiceClient(thrift.NewTStandardClient(iprot, oprot))
  if err := trans.Open(); err != nil {
    fmt.Fprintln(os.Stderr, "Error opening socket to ", host, ":", port, " ", err)
    os.Exit(1)
  }
  
  switch cmd {
  case "getData":
    if flag.NArg() - 1 != 1 {
      fmt.Fprintln(os.Stderr, "GetData requires 1 args")
      flag.Usage()
    }
    argvalue0, err58 := (strconv.ParseInt(flag.Arg(1), 10, 64))
    if err58 != nil {
      Usage()
      return
    }
    value0 := UserStore.TKey(argvalue0)
    fmt.Print(client.GetData(context.Background(), value0))
    fmt.Print("\n")
    break
  case "getListUsers":
    if flag.NArg() - 1 != 1 {
      fmt.Fprintln(os.Stderr, "GetListUsers requires 1 args")
      flag.Usage()
    }
    arg59 := flag.Arg(1)
    mbTrans60 := thrift.NewTMemoryBufferLen(len(arg59))
    defer mbTrans60.Close()
    _, err61 := mbTrans60.WriteString(arg59)
    if err61 != nil { 
      Usage()
      return
    }
    factory62 := thrift.NewTSimpleJSONProtocolFactory()
    jsProt63 := factory62.GetProtocol(mbTrans60)
    containerStruct0 := UserStore.NewTUserStoreServiceGetListUsersArgs()
    err64 := containerStruct0.ReadField1(jsProt63)
    if err64 != nil {
      Usage()
      return
    }
    argvalue0 := containerStruct0.Keys
    value0 := argvalue0
    fmt.Print(client.GetListUsers(context.Background(), value0))
    fmt.Print("\n")
    break
  case "hasUser":
    if flag.NArg() - 1 != 2 {
      fmt.Fprintln(os.Stderr, "HasUser requires 2 args")
      flag.Usage()
    }
    argvalue0 := flag.Arg(1)
    value0 := argvalue0
    arg66 := flag.Arg(2)
    mbTrans67 := thrift.NewTMemoryBufferLen(len(arg66))
    defer mbTrans67.Close()
    _, err68 := mbTrans67.WriteString(arg66)
    if err68 != nil { 
      Usage()
      return
    }
    factory69 := thrift.NewTSimpleJSONProtocolFactory()
    jsProt70 := factory69.GetProtocol(mbTrans67)
    containerStruct1 := UserStore.NewTUserStoreServiceHasUserArgs()
    err71 := containerStruct1.ReadField2(jsProt70)
    if err71 != nil {
      Usage()
      return
    }
    argvalue1 := containerStruct1.Keys
    value1 := argvalue1
    fmt.Print(client.HasUser(context.Background(), value0, value1))
    fmt.Print("\n")
    break
  case "getIDByPublicKey":
    if flag.NArg() - 1 != 2 {
      fmt.Fprintln(os.Stderr, "GetIDByPublicKey requires 2 args")
      flag.Usage()
    }
    argvalue0 := flag.Arg(1)
    value0 := argvalue0
    argvalue1, err73 := (strconv.ParseInt(flag.Arg(2), 10, 64))
    if err73 != nil {
      Usage()
      return
    }
    value1 := argvalue1
    fmt.Print(client.GetIDByPublicKey(context.Background(), value0, value1))
    fmt.Print("\n")
    break
  case "putData":
    if flag.NArg() - 1 != 2 {
      fmt.Fprintln(os.Stderr, "PutData requires 2 args")
      flag.Usage()
    }
    argvalue0, err74 := (strconv.ParseInt(flag.Arg(1), 10, 64))
    if err74 != nil {
      Usage()
      return
    }
    value0 := UserStore.TKey(argvalue0)
    arg75 := flag.Arg(2)
    mbTrans76 := thrift.NewTMemoryBufferLen(len(arg75))
    defer mbTrans76.Close()
    _, err77 := mbTrans76.WriteString(arg75)
    if err77 != nil {
      Usage()
      return
    }
    factory78 := thrift.NewTSimpleJSONProtocolFactory()
    jsProt79 := factory78.GetProtocol(mbTrans76)
    argvalue1 := UserStore.NewTUserInfo()
    err80 := argvalue1.Read(jsProt79)
    if err80 != nil {
      Usage()
      return
    }
    value1 := argvalue1
    fmt.Print(client.PutData(context.Background(), value0, value1))
    fmt.Print("\n")
    break
  case "addConversation":
    if flag.NArg() - 1 != 2 {
      fmt.Fprintln(os.Stderr, "AddConversation requires 2 args")
      flag.Usage()
    }
    argvalue0, err81 := (strconv.ParseInt(flag.Arg(1), 10, 64))
    if err81 != nil {
      Usage()
      return
    }
    value0 := UserStore.TKey(argvalue0)
    argvalue1, err82 := (strconv.ParseInt(flag.Arg(2), 10, 64))
    if err82 != nil {
      Usage()
      return
    }
    value1 := argvalue1
    fmt.Print(client.AddConversation(context.Background(), value0, value1))
    fmt.Print("\n")
    break
  case "deleteConversation":
    if flag.NArg() - 1 != 2 {
      fmt.Fprintln(os.Stderr, "DeleteConversation requires 2 args")
      flag.Usage()
    }
    argvalue0, err83 := (strconv.ParseInt(flag.Arg(1), 10, 64))
    if err83 != nil {
      Usage()
      return
    }
    value0 := UserStore.TKey(argvalue0)
    argvalue1, err84 := (strconv.ParseInt(flag.Arg(2), 10, 64))
    if err84 != nil {
      Usage()
      return
    }
    value1 := argvalue1
    fmt.Print(client.DeleteConversation(context.Background(), value0, value1))
    fmt.Print("\n")
    break
  case "deleteUser":
    if flag.NArg() - 1 != 1 {
      fmt.Fprintln(os.Stderr, "DeleteUser requires 1 args")
      flag.Usage()
    }
    argvalue0, err85 := (strconv.ParseInt(flag.Arg(1), 10, 64))
    if err85 != nil {
      Usage()
      return
    }
    value0 := UserStore.TKey(argvalue0)
    fmt.Print(client.DeleteUser(context.Background(), value0))
    fmt.Print("\n")
    break
  case "":
    Usage()
    break
  default:
    fmt.Fprintln(os.Stderr, "Invalid function ", cmd)
  }
}