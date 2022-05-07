using System;

class AhnmikaWhite
{
    static void Main()
    {
        var rnd = new Random();
        var flag = true;
        UInt64 count = 0;

        Console.CancelKeyPress += (object sender, ConsoleCancelEventArgs e) => {flag = false; e.Cancel = true;};
        
        while (flag)
        {
            var colors = rnd.Next(100, 1001);
            Console.WriteLine("白って{0}色あんねん", colors);
            count++;
        }
        Console.WriteLine("{0} 人のアンミカ", count);
    }
}
