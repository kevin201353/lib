package math2

import (
	"fmt"
	"log"
	 "encoding/xml"
	 "io/ioutil"
	 "encoding/json"
)

type MsgInfo struct{
	Type  int    `xml:"Type"`
	SubType  int  `xml:"Subtype"`
	Data string  `xml:"Data"`
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
	v := MsgInfo{Type: 6, SubType:0}
	err0 := xml.Unmarshal(context, &v)
	if err0 != nil {
		log.Fatal(err0)
	}
	fmt.Printf("MsgType: %d, SubType: %d, Buf: %s\n", v.Type, v.SubType, v.Data)
	
	bytes, err := json.Marshal(v)
	if err != nil {
		log.Fatal(err)
	}
	fmt.Printf("MsgType: %s\n", bytes) 

	return bytes
}
