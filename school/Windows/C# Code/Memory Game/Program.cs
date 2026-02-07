using System;
using System.Windows.Forms;
using cs04_memoryRedo;

namespace cs04_memoryRedo
{
    static class Program
    {
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}