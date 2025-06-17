using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace PAAL1
{
    public static class Testing
    {
        public static void Test(string pattern, string Text)
        {
            Stopwatch stopwatch1 = new Stopwatch();
            stopwatch1.Start();
            KMP.KMPSearch(pattern, Text);
            stopwatch1.Stop();
            Console.WriteLine($"\n\n>> [KMPS] Bilo je potrebno {stopwatch1.Elapsed.TotalMilliseconds} ms za izvrsenje. <<\n\n");
        }
    }
}
