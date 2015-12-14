package main

import (
	"net"
	"strconv"
	"bufio"
	"fmt"
	"flag"
)

const DEFAULT_PORT = 1024
var port int

func init() {
	flag.IntVar(&port, "p", DEFAULT_PORT, "Set listening port.")
	flag.Parse()
}

func handleConnection(conn net.Conn) {
	scanner := bufio.NewScanner(conn)
	for scanner.Scan() {
		fmt.Println(scanner.Text())
	}
	if err := scanner.Err(); err != nil {
		panic("Server: reading input error: " + err.Error())
	}
}

func main() {
	ln, err := net.Listen("tcp", ":" + strconv.Itoa(port))
	if err != nil {
		panic("Server: cannot start listening: " + err.Error())
	}
	fmt.Printf("Server: started listening at %d\n", port)
	for {
		conn, err := ln.Accept()
		if err != nil {
			panic("Server: cannot establish connection: " + err.Error())
		}
		go handleConnection(conn)
	}
}
