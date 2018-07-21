using System;
using System.Net.Sockets;
using System.Net;
using System.IO;
using System.Text;

namespace Server
{
  class Program
  {
    public static void Main()
    {
      Globals.server.InitServer();

      while(true)
      {
        string input = Console.ReadLine();

        if(input == "e")
        {
          break;
        }
      }
    }
  }
}
