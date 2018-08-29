package main

import (
	"math2"
	"fmt"
	"net"
)

func handleConnection(conn net.Conn)  {
	defer conn.Close()
	for {
		data := make([]byte, 1024)
		n, err := conn.Read(data)
		if n == 0 || err != nil {
			break
		}
		fmt.Printf("Read len: %d,  data: %s", n, data)
		conn.Write(data)
	}
}

func main() {
	b := math2.Sum(2,3)
	fmt.Println("Hello,world!, b:", b)
	ln, err := net.Listen("tcp",  "localhost:8081")
	if err != nil {
		panic(err)
	}

	for {
		conn, err := ln.Accept()
		if err != nil {
			panic(err)
		}
		go handleConnection(conn)
	}

}