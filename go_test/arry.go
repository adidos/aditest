package main

import "fmt"

func main(){
	arry := [6] int32 {1,32,34,22,31,32}
	for _, v := range arry{
		fmt.Printf("%d\t", v)
	}
}
