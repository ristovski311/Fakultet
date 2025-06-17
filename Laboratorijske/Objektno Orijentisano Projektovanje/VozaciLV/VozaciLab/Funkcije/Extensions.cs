using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Funkcije
{
    public static class Extensions
    {
        public static string ShowCurrentTime(this DateTime dt)
        {
            return dt.ToString("dd.MM.yyyy. HH:mm:ss.");
        }
    
        public static string Capitalize(this string str)
        {
            if (str == null || str == string.Empty)
                return str;
            char[] temp = str.ToCharArray();
            temp[0] = Char.ToUpper(temp[0]);
            for(int i = 1; i < temp.Length; i++)
            {
                temp[i] = Char.ToLower(temp[i]);
            }
            String res = new String(temp);
            return res;
        }
    }
}
