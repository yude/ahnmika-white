count = 0

begin
  loop do
    printf("白って%d色あんねん\n", rand(100..1000))
    count += 1
  end
rescue Interrupt
  printf("%d人のアンミカ\n", count)
end
