package math2

import (
	"fmt"
	"log"
	 "encoding/xml"
	 "io/ioutil"
)

type MsgInfo struct{
	MsgType  int    `xml:"Type"`
	MsgSubType  int  `xml:"Subtype"`
	Buf []byte  `xml:"Data"`
	Buflen  int
	Arg interface{}
}

func Sum(a int, b int) int {
	return a+b
}

func ParseMsgInfoXml() []byte {
	context, err := ioutil.ReadFile("msg.xml")
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("msg xml data: %s\n", context)
	v := MsgInfo{MsgType: 6, MsgSubType:0}
	err0 := xml.Unmarshal(context, &v)
	if err0 != nil {
		log.Fatal(err0)
	}
	fmt.Printf("MsgType: %d, SubType: %d, Buf: %s\n", v.MsgType, v.MsgSubType, v.Buf)
	bytes, err := xml.Marshal(v)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("MsgType: %s\n", bytes)
	return bytes
}
