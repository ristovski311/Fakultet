using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VezbanjeC_PJ2
{
    internal class NedovoljnaRaznovrsnost : Exception
    {
        public NedovoljnaRaznovrsnost(string msg) : base(msg) { }
    }
}
