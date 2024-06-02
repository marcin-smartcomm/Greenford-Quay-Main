using Crestron.SimplSharp;
using System.Timers;

namespace Greenford_Quay_Main
{
    public class MemoryMonitor
    {
        public MemoryMonitor()
        {
            var timer = new Timer();
            timer.Interval = 600000;
            timer.Elapsed += SaveMemoryUsage;
            timer.Start();
        }

        void SaveMemoryUsage(object sender, ElapsedEventArgs e)
        {
            string response = "";
            if (CrestronConsole.SendControlSystemCommand("taskstat -find:SSP", ref response))
            {
                ConsoleLogger.WriteLine(response);
                FileOperations.RecordMemoryUsage(response);
            }
            else
            {
                ConsoleLogger.WriteLine("taskstat command not sent");
            }
        }
    }
}
