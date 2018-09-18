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
  client := UserStore.NewTDataServiceClient(thrift.NewTStandardClient(iprot, oprot))
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
    argvalue0, err29 := (strconv.ParseInt(flag.Arg(1), 10, 64))
    if err29 != nil {
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
    arg30 := flag.Arg(1)
    mbTrans31 := thrift.NewTMemoryBufferLen(len(arg30))
    defer mbTrans31.Close()
    _, err32 := mbTrans31.WriteString(arg30)
    if err32 != nil { 
      Usage()
      return
    }
    factory33 := thrift.NewTSimpleJSONProtocolFactory()
    jsProt34 := factory33.GetProtocol(mbTrans31)
    containerStruct0 := UserStore.NewTDataServiceGetListUsersArgs()
    err35 := containerStruct0.ReadField1(jsProt34)
    if err35 != nil {
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
    arg37 := flag.Arg(2)
    mbTrans38 := thrift.NewTMemoryBufferLen(len(arg37))
    defer mbTrans38.Close()
    _, err39 := mbTrans38.WriteString(arg37)
    if err39 != nil { 
      Usage()
      return
    }
    factory40 := thrift.NewTSimpleJSONProtocolFactory()
    jsProt41 := factory40.GetProtocol(mbTrans38)
    containerStruct1 := UserStore.NewTDataServiceHasUserArgs()
    err42 := containerStruct1.ReadField2(jsProt41)
    if err42 != nil {
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
    argvalue1, err44 := (strconv.ParseInt(flag.Arg(2), 10, 64))
    if err44 != nil {
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
    argvalue0, err45 := (strconv.ParseInt(flag.Arg(1), 10, 64))
    if err45 != nil {
      Usage()
      return
    }
    value0 := UserStore.TKey(argvalue0)
    arg46 := flag.Arg(2)
    mbTrans47 := thrift.NewTMemoryBufferLen(len(arg46))
    defer mbTrans47.Close()
    _, err48 := mbTrans47.WriteString(arg46)
    if err48 != nil {
      Usage()
      return
    }
    factory49 := thrift.NewTSimpleJSONProtocolFactory()
    jsProt50 := factory49.GetProtocol(mbTrans47)
    argvalue1 := UserStore.NewTUserInfo()
    err51 := argvalue1.Read(jsProt50)
    if err51 != nil {
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
    argvalue0, err52 := (strconv.ParseInt(flag.Arg(1), 10, 64))
    if err52 != nil {
      Usage()
      return
    }
    value0 := UserStore.TKey(argvalue0)
    argvalue1, err53 := (strconv.ParseInt(flag.Arg(2), 10, 64))
    if err53 != nil {
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
    argvalue0, err54 := (strconv.ParseInt(flag.Arg(1), 10, 64))
    if err54 != nil {
      Usage()
      return
    }
    value0 := UserStore.TKey(argvalue0)
    argvalue1, err55 := (strconv.ParseInt(flag.Arg(2), 10, 64))
    if err55 != nil {
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
    argvalue0, err56 := (strconv.ParseInt(flag.Arg(1), 10, 64))
    if err56 != nil {
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
