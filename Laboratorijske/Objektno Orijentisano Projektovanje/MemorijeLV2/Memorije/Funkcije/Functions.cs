using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Funkcije
{
    public class Functions
    {
        public static string ConvertToTimerFormat(int num)
        {
            int hours = num / 3600;
            int minutes = (num % 3600) / 60;
            int seconds = num % 60;

            string res = $"{hours} : {minutes} : {seconds}";
            return res;
        }
    }
}
