using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VezbanjeC_PJ
{
    public class PogresanRaspored : Exception
    {
        public PogresanRaspored(string msg) : base(msg)
        {

        }

        public PogresanRaspored(): base("Pogresan raspored!")
        { }
    }
}
