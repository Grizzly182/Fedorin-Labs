using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using OOPTraining.Strategy;

namespace OOPTraining
{
    internal class Program
    {
        private static void Main(string[] args)
        {
            WindowsLogReader windowsLogReader = new WindowsLogReader();
            GameLogReader gameLogReader = new GameLogReader();
            BrowserLogReader browserLogReader = new BrowserLogReader();
            LogProcessor processor = new LogProcessor();
            processor.ProcessLogs(windowsLogReader.ReadLogs);
            processor.ProcessLogs(gameLogReader.ReadLogs);
            processor.ProcessLogs(gameLogReader.ReadLogs);
            Console.ReadKey();
        }
    }
}