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
        "OpenStars/Platform/ContactStore"
)


func Usage() {
  fmt.Fprintln(os.Stderr, "Usage of ", os.Args[0], " [-h host:port] [-u url] [-f[ramed]] function [arg1 [arg2...]]:")
  flag.PrintDefaults()
  fmt.Fprintln(os.Stderr, "\nFunctions:")
  fmt.Fprintln(os.Stderr, "  TDataResult getData(TKey key)")
  fmt.Fprintln(os.Stderr, "  TErrorCode putData(TKey key, TValue data)")
  fmt.Fprintln(os.Stderr, "  TErrorCode addFriend(TKey uid, i64 friendid)")
  fmt.Fprintln(os.Stderr, "  TErrorCode unFriend(TKey uid, i64 friendid)")
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
  client := ContactStore.NewTContactStoreServiceClient(thrift.NewTStandardClient(iprot, oprot))
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
    value0 := ContactStore.TKey(argvalue0)
    fmt.Print(client.GetData(context.Background(), value0))
    fmt.Print("\n")
    break
  case "putData":
    if flag.NArg() - 1 != 2 {
      fmt.Fprintln(os.Stderr, "PutData requires 2 args")
      flag.Usage()
    }
    argvalue0, err30 := (strconv.ParseInt(flag.Arg(1), 10, 64))
    if err30 != nil {
      Usage()
      return
    }
    value0 := ContactStore.TKey(argvalue0)
    arg31 := flag.Arg(2)
    mbTrans32 := thrift.NewTMemoryBufferLen(len(arg31))
    defer mbTrans32.Close()
    _, err33 := mbTrans32.WriteString(arg31)
    if err33 != nil {
      Usage()
      return
    }
    factory34 := thrift.NewTSimpleJSONProtocolFactory()
    jsProt35 := factory34.GetProtocol(mbTrans32)
    argvalue1 := ContactStore.NewTValue()
    err36 := argvalue1.Read(jsProt35)
    if err36 != nil {
      Usage()
      return
    }
    value1 := argvalue1
    fmt.Print(client.PutData(context.Background(), value0, value1))
    fmt.Print("\n")
    break
  case "addFriend":
    if flag.NArg() - 1 != 2 {
      fmt.Fprintln(os.Stderr, "AddFriend requires 2 args")
      flag.Usage()
    }
    argvalue0, err37 := (strconv.ParseInt(flag.Arg(1), 10, 64))
    if err37 != nil {
      Usage()
      return
    }
    value0 := ContactStore.TKey(argvalue0)
    argvalue1, err38 := (strconv.ParseInt(flag.Arg(2), 10, 64))
    if err38 != nil {
      Usage()
      return
    }
    value1 := argvalue1
    fmt.Print(client.AddFriend(context.Background(), value0, value1))
    fmt.Print("\n")
    break
  case "unFriend":
    if flag.NArg() - 1 != 2 {
      fmt.Fprintln(os.Stderr, "UnFriend requires 2 args")
      flag.Usage()
    }
    argvalue0, err39 := (strconv.ParseInt(flag.Arg(1), 10, 64))
    if err39 != nil {
      Usage()
      return
    }
    value0 := ContactStore.TKey(argvalue0)
    argvalue1, err40 := (strconv.ParseInt(flag.Arg(2), 10, 64))
    if err40 != nil {
      Usage()
      return
    }
    value1 := argvalue1
    fmt.Print(client.UnFriend(context.Background(), value0, value1))
    fmt.Print("\n")
    break
  case "":
    Usage()
    break
  default:
    fmt.Fprintln(os.Stderr, "Invalid function ", cmd)
  }
}
