package main

import (
	"context"
	"fmt"
	"math/rand"
	"os"
	"os/signal"
	"sync"
)

func main() {
	count := int64(0)
	ctx, stop := signal.NotifyContext(context.Background(), os.Interrupt)
	defer stop()

	wg := sync.WaitGroup{}
	wg.Add(1)

	go func() {
		defer wg.Done()
		for {
			fmt.Printf("白って%d色あんねん\n", 100+rand.Intn(901))
			count++

			select {
			case <-ctx.Done():
				return
			default:
				// more ahnmika please
			}
		}
	}()

	<-ctx.Done()
	wg.Wait()

	fmt.Printf("%d 人のアンミカ\n", count)
}
