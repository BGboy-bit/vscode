package main

import "fmt"

func Solve() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n+1)
	cnt1 := 0
	cnt2 := 0
	for i := 1; i <= n; i++ {
		fmt.Scan(&a[i])
		if a[i]%2 == 1 {
			cnt1++
		} else {
			cnt2++
		}
	}
	if cnt2 == 0 {
		cnt1 -= 1
	} else {
		cnt1++
	}
	fmt.Println(cnt1)
}

func main() {
	T := 1
	fmt.Scan(&T)
	for T > 0 {
		T--
		Solve()
	}
}
