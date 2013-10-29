package main

import "fmt"

func main(){
	fmt.Println("hello world!")
	defer fmt.Println("go")
	fmt.Println("haha......")
	defer fmt.Println("hello ")
}

