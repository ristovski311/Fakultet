using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PJLAB319347
{
    internal class PotencijalnaEksplozija : ApplicationException
    {
        public PotencijalnaEksplozija(string message) : base(message) { }
    }
}
