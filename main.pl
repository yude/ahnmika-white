$flag = 0;
$count = 0;

$SIG{INT} = sub {
    $flag = 1;
};

while ($flag != 1) {
    my $colors = 100 + int(rand(901));
    printf("白って%d色あんねん\n", $colors);
    $count ++;
}
printf("%d 人のアンミカ\n", $count);
