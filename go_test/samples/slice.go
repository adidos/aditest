package main

import "fmt"

func main(){
	var arry [5]int = [5]int{445, 23,453,23,56}
	sli := arry[:3]
	for i, v := range arry{
		fmt.Printf("%d\t%d", i, v)
		fmt.Println()
	}
	fmt.Println();
	for i, v := range sli{
		fmt.Printf("%d\t%d", i, v)
		fmt.Println();
	}
	fmt.Println();
	sli1 := make([]int, 5)
	sli1[0] = 1
	sli1[1] = 2
	sli1 = append(sli1, 1,2,3,4,5)
	for i, v := range sli1{
		fmt.Printf("%d\t%d", i, v)
		fmt.Println();
	}
	fmt.Println();
	
	sli2 := make([]int, 5, 10)
	sli2 = append(sli2, 1,2,3)
	for i, v := range sli2{
		fmt.Printf("%d\t%d", i, v)
		fmt.Println();
	}
	fmt.Println();
	
	sli2 = append(sli2, sli...)
	for i, v := range sli2{
		fmt.Printf("%d\t%d", i, v)
		fmt.Println();
	}
	fmt.Println(len(sli2), cap(sli2));
}