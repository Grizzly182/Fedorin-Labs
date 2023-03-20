using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOPTraining.Strategy
{
    public class LogProcessor
    {
        public void ProcessLogs(Func<string> func)
        {
            Console.WriteLine(func.Invoke());
        }
    }
}