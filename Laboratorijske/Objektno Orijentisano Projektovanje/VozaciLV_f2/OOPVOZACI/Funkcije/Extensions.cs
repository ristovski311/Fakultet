using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Funkcije
{
    internal static class Extensions
    {
        public static string ShowCurrentTime(this DateTime dt)
        {
            return dt.ToString("dd.MM.yyyy. HH:mm:ss.");
        }
    }
}
