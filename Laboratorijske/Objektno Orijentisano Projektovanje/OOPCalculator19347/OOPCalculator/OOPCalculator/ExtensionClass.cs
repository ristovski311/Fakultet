using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace OOPCalculator
{
    public static class ExtensionClass
    {
        public static string ShowCurrentTime(this DateTime dt)
        {
            return dt.ToString("dd.MM.yyyy. HH:mm:ss.");
        }

        public static string AddCharacterToCalculator(this String str, char c)
        {
            if (str.Length >= 25)
                return str;
            switch (c)
            {
                case '0':
                    {
                        if(str.IsZero())
                        {
                            str = str.Remove(str.Length - 1, 1);
                        }
                        return str + "0";
                    }
                case '1':
                    {
                        if (str.IsZero())
                        {
                            str = str.Remove(str.Length - 1, 1);
                        }
                        return str + "1";
                    }
                case '2':
                    {
                        if (str.IsZero())
                        {
                            str = str.Remove(str.Length - 1, 1);
                        }
                        return str + "2";
                    }
                case '3':
                    {
                        if (str.IsZero())
                        {
                            str = str.Remove(str.Length - 1, 1);
                        }
                        return str + "3";
                    }
                case '4':
                    {
                        if (str.IsZero())
                        {
                            str = str.Remove(str.Length - 1, 1);
                        }
                        return str + "4";
                    }
                case '5':
                    {
                        if (str.IsZero())
                        {
                            str = str.Remove(str.Length - 1, 1);
                        }
                        return str + "5";
                    }
                case '6':
                    {
                        if (str.IsZero())
                        {
                            str = str.Remove(str.Length - 1, 1);
                        }
                        return str + "6";
                    }
                case '7':
                    {
                        if (str.IsZero())
                        {
                            str = str.Remove(str.Length - 1, 1);
                        }
                        return str + "7";
                    }
                case '8':
                    {
                        if (str.IsZero())
                        {
                            str = str.Remove(str.Length - 1, 1);
                        }
                        return str + "8";
                    }
                case '9':
                    {
                        if (str.IsZero())
                        {
                            str = str.Remove(str.Length - 1, 1);
                        }
                        return str + "9";
                    }
                case '+':
                    {
                        if(str.IsLastSign())
                            str = str.Remove(str.Length - 1, 1);
                        return str + "+";
                    }
                case '*':
                    {
                        if (str.IsLastSign())
                            str = str.Remove(str.Length - 1, 1);
                        return str + "*";
                    }
                case '-':
                    {
                        if (str.IsLastSign())
                            str = str.Remove(str.Length - 1, 1);
                        return str + "-";
                    }
                case '/':
                    {
                        if (str.IsLastSign())
                            str = str.Remove(str.Length - 1, 1);
                        return str + "/";
                    }
                case '.':
                    {
                        char[] temp = str.ToCharArray();
                        int i = str.Length - 1;
                        if (temp[i].IsSign())
                            return str;
                        while(i >= 0)
                        {
                            if (temp[i] == '.')
                            {
                                MessageBox.Show("Invalid decimal representation!");
                                return str;
                            }
                            if (temp[i].IsSign())
                            {
                                return str + ".";
                            }
                            i--;
                        }
                        return str + ".";
                    }
                default:
                    return str;
            }
        }
        public static bool IsLastSign(this string str)
        {
            if (str.EndsWith("+") || str.EndsWith("-") || str.EndsWith("/") || str.EndsWith("*"))
            {
                return true;
            }
            return false;
        }

        public static bool IsSign(this char c)
        {
            if (c == '+' || c == '-' || c == '*' || c == '/')
                return true;
            return false;
        }

        public static bool IsZero(this string str)
        {
            if(str == "0" || str.EndsWith("-0") || str.EndsWith("+0") || str.EndsWith("/0")
                || str.EndsWith("*0"))
            {
                return true;
            }
            return false;
        }
    }
}
