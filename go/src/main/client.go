package main
/*
import (
	"os"
	//"log"
	"fmt"
	"net"
	"bufio"
)

//处理用户控制台输入
var (
	input string
	bChan chan bool
	inputReader *bufio.Reader
	err  error
)

func main2(){
	old := "S"
	tcpAddr, err := net.ResolveTCPAddr("tcp4", ":8081")
	conn, err := net.DialTCP("tcp", nil, tcpAddr)
    defer conn.Close()
	inputReader = bufio.NewReader(os.Stdin)
	for {
		fmt.Println("Please enter some input: ")
		input, err = inputReader.ReadString('\n')
		if err == nil {
			fmt.Printf("The input was:%s\n", input)
			if input == old {
				fmt.Println("input")
				break
			}
			conn.Write([]byte(input))
		}
	}
}*/
