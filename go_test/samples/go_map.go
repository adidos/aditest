package main

import "fmt"

func main(){
	var arry map[int] string
	arry = make(map[int] string)
	arry[1] = "bac"
	arry[2] = "bacdfd"
	arry[3] = "bacdfs"
	
	for k, v := range arry{
		fmt.Printf("key = %d\t value = %s\n", k, v)
	}
	
	value, bExist := arry[1]
	if bExist {
		fmt.Printf("%s\n", value)
	}
	
	value, bExist = arry[5]
	if !bExist{
		fmt.Printf("key 5 is not exist!\n")
	}
	
	delete(arry, 1)
	for k, v := range arry{
		fmt.Printf("key = %d\t value = %s\n", k, v)
	}
}