// Autogenerated by Thrift Compiler (0.9.1)
// DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING

package main

import (
	"flag"
	"fmt"
	"git.apache.org/thrift.git/lib/go/thrift"
	"i64toi64setservice"
	"math"
	"net"
	"net/url"
	"os"
	"strconv"
	"strings"
)

func Usage() {
	fmt.Fprintln(os.Stderr, "Usage of ", os.Args[0], " [-h host:port] [-u url] [-f[ramed]] function [arg1 [arg2...]]:")
	flag.PrintDefaults()
	fmt.Fprintln(os.Stderr, "\nFunctions:")
	fmt.Fprintln(os.Stderr, "  TValue getValue(TKey key)")
	fmt.Fprintln(os.Stderr, "  TValue getValue_random(TKey key, i32 size)")
	fmt.Fprintln(os.Stderr, "  TValue getValue_slice(TKey key, i32 idxFrom, i32 size)")
	fmt.Fprintln(os.Stderr, "   getValueMulti( keys)")
	fmt.Fprintln(os.Stderr, "  bool hasItem(TKey key, TItem item)")
	fmt.Fprintln(os.Stderr, "  i32 getSize(TKey key)")
	fmt.Fprintln(os.Stderr, "   getSizeMulti( keys)")
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
	var parsedUrl url.URL
	var trans thrift.TTransport
	_ = math.MinInt32 // will become unneeded eventually
	_ = strconv.Atoi
	flag.Usage = Usage
	flag.StringVar(&host, "h", "localhost", "Specify host and port")
	flag.IntVar(&port, "p", 9090, "Specify port")
	flag.StringVar(&protocol, "P", "binary", "Specify the protocol (binary, compact, simplejson, json)")
	flag.StringVar(&urlString, "u", "", "Specify the url")
	flag.BoolVar(&framed, "framed", false, "Use framed transport")
	flag.BoolVar(&useHttp, "http", false, "Use http")
	flag.Parse()

	if len(urlString) > 0 {
		parsedUrl, err := url.Parse(urlString)
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
	client := i64toi64setservice.NewTI64ToI64SetServiceRClientFactory(trans, protocolFactory)
	if err := trans.Open(); err != nil {
		fmt.Fprintln(os.Stderr, "Error opening socket to ", host, ":", port, " ", err)
		os.Exit(1)
	}

	switch cmd {
	case "getValue":
		if flag.NArg()-1 != 1 {
			fmt.Fprintln(os.Stderr, "GetValue requires 1 args")
			flag.Usage()
		}
		argvalue0, err36 := (strconv.ParseInt(flag.Arg(1), 10, 64))
		if err36 != nil {
			Usage()
			return
		}
		value0 := i64toi64setservice.TKey(argvalue0)
		fmt.Print(client.GetValue(value0))
		fmt.Print("\n")
		break
	case "getValue_random":
		if flag.NArg()-1 != 2 {
			fmt.Fprintln(os.Stderr, "GetValueRandom requires 2 args")
			flag.Usage()
		}
		argvalue0, err37 := (strconv.ParseInt(flag.Arg(1), 10, 64))
		if err37 != nil {
			Usage()
			return
		}
		value0 := i64toi64setservice.TKey(argvalue0)
		tmp1, err38 := (strconv.Atoi(flag.Arg(2)))
		if err38 != nil {
			Usage()
			return
		}
		argvalue1 := int32(tmp1)
		value1 := argvalue1
		fmt.Print(client.GetValueRandom(value0, value1))
		fmt.Print("\n")
		break
	case "getValue_slice":
		if flag.NArg()-1 != 3 {
			fmt.Fprintln(os.Stderr, "GetValueSlice requires 3 args")
			flag.Usage()
		}
		argvalue0, err39 := (strconv.ParseInt(flag.Arg(1), 10, 64))
		if err39 != nil {
			Usage()
			return
		}
		value0 := i64toi64setservice.TKey(argvalue0)
		tmp1, err40 := (strconv.Atoi(flag.Arg(2)))
		if err40 != nil {
			Usage()
			return
		}
		argvalue1 := int32(tmp1)
		value1 := argvalue1
		tmp2, err41 := (strconv.Atoi(flag.Arg(3)))
		if err41 != nil {
			Usage()
			return
		}
		argvalue2 := int32(tmp2)
		value2 := argvalue2
		fmt.Print(client.GetValueSlice(value0, value1, value2))
		fmt.Print("\n")
		break
	case "getValueMulti":
		if flag.NArg()-1 != 1 {
			fmt.Fprintln(os.Stderr, "GetValueMulti requires 1 args")
			flag.Usage()
		}
		arg42 := flag.Arg(1)
		mbTrans43 := thrift.NewTMemoryBufferLen(len(arg42))
		defer mbTrans43.Close()
		_, err44 := mbTrans43.WriteString(arg42)
		if err44 != nil {
			Usage()
			return
		}
		factory45 := thrift.NewTSimpleJSONProtocolFactory()
		jsProt46 := factory45.GetProtocol(mbTrans43)
		containerStruct0 := i64toi64setservice.NewGetValueMultiArgs()
		err47 := containerStruct0.ReadField1(jsProt46)
		if err47 != nil {
			Usage()
			return
		}
		argvalue0 := containerStruct0.Keys
		value0 := argvalue0
		fmt.Print(client.GetValueMulti(value0))
		fmt.Print("\n")
		break
	case "hasItem":
		if flag.NArg()-1 != 2 {
			fmt.Fprintln(os.Stderr, "HasItem requires 2 args")
			flag.Usage()
		}
		argvalue0, err48 := (strconv.ParseInt(flag.Arg(1), 10, 64))
		if err48 != nil {
			Usage()
			return
		}
		value0 := i64toi64setservice.TKey(argvalue0)
		argvalue1, err49 := (strconv.ParseInt(flag.Arg(2), 10, 64))
		if err49 != nil {
			Usage()
			return
		}
		value1 := i64toi64setservice.TItem(argvalue1)
		fmt.Print(client.HasItem(value0, value1))
		fmt.Print("\n")
		break
	case "getSize":
		if flag.NArg()-1 != 1 {
			fmt.Fprintln(os.Stderr, "GetSize requires 1 args")
			flag.Usage()
		}
		argvalue0, err50 := (strconv.ParseInt(flag.Arg(1), 10, 64))
		if err50 != nil {
			Usage()
			return
		}
		value0 := i64toi64setservice.TKey(argvalue0)
		fmt.Print(client.GetSize(value0))
		fmt.Print("\n")
		break
	case "getSizeMulti":
		if flag.NArg()-1 != 1 {
			fmt.Fprintln(os.Stderr, "GetSizeMulti requires 1 args")
			flag.Usage()
		}
		arg51 := flag.Arg(1)
		mbTrans52 := thrift.NewTMemoryBufferLen(len(arg51))
		defer mbTrans52.Close()
		_, err53 := mbTrans52.WriteString(arg51)
		if err53 != nil {
			Usage()
			return
		}
		factory54 := thrift.NewTSimpleJSONProtocolFactory()
		jsProt55 := factory54.GetProtocol(mbTrans52)
		containerStruct0 := i64toi64setservice.NewGetSizeMultiArgs()
		err56 := containerStruct0.ReadField1(jsProt55)
		if err56 != nil {
			Usage()
			return
		}
		argvalue0 := containerStruct0.Keys
		value0 := argvalue0
		fmt.Print(client.GetSizeMulti(value0))
		fmt.Print("\n")
		break
	case "":
		Usage()
		break
	default:
		fmt.Fprintln(os.Stderr, "Invalid function ", cmd)
	}
}
