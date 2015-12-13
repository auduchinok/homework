package main
import (
	"net"
	"fmt"
	"flag"
	"strconv"
	"bufio"
	"os"
)

const DEFAULT_ADDRESS = "localhost"
const DEFAULT_PORT = 1024

var full_address string
var message string

func init() {
	var address string
	var port int

	flag.StringVar(&address, "address", DEFAULT_ADDRESS, "set server address")
	flag.StringVar(&message, "message", "", "message to send")
	flag.IntVar(&port, "port", DEFAULT_PORT, "set listening port")
	flag.Parse()

	full_address = address + ":" + strconv.Itoa(port)
}

func main() {
	conn, err := net.Dial("tcp", full_address)
	if err != nil {
		panic("Client: cannot connect to server " + full_address)
	}

	if message != "" {
		fmt.Fprint(conn, message)
		return
	}

	fmt.Println("Client: type message to send and press Return")
	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		fmt.Fprint(conn, scanner.Text() + "\n")
	}
}