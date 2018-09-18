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
        "OpenStars/Platform/UserConversationService"
)


func Usage() {
  fmt.Fprintln(os.Stderr, "Usage of ", os.Args[0], " [-h host:port] [-u url] [-f[ramed]] function [arg1 [arg2...]]:")
  flag.PrintDefaults()
  fmt.Fprintln(os.Stderr, "\nFunctions:")
  fmt.Fprintln(os.Stderr, "  TDataResult getData(TKey key)")
  fmt.Fprintln(os.Stderr, "  TErrorCode putData(TKey key, TValue data)")
  fmt.Fprintln(os.Stderr, "  TErrorCode addConversation(TKey key, i64 cid)")
  fmt.Fprintln(os.Stderr, "  TErrorCode removeConversation(TKey key, i64 cid)")
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
  client := UserConversationService.NewTDataServiceClient(thrift.NewTStandardClient(iprot, oprot))
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
    argvalue0, err16 := (strconv.ParseInt(flag.Arg(1), 10, 64))
    if err16 != nil {
      Usage()
      return
    }
    value0 := UserConversationService.TKey(argvalue0)
    fmt.Print(client.GetData(context.Background(), value0))
    fmt.Print("\n")
    break
  case "putData":
    if flag.NArg() - 1 != 2 {
      fmt.Fprintln(os.Stderr, "PutData requires 2 args")
      flag.Usage()
    }
    argvalue0, err17 := (strconv.ParseInt(flag.Arg(1), 10, 64))
    if err17 != nil {
      Usage()
      return
    }
    value0 := UserConversationService.TKey(argvalue0)
    arg18 := flag.Arg(2)
    mbTrans19 := thrift.NewTMemoryBufferLen(len(arg18))
    defer mbTrans19.Close()
    _, err20 := mbTrans19.WriteString(arg18)
    if err20 != nil {
      Usage()
      return
    }
    factory21 := thrift.NewTSimpleJSONProtocolFactory()
    jsProt22 := factory21.GetProtocol(mbTrans19)
    argvalue1 := UserConversationService.NewTValue()
    err23 := argvalue1.Read(jsProt22)
    if err23 != nil {
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
    argvalue0, err24 := (strconv.ParseInt(flag.Arg(1), 10, 64))
    if err24 != nil {
      Usage()
      return
    }
    value0 := UserConversationService.TKey(argvalue0)
    argvalue1, err25 := (strconv.ParseInt(flag.Arg(2), 10, 64))
    if err25 != nil {
      Usage()
      return
    }
    value1 := argvalue1
    fmt.Print(client.AddConversation(context.Background(), value0, value1))
    fmt.Print("\n")
    break
  case "removeConversation":
    if flag.NArg() - 1 != 2 {
      fmt.Fprintln(os.Stderr, "RemoveConversation requires 2 args")
      flag.Usage()
    }
    argvalue0, err26 := (strconv.ParseInt(flag.Arg(1), 10, 64))
    if err26 != nil {
      Usage()
      return
    }
    value0 := UserConversationService.TKey(argvalue0)
    argvalue1, err27 := (strconv.ParseInt(flag.Arg(2), 10, 64))
    if err27 != nil {
      Usage()
      return
    }
    value1 := argvalue1
    fmt.Print(client.RemoveConversation(context.Background(), value0, value1))
    fmt.Print("\n")
    break
  case "":
    Usage()
    break
  default:
    fmt.Fprintln(os.Stderr, "Invalid function ", cmd)
  }
}
