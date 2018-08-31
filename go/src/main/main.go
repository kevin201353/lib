package main

import (
	//"log"
	"math2"
	"fmt"
	"net"
	"bufio"
	"os"
)
//处理用户控制台输入
var (
	input string
	bChan chan bool
	inputReader *bufio.Reader
	err  error
)

func HandleInput(){
	/*
	tcpAddr, err := net.ResolveTCPAddr("tcp4", ":8081")
	conn, err := net.DialTCP("tcp", nil, tcpAddr)
	defer conn.Close()
	*/
	inputReader = bufio.NewReader(os.Stdin)
	for {
		fmt.Println("Please enter some input: ")
		input, err = inputReader.ReadString('\n')
		if err == nil {
			fmt.Printf("The input was:%s\n", input)
			//conn.Write([]byte(input))
			bChan <- true
		}
	}
}

func handleRead(conn net.Conn) {
	for {
		data := make([]byte, 1024)
		n, err := conn.Read(data)
		if n == 0 || err != nil {
			fmt.Printf("rev client data == 0, error: %s.\n", err.Error())
			conn.Close()
			bChan <- true
			break
		}
		fmt.Printf("Read len: %d,  data: %s\n", n, data)
	}
}

func handleConnection(conn net.Conn)  {
	for {
		<- bChan
		bytes := math2.ParseMsgInfoXml()
		fmt.Printf("xml return data: %s\n", bytes)
		n, err := conn.Write(bytes)
		if n == 0 && err != nil {
			conn.Close()
			break
		}
	}
}


func main() {
	b := math2.Sum(2,3)
	fmt.Println("Hello,world!, b:", b)
	bChan = make(chan bool)
	ln, err := net.Listen("tcp",  "localhost:8081")
	if err != nil {
		panic(err)
	}
	defer ln.Close()
	go HandleInput()
	for {
		conn, err := ln.Accept()
		if err != nil {
			panic(err)
		}
		defer conn.Close()
		go handleRead(conn)
		go handleConnection(conn)
	}
}