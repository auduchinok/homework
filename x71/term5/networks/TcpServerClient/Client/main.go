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

	flag.StringVar(&address, "a", DEFAULT_ADDRESS, "set server address")
	flag.StringVar(&message, "m", "", "message to send")
	flag.IntVar(&port, "p", DEFAULT_PORT, "set listening port")
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

	greeting, _ := bufio.NewReader(conn).ReadString('\n')
	fmt.Print(greeting)

	scanner := bufio.NewScanner(os.Stdin)
	for scanner.Scan() {
		fmt.Fprint(conn, scanner.Text() + "\n")
	}
}
